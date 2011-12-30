import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;


class ArrComparator implements Comparator<int[]>
{ 
    @Override
    public int compare(int[] o1, int[] o2) {
        if( o1[0] < o2[0] )
        {
            return -1;
        }
        if( o1[0] > o2[0] )
        {
            return 1;
        }
        return 0;
    }
}



public class Dijkstra {
 

    private static int MAX = 100;
    private static int n;
    private static int total;
    private static int [][] Graph;
    
    private static int [] distances;
    private static int [] prev;
    private static boolean [] visited;

    private static Comparator<int []> comparator;
    private static PriorityQueue<int[]> Queue ;

   
    
    
    static void dijkstra(int start)
    {
        
      
        int [] a,tmp;
        int i,j;

        // initialze matrix 
        for( i = 0; i <total; i++)
        {
            distances[i] = Integer.MAX_VALUE;
            prev[i] = -1;
            visited[i] = false;
        }
        
        distances[start] = 0;
        
        a = new int[2];
        a[0] = distances[start];
        a[1] = start;
        
        Queue.add( a );
        
        while( !Queue.isEmpty() ){
            tmp = (int[]) Queue.poll(); // el nodo con la distancia mas chica
            i = tmp[1]; // numero del nodo
            if( !visited[ i ] ) { // si no a sido visitado
                visited[ i ] = true; // marcarlo como visitado
                for( j = 0; j<total; j++) { // para todos los nodos vecinos
                  
                    int alt = distances[i] + Graph[i][j] ;
                    //si el vecino no a sido visitado, existe una arista entre ellos
                    // y la distancia desde el nodo i + de i a j, es menor que a la ya existente 
                    if( !visited[j] && Graph[i][j] > 0 &&  alt < distances[j] ) {
                        distances[j] = alt;
                        prev[j] = i;
                        a = new int[2];
                        a[0] = distances[j];
                        a[1] = j;
                        Queue.add(a);
                    }
                }       
            }       
        }   
    }
    
    static public void main(String[] args) {

    
       Scanner in = new Scanner(System.in);

       total = in.nextInt(); // number of nodes 
       int e = in.nextInt();
       Graph = new int[total][total];
       distances = new int[total];
       prev = new int[total];
       visited = new boolean[total];
       
       comparator = new ArrComparator();
       Queue = new PriorityQueue<int[]>(total,comparator);
       System.out.println("comienza a leer las aristas");
       // read graph
       for(int i = 0; i<e; i++ )
       {
          // System.out.println("arista numero "+ Integer.toString(i) );
           int a,b,d;
           a = in.nextInt();
           b = in.nextInt();
           d = in.nextInt();
         //  System.out.println(Integer.toString(a)+" "+Integer.toString(b)+" "+Integer.toString(d) );
           Graph[a][b] = d;
           Graph[b][a] = d;
       }
        
       dijkstra(0);

      // System.out.println(distances[3]);
        
    }
}
