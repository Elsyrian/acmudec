
package graph;


public class Nodo {

    int valor;
    int peso;
    String tipo;

    public Nodo (int v, int p) {

        valor = v;
        peso = p;

    }

    public Nodo (int v){
        valor = v;
        tipo = "unexplored";
    }

}
