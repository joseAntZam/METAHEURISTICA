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
#include "FuncionesComunes.h"
#include <algorithm>

using namespace std;
using Random = effolkronium::random_static;
using namespace std;
using namespace std::chrono;




void busquedadLocal(vector<int> _vector_peso,  vector<int> _vector_beneficio ,  vector<vector<int>> _matriz_beneficios,int _capacidad_mochila, vector<int>& Solucion, int& beneficio){


                vector<int> cromosoma = Solucion;
                int iteracionesAux = 0;    


                int contadorVecinosExplorar = 0; 
                bool posible_vecino = true;
                vector<vector<int>>vecinos;

                int beneficio_actual = beneficioProducidoSolucion(_vector_beneficio,_matriz_beneficios,_vector_peso,cromosoma);


                
                        while( iteracionesAux < 4500 && posible_vecino ){
                            
                                    
                                    vector<int>solucionCandidata = cromosoma;
                                    int espacio_disponible =  _capacidad_mochila - PesoTotal(_vector_peso,cromosoma);

                                    if(contadorVecinosExplorar == 0){
                                        vecinos = generarVecinos(solucionCandidata);
                                        Random::shuffle(vecinos);
                                    }

                                    solucionCandidata[vecinos[contadorVecinosExplorar][0]] = 0;
                                    solucionCandidata[vecinos[contadorVecinosExplorar][1]] = 1;

                                   espacio_disponible += _vector_peso[vecinos[contadorVecinosExplorar][0]];
                                   espacio_disponible -= _vector_peso[vecinos[contadorVecinosExplorar][1]];

                                   
                                   int beneficio_candidata = beneficioProducidoSolucion_Factorizado(_vector_beneficio,_matriz_beneficios,_vector_peso,vecinos[contadorVecinosExplorar][0],vecinos[contadorVecinosExplorar][1],beneficio_actual,cromosoma);
                                   

                                    if(beneficio_actual < beneficio_candidata && espacio_disponible >= 0){
                                        cromosoma = solucionCandidata;
                                        contadorVecinosExplorar = 0;
                                        iteracionesAux++;
                                        beneficio_actual = beneficio_candidata;
                                    }
                                    else if (contadorVecinosExplorar == vecinos.size() -1 ){
                                        posible_vecino = false;
                                        
                                    }
                                    else{
                                        contadorVecinosExplorar++;
                                        iteracionesAux++;
                                    }

                        
                        } 
                Solucion = cromosoma;
                beneficio = beneficio_actual;       
}



vector<int> busquedadLocalP1(vector<int> _vector_peso,  vector<int> _vector_beneficio ,  vector<vector<int>> _matriz_beneficios,int _capacidad_mochila, int& beneficio){


                vector<int> cromosoma = generarSolucionAleatoria(_vector_peso,_capacidad_mochila);
                int iteracionesAux = 0;    


                int contadorVecinosExplorar = 0; 
                bool posible_vecino = true;
                vector<vector<int>>vecinos;

                int beneficio_actual = beneficioProducidoSolucion(_vector_beneficio,_matriz_beneficios,_vector_peso,cromosoma);


                
                        while( iteracionesAux < 90000 && posible_vecino ){
                            
                                    
                                    vector<int>solucionCandidata = cromosoma;
                                    int espacio_disponible =  _capacidad_mochila - PesoTotal(_vector_peso,cromosoma);

                                    if(contadorVecinosExplorar == 0){
                                        vecinos = generarVecinos(solucionCandidata);
                                        Random::shuffle(vecinos);
                                    }

                                    solucionCandidata[vecinos[contadorVecinosExplorar][0]] = 0;
                                    solucionCandidata[vecinos[contadorVecinosExplorar][1]] = 1;

                                   espacio_disponible += _vector_peso[vecinos[contadorVecinosExplorar][0]];
                                   espacio_disponible -= _vector_peso[vecinos[contadorVecinosExplorar][1]];

                                   
                                   int beneficio_candidata = beneficioProducidoSolucion_Factorizado(_vector_beneficio,_matriz_beneficios,_vector_peso,vecinos[contadorVecinosExplorar][0],vecinos[contadorVecinosExplorar][1],beneficio_actual,cromosoma);
                                   

                                    if(beneficio_actual < beneficio_candidata && espacio_disponible >= 0){
                                        cromosoma = solucionCandidata;
                                        contadorVecinosExplorar = 0;
                                        iteracionesAux++;
                                        beneficio_actual = beneficio_candidata;
                                    }
                                    else if (contadorVecinosExplorar == vecinos.size() -1 ){
                                        posible_vecino = false;
                                        
                                    }
                                    else{
                                        contadorVecinosExplorar++;
                                        iteracionesAux++;
                                    }

                        
                        }
                beneficio = beneficio_actual; 
                return cromosoma;      
}
