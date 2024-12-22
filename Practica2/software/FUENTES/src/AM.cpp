//lectura de un fichero
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <chrono>
#include <ctime>
#include "random.hpp"
#include "BL.h"
#include "AGG.h"
#include "AM.h"

using namespace std;
using Random = effolkronium::random_static;
using namespace std;
using namespace std::chrono;



int encontrarMejorSolucion_AMM(vector<int> _beneficios_poblacion , int posicion_excluida , double beneficio_ultima_solucion){
    int mejor = 0;
    int posicion = 0;
    for(int i = 0 ; i < _beneficios_poblacion.size() ; i++){
        if(_beneficios_poblacion[i] >= mejor && _beneficios_poblacion[i] <= beneficio_ultima_solucion &&  i != posicion_excluida){
            mejor = _beneficios_poblacion[i];
            posicion = i;
        }
    }
    return posicion;
}


vector<int> aplicarAlgoritmo_AM_ALL( int _numero_objetos , int _capacidad_mochila , vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios){

    
    vector<vector<int>>poblacion = poblacionInicial_AGG(_capacidad_mochila,_vector_peso);
    vector<vector<int>>poblacionAux = poblacion;

    vector<int>beneficios_poblacion = beneficiosPoblacion_AGG(poblacion,_vector_beneficio,_matriz_beneficios,_vector_peso);



    int iteraciones = 0;
    int generacion = 0;
    
    while(iteraciones < 90000){

            
            
            if(generacion % 10  == 0){
                for(int i = 0 ; i< 50 && iteraciones < 90000 ; i++){
                    int iteracionBL;
                    busquedadLocal(_vector_peso,_vector_beneficio,_matriz_beneficios,_capacidad_mochila,poblacion,i,beneficios_poblacion,iteracionBL , iteraciones);
                    iteraciones+=iteracionBL;
                }
            }


            
          
                int posicion_mejor_solucion = encontrarMejorSolucion_AGG(beneficios_poblacion);
                bool encontrado = torneos_AGG(poblacion,posicion_mejor_solucion,beneficios_poblacion);
                cruces_AGG(poblacion,_capacidad_mochila,_vector_beneficio,_vector_peso,_matriz_beneficios,beneficios_poblacion);
                mutacion_AGG(poblacion,_capacidad_mochila,_vector_beneficio,_vector_peso,_matriz_beneficios,beneficios_poblacion);
                bool conseguirMejorSolucion = mejorSolucionNuevaPoblacion_AGG(poblacionAux,poblacion,_vector_beneficio,_vector_peso,_matriz_beneficios,posicion_mejor_solucion,beneficios_poblacion);
                if(!encontrado && !conseguirMejorSolucion){
                    reemplazo_AGG(poblacionAux,poblacion,_vector_beneficio,_vector_peso,_matriz_beneficios,posicion_mejor_solucion,beneficios_poblacion);
                }
                poblacionAux = poblacion;  
                iteraciones+=50;
                generacion++;
            
    }
    
    int beneficio = 0;
    vector<int> mejorSolucion ;
    for(int i = 0 ; i<50 ; i++){
        int beneficioSolucion = beneficios_poblacion[i];
        if(beneficioSolucion >= beneficio){
            mejorSolucion = poblacion[i];
            beneficio = beneficioSolucion;
        }

    }
    cout<<beneficio<<endl;
    return mejorSolucion;
}



