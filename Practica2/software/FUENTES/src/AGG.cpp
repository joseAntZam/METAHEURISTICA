//lectura de un fichero
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <chrono>
#include <ctime>
#include "random.hpp"
#include "AGG.h"
#include "LecturaFicheros.h"
#include <algorithm>

using namespace std;
using Random = effolkronium::random_static;
using namespace std;
using namespace std::chrono;


//CRUCE_2PUNTOS************************************************************************************************************************************************************************************

vector<int> beneficiosPoblacion_AGG(vector<vector<int>> _poblacion, vector<int> _vector_beneficio, vector<vector<int>> _matriz_beneficios, vector<int>_vector_peso){

	vector<int>beneficios_poblacion;
	for(int i = 0 ; i < _poblacion.size() ; i++){
    	int benefico = beneficioProducidoSolucion_AGG(_vector_beneficio,_matriz_beneficios,_vector_peso,_poblacion[i]);
    	beneficios_poblacion.push_back(benefico);
	}
	return beneficios_poblacion;
}

int encontrarMejorSolucion_AGG(vector<int> _beneficios_poblacion){
    int mejor = 0;
    int posicion = 0;
    for(int i = 0 ; i < _beneficios_poblacion.size() ; i++){
        if(_beneficios_poblacion[i] >= mejor){
            mejor = _beneficios_poblacion[i];
            posicion = i;
        }
    }
    return posicion;
}

int PesoTotal_AGG(vector<int>_vector_peso, vector<int> _solucion){
    int peso = 0;
    for(int i = 0 ; i < _solucion.size() ; i++){
        if(_solucion[i] == 1){
            peso += _vector_peso[i];
        }
    }
    return peso;
}

int beneficioProducidoSolucion_AGG(vector<int> _vector_beneficio, vector<vector<int>> _matriz_beneficios, vector<int>_vector_peso, vector<int> _solucion){

    int beneficio = 0;

        for(int i = 0 ; i< _solucion.size() ; i++){

        if(_solucion[i] == 1){
            beneficio += _vector_beneficio[i];
            
            for(int j = 0 ; j < _vector_peso.size() ; j++){

                if(_solucion[j] == 1){
                    if(i<j){
                        beneficio+= _matriz_beneficios[i][j];
                        }
                    if(i>j){
                        beneficio += _matriz_beneficios[j][i];
                        }
                }
            }   
        }
    }
    
    
    return beneficio;
}

bool esMejor_AGG(int indice_solucion, int indice_solucion1,  int indice_solucion2 ,vector<int> beneficios_poblacion){

	int beneficio_solucion = beneficios_poblacion[indice_solucion];
	int beneficio_solucion1 = beneficios_poblacion[indice_solucion1];
	int beneficio_solucion2 = beneficios_poblacion[indice_solucion2];

	if(beneficio_solucion >= beneficio_solucion1 && beneficio_solucion >= beneficio_solucion2){
    	return true;
	}
	else{
    	return false;
	}
    
    
}

vector<vector<int>> poblacionInicial_AGG( int _capacidad_mochila  , vector<int> _vector_peso ){

       

        int i = 0;
        vector<vector<int>> poblacion;

        while(i<50){

                int espacio_disponible = _capacidad_mochila;
                vector<int>elementosDisponibles(_vector_peso.size(),1);
                int numeroObjetosDisponibles = elementosDisponibles.size();
                vector<int>solucion(_vector_peso.size(),0);

                

                while (numeroObjetosDisponibles != 0){

                    for (int i = 0 ; i < _vector_peso.size() ; i++){

                        if(elementosDisponibles[i] == 1 && _vector_peso[i] > espacio_disponible){
                            elementosDisponibles[i] = 0;
                            numeroObjetosDisponibles--;
                        }

                    }

                    if(numeroObjetosDisponibles > 0){
                        bool encontrado  =  false;
                        int elementoAleatorio = -1;

                        while(!encontrado){
                            elementoAleatorio = Random::get(0,int(_vector_peso.size()-1));
                            if(elementosDisponibles[elementoAleatorio] == 1){
                                encontrado = true;
                            }
                        }
                        

                        elementosDisponibles[elementoAleatorio] = 0;
                        solucion[elementoAleatorio] = 1;
                        numeroObjetosDisponibles--;
                        espacio_disponible -= _vector_peso[elementoAleatorio];
                    }
                
                }

                

                poblacion.push_back(solucion);
                i++;

        }
        return poblacion;

}

