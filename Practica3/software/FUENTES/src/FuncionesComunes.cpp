
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <chrono>
#include <ctime>
#include "random.hpp"
#include "FuncionesComunes.h"
#include "LecturaFicheros.h"
#include <algorithm>

using namespace std;
using Random = effolkronium::random_static;
using namespace std;
using namespace std::chrono;



vector<vector<int>> generarVecinos(vector<int>solucion){

    vector<vector<int>>vecinos;

    for ( int i = 0 ; i < solucion.size() ; i++){

        if(solucion[i]== 1){

            for(int j = 0 ; j< solucion.size() ; j++){
                
                if(solucion[j] == 0){

                    vector<int>vecino;
                    vecino.push_back(i);
                    vecino.push_back(j);
                    vecinos.push_back(vecino);


                }
            }


        }
        
    }

    return vecinos;
}

vector<int> generarSolucionAleatoria(vector<int> _vector_peso, int _capacidad_mochila){

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

        return solucion;

}


int beneficioProducidoSolucion(vector<int> _vector_beneficio, vector<vector<int>> _matriz_beneficios, vector<int>_vector_peso, vector<int> _solucion){

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

int PesoTotal(vector<int>_vector_peso, vector<int> _solucion){
    int peso = 0;
    for(int i = 0 ; i < _solucion.size() ; i++){
        if(_solucion[i] == 1){
            peso += _vector_peso[i];
        }
    }
    return peso;
}


// MODIFICADA 
int beneficioProducidoSolucion_Factorizado(vector<int> _vector_beneficio, vector<vector<int>> _matriz_beneficios, vector<int>_vector_peso, int eliminado ,int  asignado, int beneficio, vector<int> _solucion){

    int beneficioAux = beneficio;
    beneficioAux -= _vector_beneficio[eliminado];
    beneficioAux += _vector_beneficio[asignado];

    for(int i = 0 ; i < _vector_peso.size() ; i++){
        if(_solucion[i] == 1){
                if(i != eliminado ){
                
                        if(i<eliminado){
                            beneficioAux -= ((_matriz_beneficios[i][eliminado])*2);
                        }
                        if(i>eliminado){
                            beneficioAux -= ((_matriz_beneficios[eliminado][i])*2);
                        }
                

                }
                if(i != asignado && i != eliminado){

                        if(i<asignado){
                            beneficioAux += ((_matriz_beneficios[i][asignado])*2);
                        }
                        if(i>asignado){
                            beneficioAux += ((_matriz_beneficios[asignado][i])*2);
                        }
                }
        }
    } 
    
    return beneficioAux;
}


int PesoTotal_Factorizado(vector<int>_vector_peso,  int eliminado ,int  asignado, int peso ){
    int pesoAux = peso;
    pesoAux -= _vector_peso[eliminado];
    pesoAux += _vector_peso[asignado];
    return pesoAux;
}