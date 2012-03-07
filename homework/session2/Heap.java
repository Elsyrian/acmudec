
package graph;

import java.util.ArrayList;

public class Heap {

ArrayList<Objeto> heap;
int pos[];

    public Heap(int n){

        heap = new ArrayList<Objeto>();
        pos = new int[n+1];
        heap.add(0, null);
    }

    void add(int x, int y){

        Objeto o = new Objeto(x,y);
        
        heap.add(o);
        int i = heap.indexOf(o);

        pos[y] = i;
        upHeap(i);        
    }
    
    void upHeap(int i){

        if(i==1) return;

        Objeto m = heap.get(i);
        Objeto n = heap.get(i/2);

        if(n.key > m.key){

            heap.set(i/2, m);
            heap.set(i, n);

            pos[n.elemento]=i;
            pos[m.elemento]=i/2;

            upHeap(i/2);
        }
    }

    boolean isEmpty(){

        if(heap.size()>1) return false;

        else return true;

    }

    Objeto removeMin(){

        Objeto r = heap.get(1);
        int s = heap.size();
        Objeto nr = heap.get(s-1);

        heap.set(1, nr);
        heap.remove(s-1);

        pos[nr.elemento]=1;
        pos[r.elemento]=0;

        downHeap(1);

        return r;
    }

    void downHeap(int i){

        if(i==heap.size()-1 || 2*i > heap.size()-1) return;

        Objeto a = heap.get(i);
        Objeto l = heap.get(2*i);
        int g = 2*i + 1;

        if(g<heap.size()){
            Objeto r = heap.get(g);

            if(l.key<= r.key){

                if(a.key > l.key){
                    heap.set(i, l);
                    heap.set(2*i, a);

                    pos[l.elemento]=i;
                    pos[a.elemento]=2*i;

                    downHeap(2*i);
                }
            }
            else {

                if(a.key > r.key){
                    heap.set(i,r);
                    heap.set(2*i+1,a);

                    pos[r.elemento]=i;
                    pos[a.elemento]=2*i+1;

                    downHeap(2*i+1);
                }
            }
        }
        else{

            if(a.key > l.key){
                heap.set(i, l);
                heap.set(2*i, a);

                pos[l.elemento]=i;
                pos[a.elemento]=2*i;

                downHeap(2*i);
            }
        }
    }

    void mostrar(){

        int s = heap.size();

        for (int i = 1; i< s; i++){
            Objeto x = heap.get(i);
        }
    }

    Objeto elementAtIndex(int i){
        return heap.get(i);
    }

}
