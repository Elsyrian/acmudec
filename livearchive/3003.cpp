/****************************************************************************
 * 3003 - Jelly
 * http://acmicpc-live-archive.uva.es/nuevoportal/data/problem.php?p=3003
 *
 * Se pide determinar a que alumno se le esta robando jalea para beneficiar a otro.
 * Para determinar esto, se dan las dimensiones del pote donde se sirve la jalea
 * y en base al volumen determinar que alumno esta siendo perjudicado del promedio
 * y quien esta siendo beneficiado. Puede darse que ningun alumno es perjudicado
 * o bien solo 1 alumno es perjudicado y solo 1 beneficiado.
 *                                                      -- Francisco Serrano
 *
 */

#include <iostream>
#include <string>
using namespace std;

int casos,i,j,menor,mayor,aux,total,mayor2,menor2;
string nombres[100];

int main(int argc, char** argv) {

  while(true){
    cin >> casos;
    if(casos==0)return 0;
    menor=0;
    mayor=0;
    menor2=-1;
    mayor2=-1;
    for(i=0;i<casos;i++){
        cin >> nombres[i];
        total=1;
        j=0;
        while(j<3){
            cin >>aux;
            total=total*aux;
            j++;
        }
        if(i==0){
            menor=total;
            mayor=total;
        }
        else{
            if(total>mayor){
                if(mayor2==-1){
                    mayor2=i;
                    mayor=total;
                }
                else{
                    menor2=0;
                    mayor2=i;
                    mayor=total;
                }
            }
            else if(total<menor){
                if(menor2==-1){
                    menor2=i;
                    menor=total;
                }
                else{
                    mayor2=0;
                    menor2=i;
                    menor=total;
                }
            }
        }
    }
    if(menor2==-1 || mayor2==-1){
    cout << "No child has lost jelly." << endl;
    }
    else{
    cout << nombres[menor2] << " has lost jelly to " << nombres[mayor2] << "." << endl;
    }
  }

  return 0;
 }
