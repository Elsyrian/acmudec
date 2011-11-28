/*************************************************************************************************************************
 * 2515 - Networking
 * http://livearchive.onlinejudge.org/external/25/2515.html
 *
 * Classification: Greedy
 *
 * Author:
 *   Javier Gonzalez Nova   <javigonzalez@udec.cl>
 *   
 * Description:
 *   Tenemos que conectar una serie de ciudades a traves de un cable, el objetivo es encontrar la menor distancia posible.
 *   El problema se puede interpretar como un grafo y debemos encontrar el MST(el arbol que conecta cada nodo del grafo, 
 *   con la menor suma posible de los pesos de cada nodo). Para calcular el MST, se usa el "Algoritmo de Prim".
 */

/* MST: Minimun Spanning Tree*/
#include <stdio.h>

int cantidad_puntos, cantidad_rutas;
int d[10000]; /*d[i] es la distancia entre el nodo i y el MST */
int whoTo[10000]; /*whoTo[i] es el nodo que conectado con i tiene una distancia d[i]*/
int weight[10000][10000]; /*weight[i][j] es la distancia entre el nodo i y el nodo j*/
char inTree[10000]; /*inTree[i] es 1 si el nodo i esta en el MST, 0 en otro caso*/

void updateDistances(int target) {
  int i;
  for(i = 0; i < cantidad_puntos; i++) {
    if((weight[target][i] != 0) && (d[i] > weight[target][i])) {
      d[i] = weight[target][i];
      whoTo[i] = target;
    }
  }
} 

int main(int argc, char* argv[]) {
  int i;
  int j, k, peso;
  int total, treeSize, min;

  while(1) {
    scanf("%d", &cantidad_puntos);
    if(cantidad_puntos == 0)
      break;

    scanf(" %d", &cantidad_rutas);

    for(i = 0; i < cantidad_rutas; i++) {
      for(j = 0; j < cantidad_rutas; j++) {
	weight[i][j] = 0;
      }
    }

    for(i = 0; i < cantidad_rutas; i++) {
      scanf("%d %d %d", &j, &k, &peso);
      k--;
      j--;
      if(weight[j][k] == 0) {
	weight[j][k] = weight[k][j] = peso;
      } else {
	if(weight[j][k] > peso)
	  weight[j][k] = weight[k][j] = peso;
      }
    }
 
    for(i = 0; i < cantidad_puntos; i++) {
      d[i] = 100000;
      inTree[i] = 0;
    }
   
    inTree[0] = 1;
    updateDistances(0);

    total = 0;
    for(treeSize = 1; treeSize < cantidad_puntos; treeSize++) {
      min = -1;
      for(i = 0; i < cantidad_puntos; i++) {
	if(!inTree[i])
	  if((min == -1) || (d[min] > d[i]))
	    min = i;
      }
      inTree[min] = 1;
      total += d[min];
      updateDistances(min);
    }
    
    printf("%d\n", total);
  }

  return 0;
}
