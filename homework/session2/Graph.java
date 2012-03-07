/**************************************************
 *
 * Grafo implementado usando vector de adyacencia.
 * Contiene el método Dijkstra que calcula las
 * distancias más cortas, dado un nodo inicial del
 * grafo, hacia los otros nodos.
 * El grafo debe ser no dirigido, conexo y sus
 * arcos deben tener pesos positivos.
 *
 **************************************************/

package graph;

import java.util.*;


public class Graph {

    public int numNodos;
    public LinkedList arcos[];
    static int INFINITY;
    int d[];

    public Graph(int n){

        this.arcos = new LinkedList[n+1];
        this.numNodos=n;
        INFINITY = (int)Integer.MAX_VALUE;
        d = new int[numNodos+1];

        for (int i = 1; i<=n; i++) {
            arcos[i] = new LinkedList();
        }
    }

    public void agregarArco(int v, int w, int z){

        Nodo x = new Nodo(v,z);
        Nodo y = new Nodo(w,z);
        arcos[v].add(y);
        arcos[w].add(x);

    }

    public void showDist(int s){

        System.out.println("Distancias desde el nodo "+s+" a:");

        int l = d.length;
        for(int i=1; i<l; i++){

            System.out.print("nodo "+i+": "+d[i]+" | ");
        }
        System.out.println();

    }

    public void Dijkstra(int start){

        /* Se implementa la cola de prioridad en forma de heap.
         * El heap se implementó en una clase aparte */
        Heap priorQ = new Heap(numNodos);

        for (int i = 1; i<=numNodos; i++){

            if(i==start) d[i]=0;
            else d[i]=INFINITY;

            priorQ.add(d[i],i);

        }

        priorQ.mostrar();
        while(!priorQ.isEmpty()){

            Objeto o = priorQ.removeMin();
            int e = o.elemento;

            ListIterator l = arcos[e].listIterator();

            Nodo n;

            while(l.hasNext()){ //para todos los nodos adyacentes

                n = (Nodo)l.next();

                if(priorQ.pos[n.valor]!=0){ //si el nodo está en el heap

    //Se actualiza, si es necesario, la distancia:
                    if((d[e] + n.peso) < d[n.valor]){
                        d[n.valor] = d[e]+n.peso;
                        int temp = priorQ.pos[n.valor];
    //Se actualiza la clave del Objeto que representa a ese Nodo en el heap:
                        priorQ.elementAtIndex(temp).key = d[n.valor];
                        priorQ.upHeap(temp);
                    }
                }
            }
        }

        showDist(start);
    }


}
