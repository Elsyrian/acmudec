/****************************************************************************
 * 3279 - Dice
 * http://acmicpc-live-archive.uva.es/nuevoportal/data/problem.php?p=3279
 *
 * Consiste en un juego de 2 personas. La primera tira un dado X veces y la
 * segunda persona al comienzo del juego debe escoger entre PAR o IMPAR.
 * Si sale lo que la segunda persona escogio, ella gana un punto y si no, la
 * primera persona gana el punto. Al final se debe imprimir cuantos puntos
 * obtuvo cada persona con su respectivo nombre.
 *                                                      -- Francisco Serrano
 *
 */

#include <iostream>
#include <string>
using namespace std;
string nombre1;
string nombre2;
string tipo;
int casos, i, aux, name1, name2;

int main(int argc, char** argv) {

    while(true){
        cin >> nombre1;
        cin >> nombre2;
        cin >> tipo;
        if(nombre1=="#" && nombre2=="#" && tipo=="#")return 0;
        cin >> casos;
        name1=0;
        name2=0;
        for(i=0;i<casos;i++){
            cin >> aux;
            if(tipo=="even"){
                if(aux%2==0)name2++;
                else name1++;
            }
            else if(tipo=="odd"){
                if(aux%2==0)name1++;
                else name2++;
            }
        }
        cout << nombre1 << " " << name1 << " " << nombre2 << " " << name2 << endl;

    }

  return 0;
 }
