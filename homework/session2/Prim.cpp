/* MST: Minimum Spanning Tree, Prim's Algorithm
 * Utilidad: Encuentra el camino mas corto, el cual pasa por todos los nodos de un grafo conectado con peso.
 */
/*Video explicativo: http://www.youtube.com/watch?v=BtGuZ-rrUeY*/
/*Ejercicio de ACM donde se puede aplicar: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=116&page=show_problem&problem=975*/
#include <iostream>
#include <string.h>
#define MAX_NODOS 100
using namespace std;

int numero_nodos;
int d[MAX_NODOS]; /*d[i] es la distancia entre el nodo i y el MST */
int weight[MAX_NODOS][MAX_NODOS]; /*weight[i][j] es la distancia entre el nodo i y el nodo j*/
char inTree[MAX_NODOS]; /*inTree[i] es 1 si el nodo i esta en el MST, 0 en otro caso*/
int total; /*Camino mas corto que pasa por todos los vertices*/

/*Prim's Algorithm: */
void updateDistances(int target) {
  int i;
  for(i = 0; i < numero_nodos; i++) {
    if((weight[target][i] != 0) && (d[i] > weight[target][i])) {
      d[i] = weight[target][i];
    }
  }
} 

void Prim() {
  int i;
  int j, k, peso;
  int treeSize, min;
 
  /*Inicializacion*/
  for(i = 0; i < numero_nodos; i++) {
    d[i] = 100000;
    inTree[i] = 0;
  }
  
  /*Comienzo del algoritmo de Prim, empezando por el nodo 0*/
  inTree[0] = 1;
  updateDistances(0);

  total = 0;
  /*Prim's Algorithm: */
  for(treeSize = 1; treeSize < numero_nodos; treeSize++) {
    min = -1;
    for(i = 0; i < numero_nodos; i++) {
      if(!inTree[i])
	if((min == -1) || (d[min] > d[i]))
	  min = i;
      }
    inTree[min] = 1;
    total += d[min];
    updateDistances(min);
  }
}

int main(int argc, char* argv[]) {
  /*Example run: http://en.wikipedia.org/wiki/Prim%27s_algorithm */
  memset(weight, 0, sizeof(weight)); /*Le asigno 0 a todos los valores del array weight*/
  /*Completo con los datos del ejemplo, en este caso A = 0, B = 1, ..., G = 6 los nodos*/
  /*El grafo es no dirigido*/
  numero_nodos = 7;
  weight[0][1] = weight[1][0] = 7; /*A->B, B->A*/
  weight[0][3] = weight[3][0] = 5; /*A->D, D->A*/
  weight[1][2] = weight[2][1] = 8; /*B->C, C->B*/
  weight[1][3] = weight[3][1] = 9; /*B->D, D->B*/
  weight[1][4] = weight[4][1] = 7; /*B->E, E->B*/
  weight[2][4] = weight[4][2] = 5; /*C->E, E->C*/
  weight[3][4] = weight[4][3] = 15;/*D->E, E->D*/
  weight[3][5] = weight[5][3] = 6; /*D->F, F->D*/
  weight[4][5] = weight[5][4] = 8; /*E->F, F->E*/
  weight[4][6] = weight[6][4] = 9; /*E->G, G->E*/
  weight[5][6] = weight[6][5] = 11;/*F->G, G->F*/
  
  Prim();
  
  /*Distancia minima*/
  cout << total << endl;

  return 0;
}
