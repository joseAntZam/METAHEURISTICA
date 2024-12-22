

//lectura de un fichero
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <chrono>
#include <ctime>
#include "random.hpp"
#include "AGE.h"
#include "LecturaFicheros.h"
#include <algorithm>

using namespace std;
using Random = effolkronium::random_static;
using namespace std;
using namespace std::chrono;

//CRUCE_2PUNTOS************************************************************************************************************************************************************************************

vector<int> beneficiosPoblacion_AGE(vector<vector<int>> _poblacion, vector<int> _vector_beneficio, vector<vector<int>> _matriz_beneficios, vector<int>_vector_peso){

	vector<int>beneficios_poblacion;
	for(int i = 0 ; i < _poblacion.size() ; i++){
    	int benefico = beneficioProducidoSolucion_AGE(_vector_beneficio,_matriz_beneficios,_vector_peso,_poblacion[i]);
    	beneficios_poblacion.push_back(benefico);
	}
	return beneficios_poblacion;
}

int PesoTotal_AGE(vector<int>_vector_peso, vector<int> _solucion){
	int peso = 0;
	for(int i = 0 ; i < _solucion.size() ; i++){
    	if(_solucion[i] == 1){
        	peso += _vector_peso[i];
    	}
	}
	return peso;
}

int beneficioProducidoSolucion_AGE(vector<int> _vector_beneficio, vector<vector<int>> _matriz_beneficios, vector<int>_vector_peso, vector<int> _solucion){

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

vector<vector<int>> cruce_AGE(vector<int>&padre1 , vector<int>&padre2, int _capacidad_mochila ,  vector<int> _vector_peso ){

   int elementoAleatorio = 0;
	int elementoAleatorio1 = 0;
	int mayor = 0;
	int menor = 0;

    
	while(elementoAleatorio == elementoAleatorio1){
    	elementoAleatorio = Random::get(0,int(padre1.size()-1));
    	elementoAleatorio1 = Random::get(0,int(padre1.size()-1));
	}
    

	if(elementoAleatorio > elementoAleatorio1){
    	mayor = elementoAleatorio;
    	menor = elementoAleatorio1;
	}

   
	if(elementoAleatorio1 > elementoAleatorio){
    	mayor = elementoAleatorio1;
    	menor = elementoAleatorio;

	}
    
   
	for(int i = menor; i <= mayor; i++){
    	swap(padre1[i],padre2[i]);
	}

   
    
	while(PesoTotal_AGE(_vector_peso, padre1) > _capacidad_mochila ){

    	int elementoEliminar = Random::get(0,int(padre1.size()-1));
    	padre1[elementoEliminar] = 0;
	}

    
	while(PesoTotal_AGE(_vector_peso,padre2) > _capacidad_mochila){

    	int elementoEliminar = Random::get(0,int(padre1.size()-1));
    	padre2[elementoEliminar] = 0;
	}

    
	return {padre1,padre2};

}

bool esMejor_AGE(int indice_solucion, int indice_solucion1,  int indice_solucion2 ,vector<int> beneficios_poblacion){

	int beneficio_solucion = beneficios_poblacion[indice_solucion];
	int beneficio_solucion1 = beneficios_poblacion[indice_solucion1];
	int beneficio_solucion2 = beneficios_poblacion[indice_solucion2];

	if(beneficio_solucion >= beneficio_solucion1 && beneficio_solucion >= beneficio_solucion2){
    	return true;
	}
	else{
    	return false;
	}
    
    
}

vector<vector<int>> poblacionInicial_AGE(int _capacidad_mochila  , vector<int> _vector_peso){

    	int i = 0;
    	vector<vector<int>> poblacion;
    	int beneficio_mejor = 0;

    	while(i<50){

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

            	poblacion.push_back(solucion);
            	i++;

    	}
    	return poblacion;

}

void torneos_AGE(vector<vector<int>> &_poblacion, vector<int>beneficios_poblacion){
    	int i = 0;
    	vector<vector<int>> _poblacionAux;

    	while(i<2){
        	int elementoAleatorio = Random::get(0,int(_poblacion.size()-1));
        	int elementoAleatorio1 = Random::get(0,int(_poblacion.size()-1));
        	int elementoAleatorio2 = Random::get(0,int(_poblacion.size()-1));

        	if(elementoAleatorio != elementoAleatorio1 && elementoAleatorio != elementoAleatorio2 && elementoAleatorio1 != elementoAleatorio2){

            	if(esMejor_AGE(elementoAleatorio,elementoAleatorio1,elementoAleatorio2,beneficios_poblacion)){
                	_poblacionAux.push_back(_poblacion[elementoAleatorio]);


            	}
            	else if(esMejor_AGE(elementoAleatorio1,elementoAleatorio,elementoAleatorio2,beneficios_poblacion)){
                	_poblacionAux.push_back(_poblacion[elementoAleatorio1]);

            	}
            	else if(esMejor_AGE(elementoAleatorio2,elementoAleatorio1,elementoAleatorio,beneficios_poblacion)){
                	_poblacionAux.push_back(_poblacion[elementoAleatorio2]);

            	 
            	}
            	i++;
        	}
    	}

    	_poblacion = _poblacionAux;

}  

void mutacion_AGE(vector<vector<int>> &_poblacion, int _capacidad_mochila , vector<int> _vector_peso ){

	int cromosomas = _poblacion.size();
 	int numero_mutaciones = cromosomas*0.08;

	int dado1 = Random::get(0,1);
	int dado2 = Random::get(0,1);

    	if(dado1 < 0.08){
       	 
        	vector<int> mutacion_producida = _poblacion[0];
        	bool encontrado = false;
        	vector<int> mutacion_aux = mutacion_producida;

        	while(!encontrado){
           	 
            	int elementoAleatorio = Random::get(0,int(_vector_peso.size()-1));

            	if(mutacion_producida[elementoAleatorio] == 0){
                	mutacion_producida[elementoAleatorio] = 1;
            	}
            	else{
                	mutacion_producida[elementoAleatorio] = 0;
            	}

            	if(PesoTotal_AGE(_vector_peso,mutacion_producida) <= _capacidad_mochila){
                	_poblacion[0] = mutacion_producida;
                	encontrado = true;
                	//i++;
            	}
            	else{
                	mutacion_producida = mutacion_aux;
            	}

        	}
    	}
    	if(dado2 < 0.08){
       	 
        	vector<int> mutacion_producida = _poblacion[1];
        	bool encontrado = false;
        	vector<int> mutacion_aux = mutacion_producida;

        	while(!encontrado){
           	 
            	int elementoAleatorio = Random::get(0,int(_vector_peso.size()-1));

            	if(mutacion_producida[elementoAleatorio] == 0){
                	mutacion_producida[elementoAleatorio] = 1;
            	}
            	else{
                	mutacion_producida[elementoAleatorio] = 0;
            	}

            	if(PesoTotal_AGE(_vector_peso,mutacion_producida) <= _capacidad_mochila){
                	_poblacion[1] = mutacion_producida;
                	encontrado = true;
                	//i++;
            	}
            	else{
                	mutacion_producida = mutacion_aux;
            	}

        	}
    	}
	}

void reemplazo_AGE(vector<vector<int>> &_poblacionAux,vector<vector<int>> _poblacion, vector<pair<vector<int>,int>>datos ){
    
   	_poblacionAux[datos[0].second] = datos[0].first;
   	_poblacionAux[datos[1].second] = datos[1].first;
  	 
}

vector<pair<vector<int>,int>> mejorSolucionNuevaPoblacion_AGE(vector<vector<int>> _poblacionAux,vector<vector<int>> _poblacion, vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios , vector<int>&beneficios_poblacion){

    	vector<int>aux;
    	vector<pair<vector<int>,int>> vecSol;

    	int posicion_peor_solucion = -1;
    	int posicion_segunda_peor_solucion = -1;

    	int peor_solucion = 9999999;
    	int segunda_peor_solucion = 9999999;

    	for ( int i = 0 ; i<_poblacionAux.size() ; i++){
        	int beneficio = beneficios_poblacion[i];
        	if(beneficio < peor_solucion){
            	peor_solucion = beneficio;
            	posicion_peor_solucion = i;
        	}
    	}

   	 
    	for (int i = 0 ; i<_poblacionAux.size() ; i++){
        	int beneficio = beneficios_poblacion[i];
        	if(beneficio >= peor_solucion && beneficio < segunda_peor_solucion && i != posicion_peor_solucion){
            	segunda_peor_solucion = beneficio;
            	posicion_segunda_peor_solucion = i;
        	}
    	}

   
	int beneficioMejorSolucionAntigua1 = beneficios_poblacion[posicion_peor_solucion];
	int beneficioMejorSolucionAntigua2 = beneficios_poblacion[posicion_segunda_peor_solucion];
	int beneficioNuevaPoblacion1 = beneficioProducidoSolucion_AGE(_vector_beneficio,_matriz_beneficios,_vector_peso,_poblacion[0]);
	int beneficioNuevaPoblacion2 = beneficioProducidoSolucion_AGE(_vector_beneficio,_matriz_beneficios,_vector_peso,_poblacion[1]);

	aux.push_back(beneficioMejorSolucionAntigua1);
	aux.push_back(beneficioMejorSolucionAntigua2);
	aux.push_back(beneficioNuevaPoblacion1);
	aux.push_back(beneficioNuevaPoblacion2);
	//ordenamos el vector auxiliar
	sort(aux.begin(),aux.end(),std::greater<int>());
	//bools para saber si ya hemos encontrado la solucion
	bool encontradoSA1 = false , encontradoSA2 = false , encontradoNP1 = false , encontradoNP2 = false;

    
	if(aux[0] == beneficioMejorSolucionAntigua1){
    	vecSol.push_back({_poblacionAux[posicion_peor_solucion],posicion_peor_solucion});
    	encontradoSA1 = true;
    	beneficios_poblacion[posicion_peor_solucion] = beneficioMejorSolucionAntigua1;
	}
	else if(aux[0] == beneficioMejorSolucionAntigua2){
    	vecSol.push_back({_poblacionAux[posicion_segunda_peor_solucion],posicion_peor_solucion});
    	encontradoSA2 = true;
    	beneficios_poblacion[posicion_peor_solucion] = beneficioMejorSolucionAntigua2;
	}
	else if(aux[0] == beneficioNuevaPoblacion1){
    	vecSol.push_back({_poblacion[0],posicion_peor_solucion});
    	encontradoNP1 = true;
    	beneficios_poblacion[posicion_peor_solucion] = beneficioNuevaPoblacion1;
	}
	else if(aux[0] == beneficioNuevaPoblacion2){
    	vecSol.push_back({_poblacion[1],posicion_peor_solucion});
    	encontradoNP2 = true;
    	beneficios_poblacion[posicion_peor_solucion] = beneficioNuevaPoblacion2;

	}

	//****************************************************************************

	if(aux[1] == beneficioMejorSolucionAntigua1 && !encontradoSA1){
    	vecSol.push_back({_poblacionAux[posicion_peor_solucion],posicion_segunda_peor_solucion});
    	beneficios_poblacion[posicion_segunda_peor_solucion] = beneficioMejorSolucionAntigua1;
	}
	else if(aux[1] == beneficioMejorSolucionAntigua2 && !encontradoSA2){
    	vecSol.push_back({_poblacionAux[posicion_segunda_peor_solucion],posicion_segunda_peor_solucion});
    	beneficios_poblacion[posicion_segunda_peor_solucion] = beneficioMejorSolucionAntigua2;
	}
	else if(aux[1] == beneficioNuevaPoblacion1 && !encontradoNP1){
    	vecSol.push_back({_poblacion[0],posicion_segunda_peor_solucion});
    	beneficios_poblacion[posicion_segunda_peor_solucion] = beneficioNuevaPoblacion1;
	}
	else if(aux[1] == beneficioNuevaPoblacion2 && !encontradoNP2){
    	vecSol.push_back({_poblacion[1],posicion_segunda_peor_solucion});
    	beneficios_poblacion[posicion_segunda_peor_solucion] = beneficioNuevaPoblacion2;
	}

    

	return vecSol;
}

vector<int> aplicarAlgoritmo_AGE( int _numero_objetos , int _capacidad_mochila , vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios){

vector<vector<int>>poblacion = poblacionInicial_AGE(_capacidad_mochila,_vector_peso);
vector<vector<int>>poblacionAux = poblacion;

vector<int>beneficios_poblacion = beneficiosPoblacion_AGE(poblacion,_vector_beneficio,_matriz_beneficios,_vector_peso);

int iteraciones = 0;
while(iteraciones < 90000){
    	torneos_AGE(poblacion,beneficios_poblacion);
    	cruce_AGE(poblacion[0],poblacion[1],_capacidad_mochila,_vector_peso);
    	mutacion_AGE(poblacion,_capacidad_mochila,_vector_peso);
    	vector<pair<vector<int>,int>>vecSol = mejorSolucionNuevaPoblacion_AGE(poblacionAux,poblacion,_vector_beneficio,_vector_peso,_matriz_beneficios,beneficios_poblacion);
    	reemplazo_AGE(poblacionAux,poblacion,vecSol);
    	poblacion = poblacionAux;
   	 
    	iteraciones+=2;
    
    	}
	

	int beneficio = 0;
	vector<int> mejorSolucion ;
	for(int i = 0 ; i < poblacion.size() ; i++){
    	int beneficio_producido = beneficios_poblacion[i];
    	if(beneficio_producido > beneficio){
        	beneficio = beneficio_producido;
			mejorSolucion = poblacion[i];
    	}

	}
	cout<<beneficio<<endl;
	return mejorSolucion;
   	 


}



//CRUCE_PROPUESTO************************************************************************************************************************************************************************************

vector<vector<int>> cruce_AGE_propuesto(vector<int>&padre1 , vector<int>&padre2, int _capacidad_mochila ,  vector<int> _vector_peso ){

    int probabilidad = 5;
    int i = 0;
    while(i<padre1.size()){
        
        int elementoAleatorio = Random::get(1,10);

        if(elementoAleatorio <= probabilidad){
            swap(padre1[i],padre2[i]);
        }

        i++;
    }

   
    
	while(PesoTotal_AGE(_vector_peso, padre1) > _capacidad_mochila ){

    	int elementoEliminar = Random::get(0,int(padre1.size()-1));
    	padre1[elementoEliminar] = 0;
	}

    
	while(PesoTotal_AGE(_vector_peso,padre2) > _capacidad_mochila){

    	int elementoEliminar = Random::get(0,int(padre1.size()-1));
    	padre2[elementoEliminar] = 0;
	}

    
	return {padre1,padre2};

}

vector<int> aplicarAlgoritmo_AGE_propuesto( int _numero_objetos , int _capacidad_mochila , vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios){

vector<vector<int>>poblacion = poblacionInicial_AGE(_capacidad_mochila,_vector_peso);
vector<vector<int>>poblacionAux = poblacion;

vector<int>beneficios_poblacion = beneficiosPoblacion_AGE(poblacion,_vector_beneficio,_matriz_beneficios,_vector_peso);

int iteraciones = 0;
while(iteraciones < 90000){
    	torneos_AGE(poblacion,beneficios_poblacion);
    	cruce_AGE_propuesto(poblacion[0],poblacion[1],_capacidad_mochila,_vector_peso);
    	mutacion_AGE(poblacion,_capacidad_mochila,_vector_peso);
    	vector<pair<vector<int>,int>>vecSol = mejorSolucionNuevaPoblacion_AGE(poblacionAux,poblacion,_vector_beneficio,_vector_peso,_matriz_beneficios,beneficios_poblacion);
    	reemplazo_AGE(poblacionAux,poblacion,vecSol);
    	poblacion = poblacionAux;
   	 
    	iteraciones+=2;
    
    	}
	

	int beneficio = 0;
	vector<int> mejorSolucion ;
	for(int i = 0 ; i < poblacion.size() ; i++){
    	int beneficio_producido = beneficios_poblacion[i];
    	if(beneficio_producido > beneficio){
        	beneficio = beneficio_producido;
			mejorSolucion = poblacion[i];
    	}

	}
	cout<<beneficio<<endl;
	return mejorSolucion;
   	 


}