vector<int> aplicarAlgoritmo_AM_RAND( int _numero_objetos , int _capacidad_mochila , vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios){

    
    vector<vector<int>>poblacion = poblacionInicial_AGG(_capacidad_mochila,_vector_peso);
    vector<vector<int>>poblacionAux = poblacion;

    vector<int>beneficios_poblacion = beneficiosPoblacion_AGG(poblacion,_vector_beneficio,_matriz_beneficios,_vector_peso);

    int iteraciones = 0;
    int generacion = 0;
    
    while(iteraciones < 90000){

            
            
            if(generacion % 10  == 0){

                for(int i = 0 ; i< (poblacion.size()*0.1) && iteraciones < 90000; i++){
                    int iteracionBL;
                    int indice = Random::get(0,49);
                    busquedadLocal(_vector_peso,_vector_beneficio,_matriz_beneficios,_capacidad_mochila,poblacion,indice,beneficios_poblacion,iteracionBL, iteraciones);
                    iteraciones+=iteracionBL;
                }
            }
            
            
            
        
            int posicion_mejor_solucion = encontrarMejorSolucion_AGG(beneficios_poblacion);
            bool encontrado = torneos_AGG(poblacion,posicion_mejor_solucion,beneficios_poblacion);
            cruces_AGG(poblacion,_capacidad_mochila,_vector_beneficio,_vector_peso,_matriz_beneficios,beneficios_poblacion);
            mutacion_AGG(poblacion,_capacidad_mochila,_vector_beneficio,_vector_peso,_matriz_beneficios,beneficios_poblacion);
            bool conseguirMejorSolucion = mejorSolucionNuevaPoblacion_AGG(poblacionAux,poblacion,_vector_beneficio,_vector_peso,_matriz_beneficios,posicion_mejor_solucion,beneficios_poblacion);
            if(!encontrado && !conseguirMejorSolucion){
                reemplazo_AGG(poblacionAux,poblacion,_vector_beneficio,_vector_peso,_matriz_beneficios,posicion_mejor_solucion,beneficios_poblacion);
            }
            poblacionAux = poblacion;  
            iteraciones+=50;
            generacion++;

    }
    
    int beneficio = 0;
    
    vector<int> mejorSolucion ;
     
    for(int i = 0 ; i<50 ; i++){
        int beneficioSolucion = beneficios_poblacion[i];
        if(beneficioSolucion >= beneficio){
            mejorSolucion = poblacion[i];
            beneficio = beneficioSolucion;
        }

    }
    cout<<beneficio<<endl;
   
    return mejorSolucion;
}



vector<int> aplicarAlgoritmo_AM_BEST( int _numero_objetos , int _capacidad_mochila , vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios){

    
    vector<vector<int>>poblacion = poblacionInicial_AGG(_capacidad_mochila,_vector_peso);
    vector<vector<int>>poblacionAux = poblacion;

    vector<int>beneficios_poblacion = beneficiosPoblacion_AGG(poblacion,_vector_beneficio,_matriz_beneficios,_vector_peso);

    int iteraciones = 0;
    int generacion = 0;
    
    while(iteraciones < 90000){

            
            
            if(generacion % 10  == 0){

                int posicion_excluida = 9999;
                double beneficio_ultima_solucion = INFINITY;
                vector<int>indicesMejores;
                for(int i = 0 ; i< (poblacion.size()*0.1) ; i++){
                    
                   int posicion_producida = encontrarMejorSolucion_AMM(beneficios_poblacion,posicion_excluida,beneficio_ultima_solucion);
                   indicesMejores.push_back(posicion_producida);
                   posicion_excluida = posicion_producida;
                   beneficio_ultima_solucion = beneficios_poblacion[posicion_producida];
                }


                for(int i = 0 ; i< (poblacion.size()*0.1) && iteraciones < 90000; i++){
                    int iteracionBL;
                    busquedadLocal(_vector_peso,_vector_beneficio,_matriz_beneficios,_capacidad_mochila,poblacion,indicesMejores[i],beneficios_poblacion,iteracionBL , iteraciones);
                    iteraciones+=iteracionBL;
                }
            }
            
            
            
        
            int posicion_mejor_solucion = encontrarMejorSolucion_AGG(beneficios_poblacion);
            bool encontrado = torneos_AGG(poblacion,posicion_mejor_solucion,beneficios_poblacion);
            cruces_AGG(poblacion,_capacidad_mochila,_vector_beneficio,_vector_peso,_matriz_beneficios,beneficios_poblacion);
            mutacion_AGG(poblacion,_capacidad_mochila,_vector_beneficio,_vector_peso,_matriz_beneficios,beneficios_poblacion);
            bool conseguirMejorSolucion = mejorSolucionNuevaPoblacion_AGG(poblacionAux,poblacion,_vector_beneficio,_vector_peso,_matriz_beneficios,posicion_mejor_solucion,beneficios_poblacion);
            if(!encontrado && !conseguirMejorSolucion){
                reemplazo_AGG(poblacionAux,poblacion,_vector_beneficio,_vector_peso,_matriz_beneficios,posicion_mejor_solucion,beneficios_poblacion);
            }
            poblacionAux = poblacion;  
            iteraciones+=50;
            generacion++;

    }
    
    int beneficio = 0;
    
    vector<int> mejorSolucion ;
    
    for(int i = 0 ; i<50 ; i++){
        int beneficioSolucion = beneficios_poblacion[i];
        if(beneficioSolucion >= beneficio){
            mejorSolucion = poblacion[i];
            beneficio = beneficioSolucion;
        }

    }
    cout<<beneficio<<endl;
    
    return mejorSolucion;
}
