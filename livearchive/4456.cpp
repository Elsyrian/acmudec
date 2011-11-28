/****************************************************************************
 * 4456 - Contest Postmortem
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=377&problem=2457&mosmsg=Submission+received+with+ID+800310
 *
 * Teniendo una serie de competidores con los respectivos problemas que han resuelto
 * Se debe asignar los siguientes puntos al puntaje total si se cumplen los requerimientos
 * 1 punto, si todos los problemas han sido resueltos por al menos 1 equipo
 * 2 puntos, si mas del 90% de los equipos resolvio mas de 2 problemas
 * 2 puntos, si ningun equipo realizo todos los problemas
 *                                                      -- Francisco Serrano
 *
 */

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) {

  int arreglo[20];
  int c,p,i,j,aux,contador,mas2,puntaje,casos;
  bool todos;
  string nombre;
  for(i=0;i<20;i++){
    arreglo[i]=0;
  }
  casos=1;
  while(true){
    cin >> c;
    cin >> p;
    if(c==0 && p==0)return 0;
    todos=false;
    puntaje=0;
    mas2=0;

    for(i=0;i<c;i++){
        cin >> nombre;
        contador=0;
        for(j=0;j<p;j++){
            cin >> aux;
            if(aux==1){
                arreglo[j]=1;
                contador++;
            }
        }
        if(contador==j)todos=true;
        if(contador>=2)mas2++;
    }
    contador=0;
    for(j=0;j<p;j++){
        contador+=arreglo[j];
        arreglo[j]=0;
    }
    if(contador==j)puntaje+=1;
    if(todos==false)puntaje+=2;
    if(mas2>c*0.9)puntaje+=2;
    cout << "Contest " << casos << ": " << puntaje << endl;
    casos++;
  }
  return 0;
 }