bool torneos_AGG(vector<vector<int>> &_poblacion, int posicion_mejor_solucion, vector<int> &beneficios_poblacion){
        int i = 0;
        vector<vector<int>> _poblacionAux;
        bool encontrado_mejor = false;
        vector<int>beneficios_poblacionAux;

        while(i<50){
            int elementoAleatorio = Random::get(0,int(_poblacion.size()-1));
            int elementoAleatorio1 = Random::get(0,int(_poblacion.size()-1));
            int elementoAleatorio2 = Random::get(0,int(_poblacion.size()-1));

            if(elementoAleatorio != elementoAleatorio1 && elementoAleatorio != elementoAleatorio2 && elementoAleatorio1 != elementoAleatorio2){

                if(esMejor_AGG(elementoAleatorio,elementoAleatorio1,elementoAleatorio2,beneficios_poblacion)){
                    _poblacionAux.push_back(_poblacion[elementoAleatorio]);

                    //para ver si este es el mejor
                    if(_poblacion[elementoAleatorio] == _poblacion[posicion_mejor_solucion]){
                        encontrado_mejor = true;
                    }

                    beneficios_poblacionAux.push_back(beneficios_poblacion[elementoAleatorio]);

                }
                else if(esMejor_AGG(elementoAleatorio1,elementoAleatorio,elementoAleatorio2,beneficios_poblacion)){
                    _poblacionAux.push_back(_poblacion[elementoAleatorio1]);

                    //para ver si este es el mejor
                    if(_poblacion[elementoAleatorio1] == _poblacion[posicion_mejor_solucion]){
                        encontrado_mejor = true;
                    }

                    beneficios_poblacionAux.push_back(beneficios_poblacion[elementoAleatorio1]);
                }
                else if(esMejor_AGG(elementoAleatorio2,elementoAleatorio1,elementoAleatorio,beneficios_poblacion)){
                    _poblacionAux.push_back(_poblacion[elementoAleatorio2]);

                    //para ver si este es el mejor
                    if(_poblacion[elementoAleatorio2] == _poblacion[posicion_mejor_solucion]){
                        encontrado_mejor = true;
                    }

                    beneficios_poblacionAux.push_back(beneficios_poblacion[elementoAleatorio2]);
                }
                i++;
            }
        }

        _poblacion = _poblacionAux;
        beneficios_poblacion = beneficios_poblacionAux;

        return encontrado_mejor;

}  

void cruces_AGG(vector<vector<int>> &_poblacion, int _capacidad_mochila , vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios, vector<int> &beneficios_poblacion){

    int numero_parejas_cruces = (_poblacion.size()/2)*0.68;
    
    int i = 0;
    int j = 0;
    while(i<numero_parejas_cruces){

        vector<vector<int>> cruce_producido = cruce_AGG(_poblacion[j],j,_poblacion[j+1],j+1,_capacidad_mochila,_vector_beneficio,_vector_peso,_matriz_beneficios,beneficios_poblacion);
        
        i++;
        j+=2;
    }
}

vector<vector<int>> cruce_AGG(vector<int> &padre1 ,int indiceP1, vector<int> &padre2,int indiceP2, int _capacidad_mochila , vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios, vector<int> &beneficios_poblacion){

    int elementoAleatorio = 0;
    int elementoAleatorio1 = 0;
    int mayor = 0;
    int menor = 0;

    while(elementoAleatorio == elementoAleatorio1){
        elementoAleatorio = Random::get(0,int(padre1.size()-1));
        elementoAleatorio1 = Random::get(0,int(padre1.size()-1));
    }

    if(elementoAleatorio > elementoAleatorio1){
        mayor = elementoAleatorio;
        menor = elementoAleatorio1;
    }
    if(elementoAleatorio1 > elementoAleatorio){
        mayor = elementoAleatorio1;
        menor = elementoAleatorio;

    }
    
    for(int i = menor; i <= mayor; i++){
        swap(padre1[i],padre2[i]);
    }

   

    while(PesoTotal_AGG(_vector_peso, padre1) > _capacidad_mochila ){

        int elementoEliminar = Random::get(0,int(padre1.size()-1));
        padre1[elementoEliminar] = 0;
    }

    while(PesoTotal_AGG(_vector_peso,padre2) > _capacidad_mochila){

        int elementoEliminar = Random::get(0,int(padre1.size()-1));
        padre2[elementoEliminar] = 0;
    }

    beneficios_poblacion[indiceP1] = beneficioProducidoSolucion_AGG(_vector_beneficio,_matriz_beneficios,_vector_peso,padre1);
    beneficios_poblacion[indiceP2] = beneficioProducidoSolucion_AGG(_vector_beneficio,_matriz_beneficios,_vector_peso,padre2);

    return {padre1,padre2};

}

