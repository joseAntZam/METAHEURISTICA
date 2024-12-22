//lectura de un fichero


#include "AGG.h"
#include "AGE.h"
#include "AM.h"
#include "LecturaFicheros.h"
#include "random.hpp"
#include <chrono>
#include <ctime>

using namespace std;
using Random = effolkronium::random_static;
using namespace std::chrono;





int main(int argc, char* argv[]) {
    int _numero_objetos ,_capacidad_mochila ,posicion_mejor_solucion;
    vector<int> _vector_beneficio ,_vector_peso ;
    vector<vector<int>> _matriz_beneficios;   

    leerFichero(argv[1],_numero_objetos , _capacidad_mochila , _vector_beneficio , _vector_peso , _matriz_beneficios );

    //crea otras variables para guardar los resultados de leerFichero
    vector<int> _vector_beneficio2 = _vector_beneficio;
    vector<int> _vector_peso2 = _vector_peso;
    vector<vector<int>> _matriz_beneficios2 = _matriz_beneficios;
    int _numero_objetos2 = _numero_objetos;
    int _capacidad_mochila2 = _capacidad_mochila;

    
    high_resolution_clock::time_point tantes , tdespues;
    vector<int> solucion;
   //Meter semilla 15

   //ALGORITMO GENERACIONAL***********************************************************************************************************************************
    if(argv[2]== string("1")){
        
        Random::seed(atoi(argv[3]));
        tantes = high_resolution_clock::now();
            solucion = aplicarAlgoritmo_AGG( _numero_objetos , _capacidad_mochila , _vector_beneficio , _vector_peso , _matriz_beneficios);
        tdespues = high_resolution_clock::now();
    }

    //ALGORITMO ESTACIONARIO***********************************************************************************************************************************
    if(argv[2] == string("2")){
        Random::seed(atoi(argv[3]));
        tantes = high_resolution_clock::now();
            solucion = aplicarAlgoritmo_AGE( _numero_objetos , _capacidad_mochila , _vector_beneficio , _vector_peso , _matriz_beneficios );
        tdespues = high_resolution_clock::now();
    }
    //ALGORITMO MEMETICO ALL****************************************************************************************************************************************

    if(argv[2] == string("3")){
        Random::seed(atoi(argv[3]));
        tantes = high_resolution_clock::now();
            solucion = aplicarAlgoritmo_AM_ALL( _numero_objetos , _capacidad_mochila , _vector_beneficio , _vector_peso , _matriz_beneficios);
        tdespues = high_resolution_clock::now();
    }

    //ALGORITMO MEMETICO RAND****************************************************************************************************************************************

    if(argv[2] == string("4")){
        Random::seed(atoi(argv[3]));
        tantes = high_resolution_clock::now();
            solucion = aplicarAlgoritmo_AM_RAND( _numero_objetos , _capacidad_mochila , _vector_beneficio , _vector_peso , _matriz_beneficios);
        tdespues = high_resolution_clock::now();
    }

    //ALGORITMO MEMETICO BEST****************************************************************************************************************************************

    if(argv[2] == string("5")){
        Random::seed(atoi(argv[3]));
        tantes = high_resolution_clock::now();
            solucion = aplicarAlgoritmo_AM_BEST( _numero_objetos , _capacidad_mochila , _vector_beneficio , _vector_peso , _matriz_beneficios);
        tdespues = high_resolution_clock::now();
    }

    //ALGORITMO GENERACIONAL PROPUESTO***********************************************************************************************************************************
    if(argv[2]== string("6")){
        Random::seed(atoi(argv[3]));
        tantes = high_resolution_clock::now();
            solucion = aplicarAlgoritmo_AGG_propuesto( _numero_objetos , _capacidad_mochila , _vector_beneficio , _vector_peso , _matriz_beneficios);
        tdespues = high_resolution_clock::now();
    }

    //ALGORITMO ESTACIONARIO PROPUESTO***********************************************************************************************************************************
    if(argv[2] == string("7")){
        Random::seed(atoi(argv[3]));
        tantes = high_resolution_clock::now();
            solucion = aplicarAlgoritmo_AGE_propuesto( _numero_objetos , _capacidad_mochila , _vector_beneficio , _vector_peso , _matriz_beneficios );
        tdespues = high_resolution_clock::now();
    }
    //***************************************************************************************************************************************************************
    
    
    duration<double> transcurrido = duration_cast<duration<double>>(tdespues - tantes);
    cout<<transcurrido.count()<<endl;

    
    for(int i = 0; i < solucion.size(); i++){
        cout<<solucion[i]<<" ";
    }
    cout<<endl;

    
    

    return 0;

}