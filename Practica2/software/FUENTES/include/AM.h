#include <iostream>
#include <vector>
using namespace std;

int encontrarMejorSolucion_AMM(vector<int> _beneficios_poblacion , int posicion_excluida , double beneficio_ultima_solucion);


vector<int> aplicarAlgoritmo_AM_ALL( int _numero_objetos , int _capacidad_mochila , vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios);



vector<int> aplicarAlgoritmo_AM_RAND( int _numero_objetos , int _capacidad_mochila , vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios);



vector<int> aplicarAlgoritmo_AM_BEST( int _numero_objetos , int _capacidad_mochila , vector<int> _vector_beneficio , vector<int> _vector_peso , vector<vector<int>> _matriz_beneficios);
