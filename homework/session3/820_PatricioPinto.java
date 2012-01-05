/*problema 820, 
 *Patricio Pinto <patriciopinto@udec.cl>
 *con un codigo extremadamente largo xDDD, pero esto, 
 *porque incluye mi propia version de una pila y una cola
 * el resto es el algoritmo de Ford (en el main) y un bfs 
 * para encontrar caminos
 * en la creacion del algoritmo llegue a una conclusion: 
 * java es malisima idea para hacer este algoritmo jejeje 
 */
import java.util.Scanner;

class Main {

    static Scanner in = new Scanner(System.in);
    static int[][] MA;
    static Pila camino = new Pila();
    static Pila ptemp = new Pila();
    static boolean sw = false;
    static int counter = 0;
    static int global_counter = 0;
    static boolean[] visited;
    static int n = 0;
    static int[] prev;

    public static void main(String[] args) {

        n = in.nextInt();//nodos

        do {
            if (n <= 0) {
                break;
            }
            MA = new int[n + 1][n + 1];
            visited = new boolean[n + 1];
            prev = new int[n + 1];
            visited[0] = true;
            int x = in.nextInt(), y = in.nextInt(), a = in.nextInt();//x=origen, y=destino, a=arcos

            for (int i = 0; i < a; i++) {
                int t = in.nextInt();
                int u = in.nextInt();
                int v = in.nextInt();
                MA[t][u] += v;
                MA[u][t] += v;
            }

            if (bfs(x, y) > 0) {
                pasar(x, y);
                prev = new int[n + 1];
            }


            while (camino.size() > 0) {
                int[] temp = camino.getPila();
                ptemp.push(MA[x][temp[0]]);

                for (int i = 0; i < temp.length - 1; i++) {
                    ptemp.push(MA[temp[i]][temp[i + 1]]);
                }

                MA[x][temp[0]] -= ptemp.getMinorValue();

                for (int i = 0; i < temp.length - 1; i++) {
                    MA[temp[i]][temp[i + 1]] -= ptemp.getMinorValue();
                }

                counter += ptemp.getMinorValue();
                ptemp.clear();
                camino.clear();
                visited = new boolean[n + 1];
                if (bfs(x, y) > 0) {
                    pasar(x, y);
                } else {
                    break;
                }
                prev = new int[n + 1];

            }


            global_counter++;
            System.out.println("Network " + global_counter);
            System.out.println("The bandwidth is " + counter + ".");
            System.out.println();
            counter = 0;
            n = in.nextInt();
        } while (n > 1);

    }

    static int bfs(int s, int t) {
        Cola cola = new Cola();
        cola.push(s);
        prev[s] = -1;

        while (cola.size() > 0) {
            int tmp = cola.pop();
            if (tmp == t) {
                return 1;
            }
            visited[tmp] = true;
            for (int i = 1; i < MA[tmp].length; i++) {
                if (MA[tmp][i] > 0 && !visited[i]) {
                    cola.push(i);
                    prev[i] = tmp;
                }
            }
        }

        return -1;
    }

    static void pasar(int in, int fin) {
        camino = new Pila();
        int i = fin;
        camino.push(i);
        while (prev[i] != -1 && prev[i] != in) {
            i = prev[i];
            camino.push(i);
        }
        Pila tmp = new Pila();
        while (camino.size() > 0) {
            tmp.push(camino.pop());
        }
        camino = tmp;
    }
}

class Pila {

    private int[] pila = new int[0];

    public void push(int a) {
        int[] pila2 = new int[pila.length + 1];
        System.arraycopy(pila, 0, pila2, 0, pila.length);
        pila2[pila.length] = a;
        pila = pila2;
    }

    public int pop() {
        int temp = pila[pila.length - 1];
        int[] pila2 = new int[pila.length - 1];
        System.arraycopy(pila, 0, pila2, 0, pila.length - 1);
        pila = pila2;
        return temp;
    }

    public void show() {
        System.out.println();
        for (int i = 0; i < pila.length; i++) {
            System.out.print(pila[i] + " ");
        }
    }

    public int view(int i) {
        if (i < pila.length) {
            return pila[i];
        } else {
            return -1;
        }
    }

    public void clear() {
        pila = new int[0];
    }

    public int size() {
        return pila.length;
    }

    public int[] getPila() {
        return pila;
    }

    public int getMinorValue() {
        int temp = pila[0];
        for (int i = 1; i < pila.length; i++) {
            if (pila[i] < temp) {
                temp = pila[i];
            }
        }
        return temp;
    }
}

class Cola {

    private int[] cola = new int[0];

    public void push(int a) {
        int[] cola2 = new int[cola.length + 1];
        System.arraycopy(cola, 0, cola2, 0, cola.length);
        cola2[cola.length] = a;
        cola = cola2;
    }

    public int pop() {
        int temp = cola[0];
        int[] cola2 = new int[cola.length - 1];
        System.arraycopy(cola, 1, cola2, 0, cola.length - 1);
        cola = cola2;
        return temp;
    }

    public void show() {
        System.out.println();
        for (int i = 0; i < cola.length; i++) {
            System.out.println(cola[i]);
        }
    }

    public int view(int i) {
        return cola[i];
    }

    public void clear() {
        cola = new int[0];
    }

    public int size() {
        return cola.length;
    }

    public int[] getCola() {
        return cola;
    }
}

