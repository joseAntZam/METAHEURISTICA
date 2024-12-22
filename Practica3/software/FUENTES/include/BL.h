#include <iostream>
#include <vector>
using namespace std;





void busquedadLocal(vector<int> _vector_peso,  vector<int> _vector_beneficio ,  vector<vector<int>> _matriz_beneficios,int _capacidad_mochila, vector<int>& Solucion, int& beneficio);


vector<int> busquedadLocalP1(vector<int> _vector_peso,  vector<int> _vector_beneficio ,  vector<vector<int>> _matriz_beneficios,int _capacidad_mochila, int& beneficio);