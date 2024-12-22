#include <iostream>
#include <vector>
using namespace std;



vector<vector<int>> generarVecinos(vector<int>solucion);
vector<int> generarSolucionAleatoria(vector<int> _vector_peso, int _capacidad_mochila);
int beneficioProducidoSolucion(vector<int> _vector_beneficio, vector<vector<int>> _matriz_beneficios, vector<int>_vector_peso, vector<int> _solucion);
int PesoTotal(vector<int>_vector_peso, vector<int> _solucion);
int beneficioProducidoSolucion_Factorizado(vector<int> _vector_beneficio, vector<vector<int>> _matriz_beneficios, vector<int>_vector_peso, int eliminado ,int  asignado, int beneficio, vector<int> _solucion);
int PesoTotal_Factorizado(vector<int>_vector_peso,  int eliminado ,int  asignado, int peso );
