/*************************************************************************************************************************
 * 820 - Internet Bandwidth
 * uva.onlinejudge.org/external/8/820.html
 *
 * Classification: Graph Theory, Max flow.
 *
 * Author:
 *   Javier Gonzalez <javigonzalez@udec.cl>
 */


/* Algoritmo Ford Fulkerson: El algortimo consiste en ejecutar busquedas por anchura (BFS) 
 * hasta que no se puede llegar al nodo destino. Luego de cada BFS se modifica el
 * valor de cada arista con la capacidad minima que se encontro en el camino de s a t. 
 * Cuando ya no se hayan mas formas de llegar a t,
 * el array cost contendra el flujo maximo que pasa desde s a cualquier nodo i.
*/

/*El programa se ejecuta en 0.04s, hagan eso en Java D:*/

#include <algorithm>
#include <queue>
#include <iostream>
#include <string.h>
#define N 100
#define oo 99999
using namespace std;

int prev[N+1];
int flow[N+1][N+1];
int minFlowNode[N+1];
bool visited[N+1];
int n;
int cost[N+1];

int bfs(int s, int t) {
  queue<int> Q;
  int mn = oo;

  Q.push(s);
  cost[s] = 9999;
  prev[s] = -1;
  
  while(!Q.empty()) {
    int tmp = Q.front();
    Q.pop();
    if(tmp == t)
      return cost[t];
    visited[tmp] = true;
    for(int i = 1; i <= n; i++) {
      if(flow[tmp][i] > 0 && !visited[i]) {
	Q.push(i);
	cost[i] = min(cost[tmp], flow[tmp][i]);
	prev[i] = tmp;
      }
    }
  }

  return 0;
}

int FordFulkerson(int s, int t) {
  int maxFlow = 0;
  while(1) {
    memset(visited, false, sizeof(visited));
    int tmp = bfs(s, t);
    if(tmp == 0)
      break;
    maxFlow += tmp;
    for(int v = t; prev[v] != -1; v = prev[v]) {
      flow[prev[v]][v] -= tmp;
      //flow[v][prev[v]] += tmp;
    }
  }

  return maxFlow;
}

int main(void) {
  int cases = 1;
  while(1) {
    cin >> n;
    if(n == 0)
      break;
    memset(flow, 0, sizeof(flow));
    int s, t, c;
    cin >> s >> t >> c;
    while(c--) {
      int tmp_s, tmp_t, tmp_capacity;
      cin >> tmp_s >> tmp_t >> tmp_capacity;
      flow[tmp_s][tmp_t] += tmp_capacity;
      flow[tmp_t][tmp_s] += tmp_capacity;
    }
    cout << "Network " << cases++ << endl;
    cout << "The bandwidth is " << FordFulkerson(s, t) << "." << endl;
    cout << endl;
  }
  return 0;
}
