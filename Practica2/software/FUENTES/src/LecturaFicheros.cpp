
//lectura de un fichero
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <chrono>
#include <ctime>
#include "random.hpp"
#include "LecturaFicheros.h"

using namespace std;
using Random = effolkronium::random_static;
using namespace std;
using namespace std::chrono;



void leerFichero(const char *_archivo , int &_numero_objetos , int &_capacidad_mochila , vector<int> &_vector_beneficio , vector<int> &_vector_peso , vector<vector<int>> &_matriz_beneficios){

    ifstream archivo;
    string linea;
    int elemento_matriz = 0;
    int elemento_vector = 0;
    int elemento_vector_peso = 0;
    int contador_filas_matriz = 0;
    int contador_elementos_vector_aux = 10;
    
    
    //Abre el fichero****************************************************************************************************************************************************************************
    archivo.open(_archivo);
    if (archivo.fail())
    {
        cout << "No se puede abrir el archivo";
        exit(1);                 //sale del programa                    
    }

    //Ignora nombre del fichero*********************************************************************************************************************************************************
    getline(archivo, linea);

    //Obtine el numero de objetos*******************************************************************************************************************************************************
    getline(archivo, linea);
    _numero_objetos = atoi(linea.c_str());
    
    //Obtine el vector de beneficios individuales***************************************************************************************************************************************
    getline(archivo, linea);
    string elemento_vector_str = ""; //Almacena elementos de la linea actual
        for(int i = 0; i <= linea.length(); i++){
           
            if( linea[i] == ' '  || i == linea.length() ){
                if(elemento_vector_str != ""){
               elemento_vector = atoi(elemento_vector_str.c_str());
               elemento_vector_str = "";
               _vector_beneficio.push_back(elemento_vector);
                }
            }
            else{
                elemento_vector_str += linea[i];
            }

        }
    //Obtiene la matriz de beneficios a pares*******************************************************************************************************************************************

    int contador_ceros = 1;
    while(getline(archivo, linea) && contador_filas_matriz < _numero_objetos-1){

      
        string elemento_matriz_str;
        vector<int>almacen_aux;
    
        for (int i = 0 ; i < contador_ceros; i++){ //Incluye los ceros necesarios para poder trabajar con la matriz.
            almacen_aux.push_back(0);
        }
        contador_ceros++;
    
        for(int i = 0; i <= linea.length(); i++){

            
            if((linea[i] == ' '  || i == linea.length())){
                if(elemento_matriz_str != ""){
                    elemento_matriz = atoi(elemento_matriz_str.c_str());
                    elemento_matriz_str = "";
                    almacen_aux.push_back(elemento_matriz);
                }
                if( i==linea.length() ){
                    _matriz_beneficios.push_back(almacen_aux);
                    contador_filas_matriz++;
                }
            }

            else{
                elemento_matriz_str += linea[i];
            }  

        }
        
        
    }
    vector<int>almacen_aux_ceros; //Almacenamos la ultima fila de la matriz de beneficios, con 0.
    for ( int i = 0; i < _numero_objetos ; i++){
        almacen_aux_ceros.push_back(0);
    }
    _matriz_beneficios.push_back(almacen_aux_ceros);

    //Ignora el cero******************************************************************************************************************************************************************
    getline(archivo, linea);

    //Obtiene la capacidad de la mochila***********************************************************************************************************************************************
    getline(archivo, linea);
    _capacidad_mochila = atoi(linea.c_str());

    //Obtiene el vector de pesos de los objetos****************************************************************************************************************************************
    getline(archivo, linea);
    string elemento_vector_peso_str;
        for(int i = 0; i <= linea.length(); i++){
           
            if(linea[i] == ' '  || i == linea.length()){
                if(elemento_vector_peso_str != ""){
                    elemento_vector_peso = atoi(elemento_vector_peso_str.c_str());
                    elemento_vector_peso_str = "";
                    _vector_peso.push_back(elemento_vector_peso);
                }
            }
            else{
                elemento_vector_peso_str += linea[i];
            }

        }
    archivo.close();

}