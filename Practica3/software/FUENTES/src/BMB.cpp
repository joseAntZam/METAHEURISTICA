#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <chrono>
#include <ctime>
#include "random.hpp"
#include "BL.h"
#include "FuncionesComunes.h"
#include <algorithm>

using namespace std;
using Random = effolkronium::random_static;
using namespace std;
using namespace std::chrono;

vector<int > BMB(vector<int> _vector_peso , vector<int> _vector_beneficio , vector<vector<int>> _matriz_beneficios, int _capacidad_mochila){

        int mejor_benficio = 0 ;
        vector<int> mejor_solucion(_vector_peso.size(),0);
        int i = 0 ;
        while( i < 20 ){

            int beneficio = 0;
            vector<int> solucion = generarSolucionAleatoria(_vector_peso,_capacidad_mochila);
            busquedadLocal(_vector_peso,_vector_beneficio,_matriz_beneficios,_capacidad_mochila,solucion,beneficio);

            if(beneficio > mejor_benficio){
                mejor_benficio = beneficio;
                mejor_solucion = solucion;
            }
            i++;
        }
        return mejor_solucion;
        

}