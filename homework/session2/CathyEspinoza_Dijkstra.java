/**************************************************
 *
 * Aplicación principal. Permite escanear varios
 * grafos y aplicar el algoritmo de Dijkstra sobre
 * ellos. Se cierra cuando los valores ingresados
 * para r, c y q, que describen un nuevo grafo,
 * son todos 0.
 *
 **************************************************/


package graph;

import java.util.Scanner;


public class MainDijkstra {

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        int r,c,q; // r = num nodos, c = num arcos, q = consultas
        int a,b,p; //para agregar arcos
        int start;

        while (true) {

/*********************Creación del Grafo ************************/

            r = scan.nextInt();
            c = scan.nextInt();
            q = scan.nextInt();

            if (r==0 && c==0 && q==0) break;

            Graph grafito = new Graph(r);

            for (int i = 0; i<c; i++){
                a = scan.nextInt();
                b = scan.nextInt();
                p = scan.nextInt();

                grafito.agregarArco(a,b,p);
            }

/****************************************************************/

            for (int i = 0; i<q; i++){

                start = scan.nextInt();

                grafito.Dijkstra(start);
            }
       }
    }

}
