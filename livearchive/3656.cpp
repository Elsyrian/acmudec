/*********************************************************
* 3656 - Odd or Even
* http://acmicpc-live-archive.uva.es/nuevoportal/data/problem.php?p=3656
*
*
* Problema bastante facil de un juego en el cual se ambos jugadores
* muestran una cantidad de dedos y si son pares gana el que haya elegido
* par y viceversa. El problema pedia dado una cierta cantidad de juegos
* cuanto era lo minimo que podia ganar uno de los jugadores.
*
*
*                                      -- Mathias Ercoreca
*
*/


#include <iostream>
using namespace std;

int main(){

int Mary[200],John[200],n,i,j,odd;
while(1){
    j=0;
    cin >> n;
    if(n == 0){
        return 0;
    }
    i=n;
    while(i>0){
        cin >> Mary[j];
        i--;
        j++;
    }
    i=n;
    j=0;
    while(i>0){
        cin >> John[j];
        i--;
        j++;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            odd = Mary[i] + John[j];
            if(Mary[i] == -1){
                goto end;
            }
            if(John[j] == -1){
                goto end;
            }
            if(odd%2==1){
                Mary[i] = -1;
                John[j] = -1;
            }
        end:;
        }
    }
    j=0;
    for(i=0;i<n;i++){
        if(Mary[i]!= -1){
            j++;
        }
    }
    cout << j << "\n";
}
return 0;
}
