/****************************************************************************
 * 2731 - Wacmian Numbers
 * http://acmicpc-live-archive.uva.es/nuevoportal/data/problem.php?p=2731
 *
 * Se pedia un programa que calculara numeros en base 6, donde algunos
 * caracteres significaban cierto numero.
 *
 *                                                      -- Mathias Ercoreca
 *
 */

#include <stdio.h>
#include <math.h>

int main(){

    char A[10];
    int i,j,k,B[10];
    i=0;
    j=0;
    k=0;

    while(1){

        for(i=0;i<10;i++){

            A[i] = '\0';
            B[i] = 0;

        }

        for(i=0;i<10;i++){

            scanf("%c",&A[i]);

            if(A[0] == '#'){

                return 0;

            }

            if(A[i] == '\n'){

                break;

            }

        }

        j=i-1;

        for(i=0;i<10;i++){

            if(A[i] == '\0'){

                break;

            }

            if(A[i] == '%'){

                B[i] = 0;

            }

            if(A[i] == ')'){

                B[i] = 1;

            }

            if(A[i] == '~'){

                B[i] = 2;

            }

            if(A[i] == '@'){

                B[i] = 3;

            }

            if(A[i] == '?'){

                B[i] = 4;

            }

            if(A[i] == 92 ){

                B[i] = 5;

            }

            if(A[i] == '$'){

                B[i] = -1;

            }

            k = k + B[i]*pow(6,j);
            j--;

        }

        if(A[0]!= '\n'){

            printf("%i\n",k);
            k=0;

        }
    }

return 0;

}
