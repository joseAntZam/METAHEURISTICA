#include <vector>
#include <algorithm>
#include <string>
#include <chrono>
#include <ctime>
#include "random.hpp"
#include "BL.h"
#include "ES.h"
#include "FuncionesComunes.h"
#include <algorithm>

using namespace std;
using Random = effolkronium::random_static;
using namespace std;
using namespace std::chrono;


void mutacion(vector<int> _vector_peso , vector<int> _vector_beneficio , vector<vector<int>> _matriz_beneficios, int _capacidad_mochila, vector<int> &solucion){

    vector<int>solucionAux = solucion;
    int elementoAleatorio = Random::get(0,int(_vector_peso.size()-1));

    vector<int>indices;
    vector<int>indicesAux;

    if(elementoAleatorio + 20 <= _vector_peso.size()){
            int i = elementoAleatorio;
            while(i < elementoAleatorio + 20 ){
                indices.push_back(i);
                indicesAux.push_back(i);
                i++;
            }
            
    }
    else{
            int sobrantes =  (elementoAleatorio+19) - _vector_peso.size()-1;
            int tope = 20 - sobrantes;

            int i = 0;
            while(i < tope){
                indices.push_back(elementoAleatorio+i);
                indicesAux.push_back(elementoAleatorio+i);
                i++;
            }

            int j = 0;
            while(j < sobrantes){
                indices.push_back(j);
                indicesAux.push_back(j);
                j++;
            }

            
    }

    Random::shuffle(indices);

    for ( int i = 0 ; i < indices.size() ; i++){
        solucion[indicesAux[i]] = solucionAux[indices[i]];
    }

    int peso = PesoTotal(_vector_peso,solucion);
    while(peso > _capacidad_mochila){
       //elemento aleatorio entre los valores de indicesAux
         int elemento = Random::get(0,int(indicesAux.size()-1));
         if(solucion[indicesAux[elemento]] == 1){
            solucion[indicesAux[elemento]] = 0;
            peso -= _vector_peso[indicesAux[elemento]];
         }
    }


}


vector<int>ILS(vector<int> _vector_peso , vector<int> _vector_beneficio , vector<vector<int>> _matriz_beneficios, int _capacidad_mochila){

        vector<int>S = generarSolucionAleatoria(_vector_peso,_capacidad_mochila);
        int mejor_benficio = 0;
        busquedadLocal(_vector_peso,_vector_beneficio,_matriz_beneficios,_capacidad_mochila,S,mejor_benficio);
        vector<int>mejor_solucion = S;
        
        int i = 1;

        while(i<20){

            vector<int> solucion_mutada = mejor_solucion;  //MUTAR SOLUCION
            mutacion(_vector_peso,_vector_beneficio,_matriz_beneficios,_capacidad_mochila,solucion_mutada);
            int benfecios_mutada = 0;
            busquedadLocal(_vector_peso,_vector_beneficio,_matriz_beneficios,_capacidad_mochila,solucion_mutada,benfecios_mutada);
            if(benfecios_mutada > mejor_benficio){
                mejor_benficio = benfecios_mutada;
                mejor_solucion = solucion_mutada;
            }
            i++;

        }

        return mejor_solucion;
        
}

vector<int>ILSES(vector<int> _vector_peso , vector<int> _vector_beneficio , vector<vector<int>> _matriz_beneficios, int _capacidad_mochila){

        vector<int>S = generarSolucionAleatoria(_vector_peso,_capacidad_mochila);
        int mejor_benficio = 0;
        ES(_vector_peso,_vector_beneficio,_matriz_beneficios,_capacidad_mochila,S,mejor_benficio);
        vector<int>mejor_solucion = S;
        
        int i = 1;

        while(i<20){

            vector<int> solucion_mutada = mejor_solucion;  //MUTAR SOLUCION
            mutacion(_vector_peso,_vector_beneficio,_matriz_beneficios,_capacidad_mochila,solucion_mutada);
            int benfecios_mutada = 0;
            ES(_vector_peso,_vector_beneficio,_matriz_beneficios,_capacidad_mochila,solucion_mutada,benfecios_mutada);
            if(benfecios_mutada > mejor_benficio){
                mejor_benficio = benfecios_mutada;
                mejor_solucion = solucion_mutada;
            }
            i++;

        }

        return mejor_solucion;
        
}