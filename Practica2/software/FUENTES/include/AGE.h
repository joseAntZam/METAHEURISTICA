#include <iostream>
#include <vector>
using namespace std;



vector<int> beneficiosPoblacion_AGE(vector<vector<int>> _poblacion, vector<int> _vector_beneficio, vector<vector<int>> _matriz_beneficios, vector<int>_vector_peso);

int PesoTotal_AGE(vector<int>_vector_peso, vector<int> _solucion);

int beneficioProducidoSolucion_AGE(vector<int> _vector_beneficio, vector<vector<int>> _matriz_beneficios, vector<int>_vector_peso, vector<int> _solucion);

vector<vector<int>> cruce_AGE(vector<int>&padre1 , vector<int>&padre2, int _capacidad_mochila ,  vector<int> _vector_peso );

bool esMejor_AGE(int indice_solucion, int indice_solucion1,  int indice_solucion2 ,vector<int> beneficios_poblacion);

vector<vector<int>> poblacionInicial_AGE(int _capacidad_mochila  , vector<int> _vector_peso);

void torneos_AGE(vector<vector<int>> &_poblacion, vector<int>beneficios_poblacion);

void mutacion_AGE(vector<vector<int>> &_poblacion, int _capacidad_mochila , vector<int> _vector_peso );

void reemplazo_AGE(vector<vector<int>> &_poblacionAux,vector<vector<int>> _poblacion, vector<pair<vector<int>,int>>datos );

vector<pair<vector<int>,int>> mejorSolucionNuevaPoblacion_AGE(vector<vector<int>> _poblacionAux,vector<vector<int>> _poblacion, vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios , vector<int>&beneficios_poblacion);

vector<int> aplicarAlgoritmo_AGE( int _numero_objetos , int _capacidad_mochila , vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios);

vector<vector<int>> cruce_AGE_propuesto(vector<int>&padre1 , vector<int>&padre2, int _capacidad_mochila ,  vector<int> _vector_peso );

vector<int> aplicarAlgoritmo_AGE_propuesto( int _numero_objetos , int _capacidad_mochila , vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios);