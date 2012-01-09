/*************************************************
 * Depth First Search recursivo (DFS)            *
 * Complejidad: O(V+E)                           *
 * 	V: Nº Vertices, E: Nº Aristas            *
 * Utilidad: Recorre todos los nodos de un grafo.*
 * Almacenamiento: Vector                        *
 * Uso de memoria = 2E si el grado es no dirigido*
 *************************************************/

#include <iostream>
#include <vector>
using namespace std;

vector<int> G[100];
bool visited[100];

/*Algoritmo DFS*/
void dfs(int v) {
  visited[v] = true;
  cout << v << " ";
  for(int u = 0; u < G[v].size(); u++) {
    if(!visited[G[v][u]])
      dfs(G[v][u]);
  }
}
/*Fin algoritmo DFS*/

int main(void) {
  int R, C, Q;

  for(int i = 0; i < 100; i++) {
    G[i].clear();
    visited[i] = false;
  }
  
  while(1) {
    cin >> R >> C >> Q;
    if(R == 0 && C == 0 && Q == 0)
      break;

    for(int i = 0; i < C; i++) {
      int a, b;
      cin >> a >> b;
      G[a].push_back(b);
      G[b].push_back(a);
    }

    dfs(0);
    cout << endl;
  }

  return 0;
}

