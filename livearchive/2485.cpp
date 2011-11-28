/****************************************************************************
 * 2485 - Vowels Frequencies
 * http://acmicpc-live-archive.uva.es/nuevoportal/data/problem.php?p=2485
 *
 * Se pide determinar cuantas vocales hay en cada string de entrada y luego
 * imprimir en pantalla las vocales desde las que se repiten con mayor
 * frecuencia hasta la menor. En caso de que dos vocales se repitan igual
 * cantidad de veces, predomina el orden A,E,I,O,U. Lo complicado para mi
 * fue aprender un algoritmo de ordenamiento y el formato de salida.
 * Creo que se puede optimizar bastante, cuando tenga más tiempo lo haré.
 *
 *                                                      -- Francisco Serrano
 *
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
string linea;
int a1,a2,a3,a4,a5,largo,j;
bool primera;

bool myfunction (int i,int j) {
    return (i>j);
}

int main(int argc, char** argv) {
    int arreglo[5];
    while(true){
        getline (cin,linea);
        a1=0;a2=0;a3=0;a4=0;a5=0;
        primera=true;

        if(linea=="#") return 0;
        largo=linea.size();
        for(j=0;j<largo;j++){
            if(linea.at(j)=='a' || linea.at(j)=='A')a1++;
            else if(linea.at(j)=='e' || linea.at(j)=='E')a2++;
            else if(linea.at(j)=='i' || linea.at(j)=='I')a3++;
            else if(linea.at(j)=='o' || linea.at(j)=='O')a4++;
            else if(linea.at(j)=='u' || linea.at(j)=='U')a5++;
        }
        arreglo[0]=a1;
        arreglo[1]=a2;
        arreglo[2]=a3;
        arreglo[3]=a4;
        arreglo[4]=a5;
        vector<int> myvector (arreglo, arreglo+5);
        sort (myvector.begin(), myvector.end(), myfunction);

        for(j=0;j<myvector.size();j++){
            if(myvector[j]==a1){
                if(primera){
                    cout << "a:" << a1;
                    primera=false;
                }
                else cout << " a:" << a1;
                a1=-1;
            }
            if(myvector[j]==a2){
                if(primera){
                    cout << "e:" << a2;
                    primera=false;
                }
                else cout << " e:" << a2;
                a2=-1;
            }
            if(myvector[j]==a3){
                if(primera){
                    cout << "i:" << a3;
                    primera=false;
                }
                else cout << " i:" << a3;
                a3=-1;
            }
            if(myvector[j]==a4){
                if(primera){
                    cout << "o:" << a4;
                    primera=false;
                }
                else cout << " o:" << a4;
                a4=-1;
            }
            if(myvector[j]==a5){
                if(primera){
                    cout << "u:" << a5;
                    primera=false;
                }
                else cout << " u:" << a5;
                a5=-1;
            }
        }
        cout << "." << endl;
        }
        return 0;
 }



