

import java.util.Scanner;

/**
 *
 * @author Alejandro Pinto
 */
public class Warshall {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int[][] matriz;//matriz de distancias
        int nodos=in.nextInt()+1;//los nodos se aumentan en 1 
        //para poder partir desde 1 a n, con n=numero de nodos
        
        matriz=new int[nodos][nodos];//se crea una matriz, esta por defecto contiene solo 0's
        
        for(int i=1;i<nodos;i++)
            for(int j=1;j<nodos;j++)
             if(i!=j)
                matriz[i][j]=Integer.MAX_VALUE/2-100000;//esto para evitar problemas con la suma de enteros 
        //muy grandes, la distancia maxima es de 200000, aunq se puede aumentar...
             
        int arcos=in.nextInt();//se ingresa la cantidad de arcos
        
        for(int i=0;i<arcos;i++)
            matriz[in.nextInt()][in.nextInt()]=in.nextInt();//se ingresan los datos a la matriz, esto,
        //considerando q se esta trabajando con un digrafo, por lo q si fuese un grafo se ingresa en ambos sentidos
        //la forma de ingreso es s e d, donde s es el nodo de partida, e el nodo de llegada
        // y d la distancia entre ellos
               
        
        for(int k=1;k<nodos;k++)
            for(int i=1;i<nodos;i++)
                for(int j=1;j<nodos;j++){
                    int dis = matriz[i][k] + matriz[k][j];
                    if(matriz[i][j] > dis)
                        matriz[i][j] = dis;
                }
        //se aplica el algoritmo de warshall
        // a la matriz 
        
        for(int i=1;i<nodos;i++){
            for(int j=1;j<nodos;j++)
                System.out.print(matriz[i][j]+" ");
            System.out.println();
        }
        //se imprime en pantalla la matriz,
        //aunq esto es variable, pues se podria pedir una distancia en especifico
        //en cuyo caso, simplmente se modifica esta ultima linea de codigo
        
        
        
    }
}
