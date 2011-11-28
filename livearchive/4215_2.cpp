/****************************************************************************
 * 4215 - Feynman
 * http://acm.uva.es/archive/nuevoportal/data/problem.php?p=4215
 *
 * Problema fácil de programar en el cual la dificultad radicaba en darse cuenta del patron.
 * Lo subo a pesar de que lo envio la cathy en primera instancia, ya que yo lo hice en C++.
 *
 *                                                      -- Francisco Serrano
 *
 */

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
  int i,aux,entero;
  while(true){
    cin >> entero;
    if(entero==0)return 0;
    aux=0;
    for(i=1;i<entero+1;i++){
        aux+=i*i;
    }
    cout << aux << endl;
  }

  return 0;
 }
