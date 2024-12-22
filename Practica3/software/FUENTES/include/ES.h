#include <iostream>
#include <vector>
using namespace std;



double Cauchy(double tkmenos1, double temperaturaInicial,int temperaturaFinal, int MaxVecinos, int iteraciones);

vector<int>ES(vector<int> _vector_peso , vector<int> _vector_beneficio , vector<vector<int>> _matriz_beneficios, int _capacidad_mochila);
void ES(vector<int> _vector_peso , vector<int> _vector_beneficio , vector<vector<int>> _matriz_beneficios, int _capacidad_mochila,vector<int>& solucion_inicial, int& beneficio_resultado );