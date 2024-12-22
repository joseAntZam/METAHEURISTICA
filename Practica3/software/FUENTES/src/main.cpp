//lectura de un fichero



#include "LecturaFicheros.h"
#include "random.hpp"
#include <chrono>
#include <ctime>
#include <iostream>
#include <vector>
#include "FuncionesComunes.h"
#include "BL.h"
#include "ES.h"
#include "ILS.h"
#include "BMB.h"



using namespace std;
using Random = effolkronium::random_static;
using namespace std::chrono;





int main(int argc, char* argv[]) {
    int _numero_objetos ,_capacidad_mochila ,posicion_mejor_solucion;
    vector<int> _vector_beneficio ,_vector_peso ;
    vector<vector<int>> _matriz_beneficios;   

    leerFichero(argv[1],_numero_objetos , _capacidad_mochila , _vector_beneficio , _vector_peso , _matriz_beneficios );

    
    high_resolution_clock::time_point tantes , tdespues;
    vector<int> solucion;
   //Meter semilla 15

    //EJECUCION BMB*********************************************************************************************************************
    if(argv[2]== string("1")){
        
        Random::seed(atoi(argv[3]));
        tantes = high_resolution_clock::now();
            solucion = BMB( _vector_peso , _vector_beneficio , _matriz_beneficios , _capacidad_mochila );
        tdespues = high_resolution_clock::now();
    }

    //EJECUCION ILS*********************************************************************************************************************
    if(argv[2] == string("2")){
        Random::seed(atoi(argv[3]));
        tantes = high_resolution_clock::now();
            solucion = ILS( _vector_peso , _vector_beneficio , _matriz_beneficios , _capacidad_mochila );
        tdespues = high_resolution_clock::now();
    }

    //EJECUCION ES*********************************************************************************************************************
    if(argv[2] == string("3")){
        Random::seed(atoi(argv[3]));
        tantes = high_resolution_clock::now();
            solucion = ES( _vector_peso , _vector_beneficio , _matriz_beneficios , _capacidad_mochila);
        tdespues = high_resolution_clock::now();
    }

    //EJECUCION BL Practica1************************************************************************************************************
    int beneficio = 0;
    if(argv[2] == string("4")){
        Random::seed(atoi(argv[3]));
        tantes = high_resolution_clock::now();
        solucion = busquedadLocalP1( _vector_peso , _vector_beneficio , _matriz_beneficios , _capacidad_mochila, beneficio);
        tdespues = high_resolution_clock::now();
    }

    //EJECUCION ILSES*********************************************************************************************************************
    if(argv[2] == string("5")){
        Random::seed(atoi(argv[3]));
        tantes = high_resolution_clock::now();
            solucion = ILSES( _vector_peso , _vector_beneficio , _matriz_beneficios , _capacidad_mochila );
        tdespues = high_resolution_clock::now();
    }


    duration<double> transcurrido = duration_cast<duration<double>>(tdespues - tantes);
    cout<<beneficioProducidoSolucion(_vector_beneficio,_matriz_beneficios,_vector_peso,solucion)<<endl;
    cout<<transcurrido.count()<<endl;

    //mostrar solucion
    for(int i = 0; i < solucion.size(); i++){
        cout<<solucion[i]<<" ";
    }
    cout<<endl;
    

    return 0;

}