/*
 * bfs , matriz de adyacencia y mi promia version de una cola, no muy util
 * pero, la hice cuando aprendia java xD
 * autor: Alejandro Pinto
 */


import java.util.Scanner;
import java.util.Vector;
 
 class Cola {
//clase que genera una cola fifo
    private int[] cola=new int[0];//cola
    
    
    public void push(int a){
    int [] cola2=new int[cola.length+1];
    System.arraycopy(cola, 0, cola2, 0, cola.length);
    cola2[cola.length]=a;
    cola=cola2;
    }//metodo para ingresar enteros a la cola

    public int pop(){
        int temp=cola[0];
        int[] cola2=new int[cola.length-1];
        System.arraycopy(cola, 1, cola2, 0, cola.length-1);
        cola=cola2;
        return temp;
    }//metodo para sacar cosas de la cola, devuelve el valor sacado



    public int view(int i){
    return cola[i];   
    }//retorna el elemento i de la cola


    public void clear(){
    cola=new int[0];
    }//limpia la cola

    public int size(){
    return cola.length;   
    }//devuelve el tamaño de la cola
}

class BFS {
    private Vector<Vector<Integer>> MA;
    private Vector<Vector<Integer>> tree=new Vector<Vector<Integer>>();
    private Cola cola=new Cola();
    private boolean[] visited;//lista que dice si un nodo ha sido visitado o no
    
   
    public BFS(Vector<Vector<Integer>> MA){
        this.MA=MA;
        visited=new boolean[MA.size()];
        for(int i=0;i<MA.size();i++)
        visited[i]=false;
    }//constructor de clase bfs
    
    
    public Vector<Vector<Integer>> getTree(int a){
    getConex(a);
    for(int i=0;i<visited.length;i++){
        if(!visited[i]){
            Vector<Integer> temp = new Vector<Integer>();
            tree.add(temp);
             getConex(i);
            }
    }
    cola.clear();
    Vector<Vector<Integer>> temp=tree;
    tree=new Vector<Vector<Integer>>();
    return temp;
    }

    private void getConex(int raiz) {
        visited[raiz]=true;
        Vector<Integer>temp=MA.elementAt(raiz);
            for(int i=0;i<temp.size();i++){
                if(!visited[temp.elementAt(i)]){
                    visited[temp.elementAt(i)]=true;
                    cola.push(temp.elementAt(i));
                    Vector <Integer>rama=new Vector <Integer>();
                    rama.add(raiz);
                    rama.add(temp.elementAt(i));
                    tree.add(rama);
                    
                }
            }
        while(cola.size()>0){
            getConex(cola.pop());
        }

    }//va llenando el vector tree, parfa devolver el o los arboles conexos del grafo
    
}    

public class matriz_ad {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Vector<Vector<Integer>> nodos =new Vector<Vector<Integer>>();
        Vector<Integer> temp=new Vector<Integer>();
        
        int cant_nodos=in.nextInt();//se ingresa la cantidad de nodos
        for(int i=0;i<cant_nodos;i++){
            int n=in.nextInt();
            //se ingresa la cantidad de nodos adyasentes
            for(int j=0;j<n;j++){
                temp.add(in.nextInt());
                //se ingresan los nodos adyacentes
            }
            nodos.add(temp);
            temp=new Vector<Integer>();
        }

        System.out.println(nodos);
        System.out.println(nodos.size());
  //hasta aqui esta la matriz de adyacencia      
        BFS bfs=new BFS(nodos);
        System.out.println(nodos.get(0));
        System.out.println(bfs.getTree(0));
        
    }
}
