/*******************************************************
*       4473 - Brothers
*       http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=2474
*
*       El problema consiste en resolver cierta cantidad de disputas territoriales con ciertas
*       reglas dadas, siempre y cuando se tenga cuidado de no salirse de los intervalos dados,
*       no deberia haber demasiado problema para resolverlo.
*                                                           autor: Javier Rodriguezq.
*/

#include <stdio.h>

int mundo[1000][1000],copia[1000][1000];

void atacar(int R,int C,int N) {
    int i,j;
    for(i=0 ; i<R ; i++) {
        for(j=0 ; j<C ; j++) {
            copia[i][j] = mundo[i][j];
        }
    }

    /* Hacia la derecha */
    for(i=0 ; i<R ; i++) {
        for(j=0 ; j<C-1 ; j++) {
            if(mundo[i][j]+1 == mundo[i][j+1] || (mundo[i][j]+1 == N && mundo[i][j+1] == 0))
                copia[i][j+1] = mundo[i][j];
        }
    }

    /* Hacia la izquierda */
    for(i=0 ; i<R ; i++) {
        for(j=C-1 ; j>0 ; j--) {
            if(mundo[i][j]+1 == mundo[i][j-1] || (mundo[i][j]+1 == N && mundo[i][j-1] == 0))
                copia[i][j-1] = mundo[i][j];
        }
    }

    /* Hacia arriba */
    for(i=0 ; i<R-1 ; i++) {
        for(j=0 ; j<C ; j++) {
            if(mundo[i][j]+1 == mundo[i+1][j] || (mundo[i][j]+1 == N && mundo[i+1][j] == 0))
                copia[i+1][j] = mundo[i][j];
        }
    }

    /* Hacia abajo */
    for(i=R-1 ; i>0 ; i--) {
        for(j=0 ; j<C ; j++) {
            if(mundo[i][j]+1 == mundo[i-1][j] || (mundo[i][j]+1 == N && mundo[i-1][j] == 0))
                copia[i-1][j] = mundo[i][j];
        }
    }



}
void copiar(int R, int C) {
    int i,j;
    for(i=0 ; i<R ; i++) {
        for(j=0 ; j<C ; j++) {
            mundo[i][j] = copia[i][j];
        }
    }
}

int main() {

    int N,R,C,K,i,j;

    while(1) {

        scanf("%d %d %d %d",&N,&R,&C,&K);
        if( N == 0 && R == 0 && C == 0 && K == 0) break;
        for(i=0 ; i<R ; i++) {
            for(j=0 ; j<C ; j++) {
                scanf("%d",&mundo[i][j]);
            }
        }
        while(K > 0) {
            atacar(R,C,N);
            copiar(R,C);
            K--;
        }
        for(i=0 ; i<R ; i++) {
            for(j=0 ; j<C ; j++) {
                printf("%d",mundo[i][j]);
                if(j+1 != C) printf(" ");
            }
            printf("\n");
        }
    }

    return 0;
}
