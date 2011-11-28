/****************************************************************************
 * 4216 - Pole Position
 * http://acmicpc-live-archive.uva.es/nuevoportal/data/problem.php?p=4216
 *
 * La idea del problema es reconstruir la grilla de partida de una carrera.
 * Fue el primer problema que intente hacer, pero se me complico y la verdad es que
 * como me gusta la formula 1, despues le segui metiendo mano hasta que salio.
 * No es tan complicado una vez que se entiende bien las dimensiones del problema.
 *
 *                                                      -- Francisco Serrano
 *
 */

#include <iostream>
using namespace std;


int main(int argc, char** argv) {
  int pista[1000000];
  int autos, numero, pos,i;
  bool valido;
  while(true){
    cin >> autos;
    if(autos==0)return 0;
    valido=true;
    for(i=0;i<autos;i++){
        cin >> numero;
        cin >> pos;
        if((i+pos)>=0 && (i+pos)<autos){
            if(pista[i+pos]==0)pista[i+pos]=numero;
            else valido=false;
        }
        else valido=false;
    }
    if(valido==false){
        cout << "-1" << endl;
        for(i=0;i<autos;i++){
            pista[i]=0;
        }
    }
    else{
        for(i=0;i<autos;i++){
            if(i!=0) cout << " ";
            cout << pista[i];
            pista[i]=0;
        }
        cout << endl;
    }
  }



  return 0;
 }
