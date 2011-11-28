/****************************************************************************
 * 2731 - Wacmian Numbers
 * http://acmicpc-live-archive.uva.es/nuevoportal/data/problem.php?p=2731
 *
 * Se trata de interpretar un nuevo lenguaje alienigena. En realidad no pide más que traducir
 * los caracteres a base 10 y entregar el decimal correspondiente. Lo subo a pesar de que el mathi
 * ya lo hizo, ya que lo programe en c++ para agregar algo más a la libreria.
 *
 *                                                      -- Francisco Serrano
 *
 */


#include <iostream>
#include <math.h>
using namespace std;

int numero(char a){
    if(a=='%')return 0;
    if(a==')')return 1;
    if(a=='~')return 2;
    if(a=='@')return 3;
    if(a=='?')return 4;
    if(a=='\\')return 5;
    if(a=='$')return -1;
    return -2;
}

int main(int argc, char** argv) {
  string linea;
  int largo,contador,i;
  while(true){
    cin >> linea;
    if(linea=="#")return 0;
    largo=linea.size();
    contador=0;
    for(i=0;i<largo;i++){
        contador+=(numero(linea[i])*pow(6,largo-1-i));
    }
    cout << contador << endl;
  }
  return 0;
 }
