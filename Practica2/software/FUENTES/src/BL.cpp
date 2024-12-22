#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <chrono>
#include <ctime>
#include "random.hpp"
#include "BL.h"
#include "LecturaFicheros.h"
#include <algorithm>

using namespace std;
using Random = effolkronium::random_static;
using namespace std;
using namespace std::chrono;


int PesoTotal_BL(vector<int>_vector_peso, vector<int> _solucion){
    int peso = 0;
    for(int i = 0 ; i < _solucion.size() ; i++){
        if(_solucion[i] == 1){
            peso += _vector_peso[i];
        }
    }
    return peso;
}

int beneficioProducidoSolucion_BL(vector<int> _vector_beneficio, vector<vector<int>> _matriz_beneficios, vector<int>_vector_peso, vector<int> _solucion){

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

vector<vector<int>> generarVecinos_BL(vector<int>solucion){

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

void busquedadLocal(vector<int> _vector_peso,  vector<int> _vector_beneficio ,  vector<vector<int>> _matriz_beneficios,int _capacidad_mochila, vector<vector<int>> &poblacion , int posicion_cromosoma, vector<int> &beneficio_poblacion, int &iteraciones , int iteraciones_globales){


                vector<int> cromosoma = poblacion[posicion_cromosoma];
                int iteracionesAux = 0;    


                int contadorVecinosExplorar = 0; 
                bool posible_vecino = true;
                vector<vector<int>>vecinos;
                
                

               

                //BL--> Para cada cromosoma de la poblacion
                        while( iteracionesAux < _vector_peso.size() && (iteracionesAux + iteraciones_globales) < 90000 && posible_vecino ){
                            
                                    
                                    vector<int>solucionCandidata = cromosoma;
                                    int espacio_disponible =  _capacidad_mochila - PesoTotal_BL(_vector_peso,cromosoma);

                                    if(contadorVecinosExplorar == 0){
                                        vecinos = generarVecinos_BL(solucionCandidata);
                                        Random::shuffle(vecinos);
                                    }

                                    solucionCandidata[vecinos[contadorVecinosExplorar][0]] = 0;
                                    solucionCandidata[vecinos[contadorVecinosExplorar][1]] = 1;


                                    for(int i = 0 ; i < solucionCandidata.size() ; i++){
                                        if(solucionCandidata[i] == 1){
                                            espacio_disponible -= _vector_peso[i];
                                        }
                                        
                                    }
                                   int beneficio_candidata = beneficioProducidoSolucion_BL(_vector_beneficio,_matriz_beneficios,_vector_peso,solucionCandidata);
                                   
                                    if(beneficio_poblacion[posicion_cromosoma] < beneficio_candidata && espacio_disponible >= 0){
                                        cromosoma = solucionCandidata;
                                        contadorVecinosExplorar = 0;
                                        iteracionesAux++;
                                        beneficio_poblacion[posicion_cromosoma] = beneficio_candidata;
                                        poblacion[posicion_cromosoma] = cromosoma;


                                    }
                                    else if (contadorVecinosExplorar == vecinos.size() -1 ){
                                        posible_vecino = false;
                                        
                                    }
                                    else{
                                        contadorVecinosExplorar++;
                                        iteracionesAux++;
                                    }

                        }

                        
                //FIN BL--> Para cada cromosoma de la poblacion


                        iteraciones = iteracionesAux;

                 
}