void mutacion_AGG(vector<vector<int>> &_poblacion , int _capacidad_mochila , vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios , vector<int> &beneficios_poblacion){

     int cromosomas = _poblacion.size();
     int numero_mutaciones = cromosomas*0.08;

     int i = 0;
     


     while(i<numero_mutaciones){
        int indicePoblacion = Random::get(0,int(_poblacion.size()-1));
        vector<int> mutacion_producida = _poblacion[indicePoblacion];
        bool encontrado = false;
        vector<int> mutacion_aux = mutacion_producida;
        
        while(!encontrado){
            

            int elementoAleatorio = Random::get(0,int(_vector_peso.size()-1));
           

            if(mutacion_producida[elementoAleatorio] == 0){
                mutacion_producida[elementoAleatorio] = 1;
            }else{
                mutacion_producida[elementoAleatorio] = 0;
            }
            
          
            if(PesoTotal_AGG(_vector_peso,mutacion_producida) <= _capacidad_mochila){
                _poblacion[indicePoblacion] = mutacion_producida;
                encontrado = true;
                i++;

            }else{

                mutacion_producida = mutacion_aux;
                
            }
            

        }
        beneficios_poblacion[indicePoblacion] = beneficioProducidoSolucion_AGG(_vector_beneficio,_matriz_beneficios,_vector_peso,_poblacion[indicePoblacion]);


    }


}

void reemplazo_AGG(vector<vector<int>> _poblacionAux,vector<vector<int>> &_poblacion , vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios, int posicion_mejor_solucion, vector<int> &beneficios_poblacion){

        int posicion_peor_solucion = -1;
        int peor_solucion = 9999999;

        for ( int i = 0 ; i<_poblacion.size() ; i++){
            int beneficio = beneficios_poblacion[i];
            if(beneficio < peor_solucion){
                peor_solucion = beneficio;
                posicion_peor_solucion = i;
            }
        }

        _poblacion[posicion_peor_solucion] = _poblacionAux[posicion_mejor_solucion];
        beneficios_poblacion[posicion_peor_solucion] = beneficioProducidoSolucion_AGG(_vector_beneficio,_matriz_beneficios,_vector_peso,_poblacion[posicion_peor_solucion]);
}

bool mejorSolucionNuevaPoblacion_AGG(vector<vector<int>> _poblacionAux,vector<vector<int>> _poblacion  , vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios, int posicion_mejor_solucion, vector<int> beneficios_poblacion){
    
    int beneficioMejorSolucionAntigua = beneficioProducidoSolucion_AGG(_vector_beneficio,_matriz_beneficios,_vector_peso,_poblacionAux[posicion_mejor_solucion]);
    for(int i = 0 ; i<50 ; i++){
        if(beneficios_poblacion[i] >= beneficioMejorSolucionAntigua){
            return true;
        }
    }
    return false;

 
}

vector<int> aplicarAlgoritmo_AGG( int _numero_objetos , int _capacidad_mochila , vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios){

    
    vector<vector<int>>poblacion = poblacionInicial_AGG(_capacidad_mochila,_vector_peso);
    vector<vector<int>>poblacionAux = poblacion;

    vector<int>beneficios_poblacion2 = beneficiosPoblacion_AGG(poblacion,_vector_beneficio,_matriz_beneficios,_vector_peso);

    int iteraciones = 0;
    
    while(iteraciones < 90000){
        
            int posicion_mejor_solucion = encontrarMejorSolucion_AGG(beneficios_poblacion2);
            bool encontrado = torneos_AGG(poblacion,posicion_mejor_solucion,beneficios_poblacion2);
            cruces_AGG(poblacion,_capacidad_mochila,_vector_beneficio,_vector_peso,_matriz_beneficios,beneficios_poblacion2);
            mutacion_AGG(poblacion,_capacidad_mochila,_vector_beneficio,_vector_peso,_matriz_beneficios,beneficios_poblacion2);
            bool conseguirMejorSolucion = mejorSolucionNuevaPoblacion_AGG(poblacionAux,poblacion,_vector_beneficio,_vector_peso,_matriz_beneficios,posicion_mejor_solucion,beneficios_poblacion2);
            if(!encontrado && !conseguirMejorSolucion){
                reemplazo_AGG(poblacionAux,poblacion,_vector_beneficio,_vector_peso,_matriz_beneficios,posicion_mejor_solucion,beneficios_poblacion2);
            }
            poblacionAux = poblacion;  
            iteraciones+=50;

    }
    
    int beneficio = 0;
    vector<int> mejorSolucion ;
    for(int i = 0 ; i<50 ; i++){
        int beneficioSolucion = beneficios_poblacion2[i];
        if(beneficioSolucion >= beneficio){
            mejorSolucion = poblacion[i];
            beneficio = beneficioSolucion;
        }

    }
    cout<<beneficio<<endl;
    return mejorSolucion;
}



