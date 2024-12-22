#include <vector>
#include <algorithm>
#include <string>
#include <chrono>
#include <ctime>
#include "random.hpp"
#include "FuncionesComunes.h"
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;
using Random = effolkronium::random_static;
using namespace std;
using namespace std::chrono;

double Cauchy(double tkmenos1, double temperaturaInicial,int temperaturaFinal, int MaxVecinos, int iteraciones) {
    double B = (temperaturaInicial-(temperaturaFinal)) / ((iteraciones/MaxVecinos)*temperaturaInicial*temperaturaFinal);
    double tk = tkmenos1/(1+B*tkmenos1);
    return tk;
    
}


vector<int>ES(vector<int> _vector_peso , vector<int> _vector_beneficio , vector<vector<int>> _matriz_beneficios, int _capacidad_mochila){

        //Genero solucioón y la almaceno en la mejor solución
                vector<int>solucion = generarSolucionAleatoria(_vector_peso,_capacidad_mochila);
                vector<int>mejor_solucion = solucion;
        //Calculo el beneficio de la solución, para evitar tener que calcularlo en cada iteración
                int beneficio = beneficioProducidoSolucion(_vector_beneficio,_matriz_beneficios,_vector_peso,solucion);
                int beneficio_mejor_solucion = beneficio;
        //Calculo el peso de la solución, para evitar tener que calcularlo en cada iteración
                int peso = PesoTotal(_vector_peso,solucion);
                int peso_mejor_solucion = peso;
        //Inicializo la temperatura inicial y la almaceno en temperatura
                double temperaturaInicial = (0.1 * beneficio) / (-log(0.3));
                double temperatura = temperaturaInicial;
                double temperaturaFinal = 0.001;
        //Inicializo las variables de control
                int evaluaciones = 0;
                // Lo pongo a cero para que pueda entrar en el bucle
                int Nexitos = 1;
                int Nvecinos = 0;
                int MaxVecinos = 5*(_vector_peso.size());
                int MaxExitos = 0.1*MaxVecinos;

        while(temperaturaFinal >= temperaturaInicial){
            temperaturaFinal = temperaturaFinal/10;
        }

        int contador = 0;
        while(evaluaciones < 90000 && Nexitos > 0){

            Nexitos = 0 ;
            Nvecinos = 0;
            vector<vector<int>> vecinos;
            contador = 0;


            while(Nexitos < MaxExitos && Nvecinos < MaxVecinos && evaluaciones < 90000 ){

                            vector<int> vecino = solucion;

                            if(contador == 0){
                                vecinos = generarVecinos(solucion);
                                Random::shuffle(vecinos);
                            }

                            vecino[vecinos[contador][0]] = 0;
                            vecino[vecinos[contador][1]] = 1;

                            int beneficioVecino = beneficioProducidoSolucion_Factorizado(_vector_beneficio,_matriz_beneficios,_vector_peso,vecinos[contador][0],vecinos[contador][1],beneficio,solucion);
                            int pesoVecino = PesoTotal_Factorizado(_vector_peso,vecinos[contador][0],vecinos[contador][1],peso);
                            int incremento  =  beneficioVecino - beneficio;
                            Nvecinos++;
                            evaluaciones++;
                            contador ++;
                            

                            if((incremento > 0 || Random::get(0,10)*0.1 <= (exp(incremento/temperatura))) && pesoVecino <= _capacidad_mochila ){

                                Nexitos++;
                                contador = 0;
                                solucion = vecino;
                                beneficio = beneficioVecino;
                                peso = pesoVecino;
                                if(beneficioVecino > beneficio_mejor_solucion){
                                    mejor_solucion = solucion;
                                    beneficio_mejor_solucion = beneficioVecino;
                                    peso_mejor_solucion = pesoVecino;
                                }

                             }
                             if(contador >= vecinos.size()){
                                Nexitos= 0;
                                Nvecinos = MaxVecinos;
                             }
                             
                        
                        
                             
            }

            temperatura = Cauchy(temperatura,temperaturaInicial,temperaturaFinal,MaxVecinos,90000);

        }
        return mejor_solucion;
  
}




void ES(vector<int> _vector_peso , vector<int> _vector_beneficio , vector<vector<int>> _matriz_beneficios, int _capacidad_mochila,vector<int>& solucion_inicial, int& beneficio_resultado ){

         
        //Genero solucioón y la almaceno en la mejor solución
                vector<int>solucion = solucion_inicial;
                vector<int>mejor_solucion = solucion;
        //Calculo el beneficio de la solución, para evitar tener que calcularlo en cada iteración
                int beneficio = beneficioProducidoSolucion(_vector_beneficio,_matriz_beneficios,_vector_peso,solucion);
                int beneficio_mejor_solucion = beneficio;
        //Calculo el peso de la solución, para evitar tener que calcularlo en cada iteración
                int peso = PesoTotal(_vector_peso,solucion);
                int peso_mejor_solucion = peso;
        //Inicializo la temperatura inicial y la almaceno en temperatura
                double temperaturaInicial = (0.1 * beneficio) / (-log(0.3));
                double temperatura = temperaturaInicial;
                double temperaturaFinal = 0.001;
        //Inicializo las variables de control
                int evaluaciones = 0;
                // Lo pongo a cero para que pueda entrar en el bucle
                int Nexitos = 1;
                int Nvecinos = 0;
                int MaxVecinos = 5*(_vector_peso.size());
                int MaxExitos = 0.1*MaxVecinos;

        while(temperaturaFinal >= temperaturaInicial){
            temperaturaFinal = temperaturaFinal/10;
        }

        int contador = 0;
        while(evaluaciones < 4500 && Nexitos > 0){

            Nexitos = 0 ;
            Nvecinos = 0;
            vector<vector<int>> vecinos;
            contador = 0;


            while(Nexitos < MaxExitos && Nvecinos < MaxVecinos && evaluaciones < 4500 ){

                            vector<int> vecino = solucion;

                            if(contador == 0){
                                vecinos = generarVecinos(solucion);
                                Random::shuffle(vecinos);
                            }

                            vecino[vecinos[contador][0]] = 0;
                            vecino[vecinos[contador][1]] = 1;

                            int beneficioVecino = beneficioProducidoSolucion_Factorizado(_vector_beneficio,_matriz_beneficios,_vector_peso,vecinos[contador][0],vecinos[contador][1],beneficio,solucion);
                            int pesoVecino = PesoTotal_Factorizado(_vector_peso,vecinos[contador][0],vecinos[contador][1],peso);
                            int incremento  =  beneficioVecino - beneficio;
                            Nvecinos++;
                            evaluaciones++;
                            contador ++;
                            

                            if((incremento > 0 || Random::get(0,10)*0.1 <= (exp(incremento/temperatura))) && pesoVecino <= _capacidad_mochila ){

                                Nexitos++;
                                contador = 0;
                                solucion = vecino;
                                beneficio = beneficioVecino;
                                peso = pesoVecino;
                                if(beneficioVecino > beneficio_mejor_solucion){
                                    mejor_solucion = solucion;
                                    beneficio_mejor_solucion = beneficioVecino;
                                    peso_mejor_solucion = pesoVecino;
                                }

                             }
                             if(contador >= vecinos.size()){
                                Nexitos= 0;
                                Nvecinos = MaxVecinos;
                             }
                             
                        
                        
                             
            }

            temperatura = Cauchy(temperatura,temperaturaInicial,temperaturaFinal,MaxVecinos,4500);

        }

        beneficio_resultado = beneficio_mejor_solucion;
        solucion_inicial = mejor_solucion;
  
}


