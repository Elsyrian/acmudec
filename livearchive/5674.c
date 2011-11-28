/*************************************************
*       5674 - Goldbach's Conjecture (II)
*       http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=3675
*
*       Programa que pide hacer un calculo de los numeros de goldbach, es decir,
*       se utilizan los numeros primos, ya que un numero de goldbach es uno que puede ser escrito como
*       la suma de varios primos.
*       Para este programa he ocupado el algoritmo de Prime Sieve of Eratosthenes, el cual me calcula los
*       primeros primos hasta el numero 100000000 en muy poco tiempo.
*
*                                           autor: Javier Rodriguezq
*/
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define MAXN  100000000
#define P1    1562501
#define P2    50000000
#define P3    5000
#define GET(b) ((sieve[(b)>>5]>>((b)&31))&1)
uint32_t sieve[P1];

void make() {
    uint32_t i, j, k;
    memset(sieve, 0, sizeof(sieve));
    for (k=1 ; k<=P3; k++)
        if (GET(k)==0) for(j=2*k+1,i=2*k*(k+1); i<P2; i+=j) sieve[i>>5]|=1<<(i&31);
}

int isprime(int p) {
    return p==2 || (p>2 && (p&1)==1 && (GET((p-1)>>1)==0));
}


int main() {

    int i,n,j,N,cant;
    int *tabla;
    make();
    tabla = malloc(sizeof(int)*6000000);
    for (n = 0, i = 0; i <= MAXN; i++) {
        if(isprime(i)) {
            tabla[n] = i;
            n++;
        }
    }
    while(1) {
        scanf("%d",&N);
        if(N == 0) break;
        cant = 0;
        for(i=0 ; tabla[i]<N ; i++) {
            for(j=i ; tabla[j]<N ; j++) {
                if(tabla[i] + tabla[j] == N) cant++;
            }
        }
        printf("%d\n",cant);
    }

    return 0;
}