//CRUCE_PROPUESTO************************************************************************************************************************************************************************************


void cruces_AGG_propuesto(vector<vector<int>> &_poblacion, int _capacidad_mochila , vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios, vector<int> &beneficios_poblacion){

    int numero_parejas_cruces = (_poblacion.size()/2)*0.68;
    
    int i = 0;
    int j = 0;
    while(i<numero_parejas_cruces){

        vector<vector<int>> cruce_producido = cruce_AGG_propuesto(_poblacion[j],j,_poblacion[j+1],j+1,_capacidad_mochila,_vector_beneficio,_vector_peso,_matriz_beneficios,beneficios_poblacion);
        
        i++;
        j+=2;
    }
}

vector<vector<int>> cruce_AGG_propuesto(vector<int> &padre1 ,int indiceP1, vector<int> &padre2,int indiceP2, int _capacidad_mochila , vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios, vector<int> &beneficios_poblacion){

    
    int probabilidad = 5;
    int i = 0;
    while(i<padre1.size()){
        
        int elementoAleatorio = Random::get(1,10);

        if(elementoAleatorio <= probabilidad){
            swap(padre1[i],padre2[i]);
        }

        i++;
    }

   

    while(PesoTotal_AGG(_vector_peso, padre1) > _capacidad_mochila ){

        int elementoEliminar = Random::get(0,int(padre1.size()-1));
        padre1[elementoEliminar] = 0;
    }

    while(PesoTotal_AGG(_vector_peso,padre2) > _capacidad_mochila){

        int elementoEliminar = Random::get(0,int(padre1.size()-1));
        padre2[elementoEliminar] = 0;
    }

    beneficios_poblacion[indiceP1] = beneficioProducidoSolucion_AGG(_vector_beneficio,_matriz_beneficios,_vector_peso,padre1);
    beneficios_poblacion[indiceP2] = beneficioProducidoSolucion_AGG(_vector_beneficio,_matriz_beneficios,_vector_peso,padre2);

    return {padre1,padre2};

}


vector<int> aplicarAlgoritmo_AGG_propuesto( int _numero_objetos , int _capacidad_mochila , vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios){

    
    vector<vector<int>>poblacion = poblacionInicial_AGG(_capacidad_mochila,_vector_peso);
    vector<vector<int>>poblacionAux = poblacion;

    vector<int>beneficios_poblacion2 = beneficiosPoblacion_AGG(poblacion,_vector_beneficio,_matriz_beneficios,_vector_peso);

    int iteraciones = 0;
    
    while(iteraciones < 90000){
        
            int posicion_mejor_solucion = encontrarMejorSolucion_AGG(beneficios_poblacion2);
            bool encontrado = torneos_AGG(poblacion,posicion_mejor_solucion,beneficios_poblacion2);
            cruces_AGG_propuesto(poblacion,_capacidad_mochila,_vector_beneficio,_vector_peso,_matriz_beneficios,beneficios_poblacion2);
            mutacion_AGG(poblacion,_capacidad_mochila,_vector_beneficio,_vector_peso,_matriz_beneficios,beneficios_poblacion2);
            bool conseguirMejorSolucion = mejorSolucionNuevaPoblacion_AGG(poblacionAux,poblacion,_vector_beneficio,_vector_peso,_matriz_beneficios,posicion_mejor_solucion,beneficios_poblacion2);
            if(!encontrado && !conseguirMejorSolucion){
                reemplazo_AGG(poblacionAux,poblacion,_vector_beneficio,_vector_peso,_matriz_beneficios,posicion_mejor_solucion,beneficios_poblacion2);
            }
            poblacionAux = poblacion;  
            iteraciones+=50;

    }
    
    int beneficio = 0;
    vector<int> mejorSolucion ;
    for(int i = 0 ; i<50 ; i++){
        int beneficioSolucion = beneficios_poblacion2[i];
        if(beneficioSolucion >= beneficio){
            mejorSolucion = poblacion[i];
            beneficio = beneficioSolucion;
        }

    }
    cout<<beneficio<<endl;
    return mejorSolucion;
}


