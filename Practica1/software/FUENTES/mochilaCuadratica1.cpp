//lectura de un fichero
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <chrono>
#include <ctime>
#include "random.hpp"

using namespace std;
using Random = effolkronium::random_static;
using namespace std;
using namespace std::chrono;

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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool esMejor(vector<int> _solucion, vector<int> _solucion_mejor, vector<int> _vector_peso,  vector<int> _vector_beneficio ,  vector<vector<int>> _matriz_beneficios , int _capacidad_mochila){

    int beneficio_solucion = beneficioProducidoSolucion(_vector_beneficio,_matriz_beneficios,_vector_peso,_solucion);
    int beneficio_mejor_solucion = beneficioProducidoSolucion(_vector_beneficio,_matriz_beneficios,_vector_peso,_solucion_mejor);

    if(beneficio_mejor_solucion > beneficio_solucion){
        return true;
    }
    else{
        return false;
    }
    
    
}

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


vector<int> busquedadLocal(vector<int> _vector_peso,  vector<int> _vector_beneficio ,  vector<vector<int>> _matriz_beneficios,int _capacidad_mochila){

    vector<int> solucion = generarSolucionAleatoria(_vector_peso,_capacidad_mochila);  //Genera una solucion aleatoria

    int contadorIteraciones = 0;
    int contadorVecinosExplorar = 0;
    bool posible_vecino = true;
    vector<vector<int>>vecinos;

    
    while(contadorIteraciones < 90000 && posible_vecino){
        
        int espacio_disponible = _capacidad_mochila;
        vector<int>solucionCandidata = solucion;

        if(contadorVecinosExplorar == 0){
            vecinos = generarVecinos(solucionCandidata);
            Random::shuffle(vecinos);
        }

        solucionCandidata[vecinos[contadorVecinosExplorar][0]] = 0;
        solucionCandidata[vecinos[contadorVecinosExplorar][1]] = 1;

        for(int i = 0 ; i < solucionCandidata.size() ; i++){
            if(solucionCandidata[i] == 1){
                espacio_disponible -= _vector_peso[i];
            }
            
        }

        if(esMejor(solucion,solucionCandidata,_vector_beneficio,_vector_peso,_matriz_beneficios,_capacidad_mochila) && espacio_disponible >= 0){
            solucion = solucionCandidata;
            contadorIteraciones = 0;
            contadorVecinosExplorar = 0;
        }
        
        else if (contadorVecinosExplorar == vecinos.size() -1 ){
            posible_vecino = false;
            
        }
        else{
            contadorIteraciones++;
            contadorVecinosExplorar++;
        }

    }
   
  // beneficio_total =beneficioProducidoSolucion(_vector_beneficio,_matriz_beneficios,_vector_peso,solucion);
   //cout<<beneficio_total<<endl;
   return solucion;

}


   



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//


