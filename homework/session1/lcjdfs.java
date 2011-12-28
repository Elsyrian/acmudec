/************************************************
 *  Depth first search con matriz de            *
 *  Adyacencia       
 * Luis Jury                                    *
 * *********************************************/

import java.*;
import java.util.Scanner;


public class Main {

   public static boolean[] labels;
   public static int[][] Graph;
   static int n = 0;
   static int start = 0,end = 0;


   public static boolean dfs( int v )
   {
       labels[v] = true;
       if( v == end)
       {
           return true;
       }
       for(int i = 0; i <n; i++)
       {
               // si el siguiente nodo no esta marcado
           if( Graph[v][i] == 1 && labels[i] == false )
           {
               if( dfs(i) )
               {
                   System.out.print(i+" ");
                   return true;
               }
           }

       }
       return false;

   }


  
   public static void main(String[] args) {

       Scanner in = new Scanner(System.in);

       n = in.nextInt(); // number of nodes

       Graph = new int[n][n];
       labels = new boolean[n];

       // initialze matrix and labels
       for(int i = 0; i<n; i++ )
       {
           labels[i] = false;
           for(int j=0; j<n; j++)
               Graph[i][j] = 0;
       }

       // read graph
       for(int i = 1; i<n; i++ )
       {
           int a,b;
           a = in.nextInt();
           b = in.nextInt();

           Graph[a][b] = 1;
           Graph[b][a] = 1;
       }

       start = in.nextInt();
       end = in.nextInt();

       System.out.print("start dfs");

       dfs(start);
   }

}
