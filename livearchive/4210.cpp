/*************************************************************************************************************************
 * 4210 - Almost Shortest Path
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=25&page=show_problem&problem=2211
 *
 * Classification: Graph
 *
 * Author:
 *   Edgardo Moreno     <egyware@gmail.com>
 *   Stephano Beneventi <stephano.bg@gmail.com>
 *   Kristoffer Ulloa	<rewpoke@gmail.com>
 *
 * Description:
 *   Este problema no es tan sencillo de resolver, dado un punto de partida y uno de llegada en un grafo.
 * se debe determinar el segundo camino mas corto, es decir, se deben elimnar todos los caminos de largo igual
 * al de camino mas corto, y luego se debe calcular el camino mas corto, y retornar su largo.
 * Primero se calcula dijkstra una vez, y se guarda una matriz con los pares que permiten caminos mas cortos
 * parciales, de este modo en que se guarda el resultado, se va haciendo backtracking, para eliminar del grafo
 * los caminos mas cortos, luego de esto calculamos una vez mas dijkstra para luego retornar su resultado.
 *
 */


#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

class grafo{
	public:

	int V;
	vii P;

	grafo(int v, grafo g){
		V=g.V;
		P = vii(g.V, vi(0));
	}

	grafo(int v){
		V=v;
		P = vii(V, vi(V, -1));
	}

	int dijkstra(int s, int t, grafo &GC);
	void imprimirGrafo();
	void elimina(grafo &GC, int t);

};

int grafo::dijkstra(int s,int t,grafo &GC){

	vector<int> lambda(V,-1);
	vector<bool> T(V,true);

   int u=-1,i,j,min=-1;
   lambda[s]=0;

   while(u!=t){
      for(i=0;i<V;i++){
         if(min==-1 && lambda[i]!=-1 && T[i]==true)min=i;
         if(lambda[i]<=lambda[min] && lambda[i]!=-1 && T[i]==true){
            min=i;
         }
      }
      u=min;
      if(u==-1)break;
      min=-1;

		for(i=0;i<V;i++){
			if(P[u][i]!=-1 && T[i]==true){
				if(lambda[i]==-1){
					lambda[i]=lambda[u]+P[u][i];
					GC.P[i].push_back(u);
				}
				else if(lambda[i]>lambda[u]+P[u][i]){
					lambda[i]=lambda[u]+P[u][i];
					GC.P[i].clear();
					GC.P[i].push_back(u);
				}
				else if(lambda[i]==lambda[u]+P[u][i]){
					GC.P[i].push_back(u);
				}
      	}
      }
      T[u]=false;
   }

   return lambda[t];

}

void grafo::imprimirGrafo(){
	int size;
	for(int i=0;i<V;i++){
		size=P[i].size();
		printf("%d",i);
		for (int j=0;j<size;j++){
			printf("[%d]",P[i][j]);
		}
		printf("\n");
	}
};

void grafo::elimina(grafo &GC, int f) {
	for (int i=0;i<GC.P[f].size();i++) {
		int u = GC.P[f][i];
		P[u][f] = -1;
		elimina(GC,u);
	}
}

int main() {
	int v,a;
	int s,t;
	int v1,v2,p;
	int i;

	while (1) {
		scanf("%d %d",&v,&a);

		if (v==0 && a==0)
			break;

		scanf("%d %d",&s,&t);

		grafo G1(v);

		for (i = 0; i < a; i++) {
			scanf("%d %d %d",&v1,&v2,&p);
			G1.P[v1][v2] = p;
		}

		grafo G2(v,G1);
		grafo G3(v,G1);

		G1.dijkstra(s,t,G2);

		G1.elimina(G2,t);

		printf("%d\n",G1.dijkstra(s,t,G3));

	}
}
