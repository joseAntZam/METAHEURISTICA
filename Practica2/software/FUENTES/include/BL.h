#include <iostream>
#include <vector>
using namespace std;


int PesoTotal_BL(vector<int>_vector_peso, vector<int> _solucion);

int beneficioProducidoSolucion_BL(vector<int> _vector_beneficio, vector<vector<int>> _matriz_beneficios, vector<int>_vector_peso, vector<int> _solucion);

vector<vector<int>> generarVecinos_BL(vector<int>solucion);

void busquedadLocal(vector<int> _vector_peso,  vector<int> _vector_beneficio ,  vector<vector<int>> _matriz_beneficios,int _capacidad_mochila, vector<vector<int>> &poblacion , int posicion_cromosoma, vector<int> &beneficio_poblacion, int &iteraciones, int iteraciones_globales);