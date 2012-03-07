
package acm;

import java.util.Iterator;
import java.util.Queue;
import java.util.LinkedList;

/******************************************************
 * Clase Grafo en implementacion de lista con arcos.
 * La clase contiene los metodos BFS y Prim Jarnik.
 * Para inicializar el grafo:
 *      -pasar como parametro al constructor, la cantidad 
 *      de nodos que tendrá el grafo.
 *      -Agregar uno a uno los arcos que tendra el grafo,
 *      utilizando el metodo addArco(origen,destino,peso)
 *****************************************************/

public class Grafo {
    
    LinkedList<Arco> arcos;
    boolean estados[];
    int distanciasBFS[];
    int distanciasPrim[];
    int padreBFS[];
    int padrePrim[];
    int nodos;
    Grafo prim;
    
    Grafo(int n){
        estados=new boolean[n];
        distanciasBFS= new int[n];
        distanciasPrim = new int[n];
        padrePrim=new int[n];
        padreBFS= new int[n];
        arcos = new LinkedList<Arco>();
        nodos=n;
    }
    
    Grafo( Grafo G){
        this.arcos=G.arcos;
        this.estados=G.estados;
        this.distanciasBFS=G.distanciasBFS;
        this.distanciasPrim=G.distanciasPrim;
        this.padreBFS=G.padreBFS;
        this.padrePrim=G.padrePrim;
        this.nodos=G.nodos;
        prim=G.prim;
    }
    
    int BFS(int inicio, int fin){
        Arco a;
        
        for(int i=(nodos-1);i>=0;i--){
            estados[i]=false;
            distanciasBFS[i]=Integer.MAX_VALUE;
            padreBFS[i]=-1;
        }
        
        estados[inicio] = true;
        distanciasBFS[inicio] = 0;
        
        Queue<Integer> Q= new LinkedList<Integer>();
        Q.add(inicio);
        
        while(Q.peek()!=null){
            
            int u=Q.poll();
            
            Iterator<Arco> i = arcos.iterator();
            
            while(i.hasNext()){
                a=i.next();
                
                if(u==a.o && estados[a.d]==false){
                    estados[a.d]=true;
                    distanciasBFS[a.d]=distanciasBFS[u]+a.p;
                    padreBFS[a.d]=u;
                    
                    Q.add(a.d);
                }
                else if(u==a.d && estados[a.o]==false){
                    estados[a.o]=true;
                    distanciasBFS[a.o]=distanciasBFS[u]+a.p;
                    padreBFS[a.o]=u;
                    
                    Q.add(a.o);
                }
            }
        }
        
        for(int i=0;i<nodos;i++){
            
            System.out.println("de 0 a "+i+": "+distanciasBFS[i]);
            
        }
     
        return distanciasBFS[fin];
    }
    
    Grafo Prim(int root){
        
        for (int i=(nodos-1);i>=0;i--){
            distanciasPrim[i]=Integer.MAX_VALUE;
            padrePrim[i]=-1;    
            estados[i]=false;
        }
        distanciasPrim[root]=0;
        
        int cant=1;
        int menor;
        int indice=0;
        Arco arco;
        Iterator<Arco> iterador;
        while(cant<nodos){
            
            menor=Integer.MAX_VALUE;
            for(int i=(nodos-1);i>=0;i--){
                if(distanciasPrim[i]<menor && estados[i]==false){                    
                    indice=i;
                    menor=distanciasPrim[i];
                }
            }
                        
            estados[indice]=true;
            iterador = arcos.iterator();
            
            while(iterador.hasNext()){
            
                arco=iterador.next();
                
                if(indice==arco.d && arco.p<distanciasPrim[arco.o]){
                    distanciasPrim[arco.o]=arco.p;
                    padrePrim[arco.o]=indice;
                }
                else if(indice==arco.o && arco.p<distanciasPrim[arco.d]){
                    distanciasPrim[arco.d]=arco.p;
                    padrePrim[arco.d]=indice;
                }
            }
            cant++;
        }
        
        Grafo nuevo = new Grafo(nodos-1);
        
        for(int i=0;i<nodos;i++){
            if(i!=root){
                nuevo.addArco(padrePrim[i],i,distanciasPrim[i]);
            }
        }
        return nuevo;
    }
    
    void addArco(int origen, int destino, int peso){
        
        if(origen>=0 && origen<=nodos && destino>=0 && destino<=nodos){
            Arco a = new Arco(origen,destino,peso);
            arcos.add(a);
        }
    }
    
    void print(){
        
        Iterator<Arco> i = arcos.iterator();
        Arco a;
        
        while(i.hasNext()){
            a=i.next();
            System.out.println(a.o+" - "+a.d+" : "+a.p);
        }
    }
}

class Arco {
    
    int o;
    int d;
    int p;
    
    Arco(int origen,int destino,int peso){
        o=origen;
        d=destino;
        p=peso;
    }
    
}