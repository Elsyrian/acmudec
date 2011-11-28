/****************************************************************************
 * 2881 - Dice
 * http://acmicpc-live-archive.uva.es/nuevoportal/data/problem.php?p=2881
 *
 * Problema consistente en un juego de tablero lineal, donde se debia decidir
 * quien seria el ganador dado un numero predeterminado de tiradas de dados
 *
 *                                                      -- Mathias Ercoreca
 *
 */


#include <stdio.h>

int main(){

    int a,i,b,c,B[22],k,e,f,h,jug,tab;
    k=1;

    while(1){

        scanf("%i %i",&jug,&tab);

        if(jug == 0 && tab== 0){

            return 0;

        }

	for(i=0;i<22;i++){

		B[i]=0;

	}

        scanf("%i %i %i %i",&e,&f,&h,&a);

        while(1){

            if(B[k+10] == 1){

		B[k+10] = 0;
               if(k == jug){

                    k=0;

                }
                k++;

            }

            else{

            	scanf("%i %i",&b,&c);
            	B[k] = b+c+B[k];
                if(B[k] > tab){

                    break;

                }

                if(B[k] == e || B[k] == f || B[k] == h){

                    B[k+10] = 1;

                }

                if(k == jug){

                    k=0;

                }

                k++;
            }

        }
        printf("%i\n",k);
	k=1;

    }

    return 0;
}

