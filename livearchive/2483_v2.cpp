/****************************************************************************
 * 2483 - House Numbering
 * http://acmicpc-live-archive.uva.es/nuevoportal/data/problem.php?p=2483
 *
 * Problema resuelto por Rodrigo Castro, Francisco Serrano y Mauricio Echavarria
 */
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
int costo(string num, int costA, int costB){
    int dir = atoi(num.c_str());
    int acm = 0, digit;
    while(dir>0){
      digit = dir%2;
      if(digit) acm += costB;
      else acm += costA;
      dir = dir/2;
    }
    return acm;
}

int main(int argc,char **argv){
  int costA, costB, aux=1;
  string aux1;
  while(1){
    cin >> aux1;
    if(aux1=="#") return 0;
    else if(aux1=="COST"){
      cin >> costA;
      cin >> costB;
      cout << "Set " << aux << endl;
      aux +=1 ;
    } else {
      cout << costo(aux1, costA, costB) << endl;
    }
    

  }
  

return 0;
}
