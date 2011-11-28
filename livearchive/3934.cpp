/****************************************************************************
 * 3934 - He is Offside!
 * http://acmicpc-live-archive.uva.es/nuevoportal/data/problem.php?p=3934
 *
 * El problema pide detectar si los atacantes de un equipo estan offside
 * Para esto habia que entender primero cuando estaba un jugado offside
 * y posteriormente verificar si el delantero más cercano al arco estaba
 * más atras que los ultimos 2 defensas (es decir los defensas mas cercanos
 * a su propio arco). No era necesario almacenar todos los valores.
 *                                                      -- Francisco Serrano
 *
 */

#include <iostream>
using namespace std;


int main(int argc, char** argv) {
   int atacantes=0, defensas=0;
    cin >> atacantes;
    cin >> defensas;
    while(atacantes!=0 && defensas!=0){
        int menorA=0, menorD=0;
        int i, aux;
        int contador=0;
        for(i=0;i<atacantes;i++){
            cin >> aux;
            if(menorA==0)menorA=aux;
            else if(aux<menorA)menorA=aux;
        }
        for(i=0;i<defensas;i++){
            cin >> aux;
            if(aux<=menorA)contador++;
        }
        if(contador>1) cout << "N" << endl;
        else if(contador <= 1) cout << "Y" << endl;
        cin >> atacantes;
        cin >> defensas;
    }
  return 0;
 }
