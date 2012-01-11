
/**************************************************
 *
 * Grafo implementado usando vector de adyacencia.
 * EL metodo DFS recibe como parametro un valor
 * correspondiente al nodo inicial y almacena una
 * lista con los nodos en la componente conexa del
 * Grafo que contiene a n.
 **************************************************/

package graph;

import java.util.*;

public class CathyEspinoza_Grafo {

    public int numNodos;
    public LinkedList arcos[];
    public boolean visitados[];
    public LinkedList conexCompOfn;

     public static void main(String[] args) {

        Scanner scan;
        int r,c,q;
        int a,b;
        int start;
        scan = new Scanner(System.in);

        while (true) {

/*********************Creación del Grafo ************************/

            r = scan.nextInt();
            c = scan.nextInt();
            q = scan.nextInt();

            if (r==0 && c==0 && q==0) break;

            CathyEspinoza_Grafo grafito = new CathyEspinoza_Grafo(r);

            for (int i = 0; i<c; i++){
                a = scan.nextInt();
                b = scan.nextInt();

                grafito.agregarArco(a,b);
            }

/****************************************************************/

            for (int i = 0; i<q; i++){

                start = scan.nextInt();

                grafito.DFS(start);

                System.out.println(grafito.conexCompOfn);
                grafito.limpiar();

            }
       }
    }


    public CathyEspinoza_Grafo (int n){

        this.arcos = new LinkedList[n+1];
        this.visitados = new boolean[n+1];
        this.numNodos=n;
        this.conexCompOfn = new LinkedList();

        for (int i = 1; i<=n; i++) {
            arcos[i] = new LinkedList();
            visitados[i] = false;
        }
    }

    public void agregarArco(int v, int w){

        Nodo x = new Nodo(v);
        Nodo y = new Nodo(w);
        arcos[v].add(y);
        arcos[w].add(x);
    }
    public void limpiar(){

        for (int i=1; i<=this.numNodos; i++){
            visitados[i]=false;
        }

        conexCompOfn.clear();

        ListIterator iter;
        Nodo n = new Nodo(0);

        for(int i=1; i<=this.numNodos; i++){

            iter = arcos[i].listIterator();

            while(iter.hasNext()){

                n = (Nodo)iter.next();
                n.tipo = "unexplored";
            }
        }
    }

    public void DFS(int n){

        visitados[n] = true;
        conexCompOfn.add(n);

        ListIterator iter = arcos[n].listIterator();
        Nodo ene = new Nodo(0);
        Nodo eme = new Nodo(0);

        while(iter.hasNext()){

            ene = (Nodo)iter.next();

            if(ene.tipo.equals("unexplored")){

                if(visitados[ene.valor]==false){

                    ene.tipo = "discovery";
                    Iterator it = arcos[ene.valor].iterator();

                    while(it.hasNext()){

                        eme = (Nodo)it.next();

                        if(eme.valor == n && eme.tipo.equals("unexplored")){

                            eme.tipo = "discovery";
                            break;
                        }
                    }
                    
                    DFS(ene.valor);
                }
            }
            else {

            ene.tipo = "back";
            }
        }
    }
}

class Nodo {

    int valor;
    String tipo;

    public Nodo (int v) {

        valor = v;
        tipo = "unexplored";

    }
}