vector<int> Greedy( int _numero_objetos , int _capacidad_mochila, vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios){

    vector<int> solucion = vector<int>(_vector_peso.size(),0);
    int espacio_disponible = _capacidad_mochila;
    int contador_disponibles = _vector_peso.size();
    vector<int>posibles = vector<int>(_vector_peso.size(),1); //vector de posibles


    int beneficio_mayor = 0;
    int indice_beneficio_mayor = -1;
    bool existe_objeto = false;

    int beneficio_total = 0;

    for ( int i = 0 ; i< _vector_beneficio.size() ; i++){

            if(posibles[i] == 1){

                float beneficio_mayor_actual = _vector_beneficio[i]/_vector_peso[i];

                if(beneficio_mayor_actual >= beneficio_mayor && _vector_peso[i] <= espacio_disponible ){
                    beneficio_mayor = beneficio_mayor_actual;
                    indice_beneficio_mayor = i;
                    existe_objeto = true;
                }
                
            }

        }

    if(existe_objeto){
        contador_disponibles--;
        solucion[indice_beneficio_mayor] = 1;
        posibles[indice_beneficio_mayor] = 0;
        espacio_disponible -= _vector_peso[indice_beneficio_mayor];
    }

    while(contador_disponibles != 0 ){
        

        float mayor_valor_potencial = 0.0;
        int indice_mayor_valor_potencial = -1;

            for(int i = 0 ; i<_vector_peso.size() ; i++){
            
                if(_vector_peso[i] > espacio_disponible && posibles[i] == 1){
                    posibles[i] = 0;
                    contador_disponibles--;
                } 
            
            }
            
            if(contador_disponibles != 0){

                    float _valor_potencial = 0.0;

                    for ( int i  = 0 ; i < _vector_peso.size() ; i++){

                        if(posibles[i] == 1){
                            _valor_potencial = _vector_beneficio[i];
                        
                            for ( int j = 0 ; j < _vector_peso.size() ; j++){

                                if( solucion[j] == 1){

                                    if(i<j){
                                        _valor_potencial += _matriz_beneficios[i][j];
                                    }

                                    if(i>j){
                                        _valor_potencial += _matriz_beneficios[j][i];
                                    }

                                }
                            }

                            
                            _valor_potencial = _valor_potencial / _vector_peso[i];
                            if(_valor_potencial > mayor_valor_potencial){
                                mayor_valor_potencial = _valor_potencial;
                                indice_mayor_valor_potencial = i;
                            }

                        }
                        
                            
                    }

                    contador_disponibles--;
                    solucion[indice_mayor_valor_potencial] = 1;
                    posibles[indice_mayor_valor_potencial] = 0;
                    espacio_disponible -= _vector_peso[indice_mayor_valor_potencial];
            }

    }

    //beneficio_total = beneficioProducidoSolucion(_vector_beneficio,_matriz_beneficios,_vector_peso,solucion);
    //cout<<beneficio_total<<endl;

   return solucion;
   
}


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

int main ( int argc, char *argv[] )
{   
    vector<int>vector_beneficio;
    vector<vector<int>>matriz_beneficios;
    vector<int>vector_peso;
    int numero_objetos = 0;
    int capacidad_mochila = 0;

    int beneficio_total = 0;

    if( argc != 4 ){
        cout<<"No se han introducido los argumentos necesarios"<<endl;
        exit(1);                 //sale del programa                    
    }
    if ( atoi(argv[2]) != 1 && atoi(argv[2]) != 2 ){
        cout<<"No se han introducido los valores correctos para el algoritmo : Greedy (1) o Busqueda Local (2)"<<endl;
        exit(1);                 //sale del programa
    }
    
    Random::seed(atoi(argv[3]));

    leerFichero(argv[1],numero_objetos,capacidad_mochila,vector_beneficio,vector_peso,matriz_beneficios);
    vector<int>solucion;
    int espacio_ocupado = 0;
    
    high_resolution_clock::time_point tantes , tdespues;

    if(argv[2] == string("1")){
        tantes = high_resolution_clock::now();
        solucion = Greedy(numero_objetos,capacidad_mochila,vector_beneficio,vector_peso,matriz_beneficios);
        tdespues = high_resolution_clock::now();
    }
    else if (argv[2] == string("2")){
        tantes = high_resolution_clock::now();
        solucion =busquedadLocal(vector_peso, vector_beneficio , matriz_beneficios,capacidad_mochila);
        tdespues = high_resolution_clock::now();
    }


    duration<double> transcurrido = duration_cast<duration<double>>(tdespues - tantes);
    beneficio_total = beneficioProducidoSolucion(vector_beneficio, matriz_beneficios, vector_peso, solucion);
    cout<<"Beneficio total: "<<beneficio_total<<endl;
    cout<<"Tiempo transcurrido: "<<transcurrido.count()<<endl;

    cout<<endl;
    cout<<"Solucion: "<<endl;
   
    for(int i = 0; i < solucion.size(); i++){
        cout << solucion[i] << " ";
        if(solucion[i] == 1){
            espacio_ocupado += vector_peso[i];
        }
    }

    cout<<endl;
    /*
    cout<<endl;
    cout<<"Espacio ocupado: "<<espacio_ocupado<<endl;
    cout<<endl;
    */

    return 0;                    //sale del programa                                
}