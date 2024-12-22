#include <iostream>
#include <vector>
using namespace std;


vector<int> beneficiosPoblacion_AGG(vector<vector<int>> _poblacion, vector<int> _vector_beneficio, vector<vector<int>> _matriz_beneficios, vector<int>_vector_peso);

int encontrarMejorSolucion_AGG(vector<int> _beneficios_poblacion);

int PesoTotal_AGG(vector<int>_vector_peso, vector<int> _solucion);

int beneficioProducidoSolucion_AGG(vector<int> _vector_beneficio, vector<vector<int>> _matriz_beneficios, vector<int>_vector_peso, vector<int> _solucion);

bool esMejor_AGG(int indice_solucion, int indice_solucion1,  int indice_solucion2 ,vector<int> beneficios_poblacion);

vector<vector<int>> poblacionInicial_AGG( int _capacidad_mochila  , vector<int> _vector_peso );

bool torneos_AGG(vector<vector<int>> &_poblacion, int posicion_mejor_solucion, vector<int> &beneficios_poblacion);

void cruces_AGG(vector<vector<int>> &_poblacion, int _capacidad_mochila , vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios, vector<int> &beneficios_poblacion);
vector<vector<int>> cruce_AGG(vector<int> &padre1 ,int indiceP1, vector<int> &padre2,int indiceP2, int _capacidad_mochila , vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios, vector<int> &beneficios_poblacion);

void mutacion_AGG(vector<vector<int>> &_poblacion , int _capacidad_mochila , vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios , vector<int> &beneficios_poblacion);

void reemplazo_AGG(vector<vector<int>> _poblacionAux,vector<vector<int>> &_poblacion , vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios, int posicion_mejor_solucion, vector<int> &beneficios_poblacion);

bool mejorSolucionNuevaPoblacion_AGG(vector<vector<int>> _poblacionAux,vector<vector<int>> _poblacion  , vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios, int posicion_mejor_solucion, vector<int> beneficios_poblacion);

vector<int> aplicarAlgoritmo_AGG( int _numero_objetos , int _capacidad_mochila , vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios);


void cruces_AGG_propuesto(vector<vector<int>> &_poblacion, int _capacidad_mochila , vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios, vector<int> &beneficios_poblacion);

vector<vector<int>> cruce_AGG_propuesto(vector<int> &padre1 ,int indiceP1, vector<int> &padre2,int indiceP2, int _capacidad_mochila , vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios, vector<int> &beneficios_poblacion);


vector<int> aplicarAlgoritmo_AGG_propuesto( int _numero_objetos , int _capacidad_mochila , vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios);