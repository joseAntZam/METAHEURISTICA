#include <iostream>
#include <vector>
using namespace std;

void mutacion(vector<int> _vector_peso , vector<int> _vector_beneficio , vector<vector<int>> _matriz_beneficios, int _capacidad_mochila, vector<int> &solucion);
vector<int>ILS(vector<int> _vector_peso , vector<int> _vector_beneficio , vector<vector<int>> _matriz_beneficios, int _capacidad_mochila);
vector<int>ILSES(vector<int> _vector_peso , vector<int> _vector_beneficio , vector<vector<int>> _matriz_beneficios, int _capacidad_mochila);