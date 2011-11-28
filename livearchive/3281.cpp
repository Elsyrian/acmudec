/**
 * 3281 - Contest
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=239&page=show_problem&problem=1282
 *
 * Authors:
 * - Rodrigo Castro
 * - Mauricio Echavarria
 * - Francisco Serrano
 *
 * Description:
 *  El problema basicamente es generar un scoreboard de una competencia estilo similar
 *  a la ACM, para ello se entrega informacion de los problemas, los equipos y los envios
 *  de estos. Se calculan los puntajes de los equipos y se ordenan de acuerdo a los criterios
 *  del problema.
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
struct team{
  int id;
  int score;
  int subs;
};
int compara(const void *a, const void *b){

  if( ((struct team *)a)->score > ((struct team *)b)->score ) return -1;
  else if(((struct team *)a)->score < ((struct team *)b)->score) return 1;
  else {
    if(((struct team *)a)->subs > ((struct team *)b)->subs) return 1;
    else if(((struct team *)a)->subs < ((struct team *)b)->subs) return -1;
    else {
      if(((struct team *)a)->id > ((struct team *)b)->id) return 1;
      else return -1;
    }
  }
}
int main(int argc, char **argv){
  int T,P,S,Ttmp,caso=1;
  char Prob, status;
  int letter[26];
  struct team TArray[10];
  while(1){
    scanf("%d %d",&T,&P);
    if((T+P)==0) return 0;
    for(int i=0;i<T;i++){
      TArray[i].id = i+1;
      TArray[i].score = TArray[i].subs = 0;
    }
    for(int i=0;i<P;i++){
      cin >> letter[i];
    }
    cin >> S;
    for(int i=0;i<S;i++){
      cin >> Ttmp;
      cin >> Prob;
      cin >> status;
      TArray[Ttmp-1].subs ++;
      if(status=='A')
	TArray[Ttmp-1].score += letter[Prob-'A'];
    }
    qsort(TArray,T,sizeof(struct team),compara);
    cout << caso << endl;
    caso++;
    for(int i=0;i<T;i++){
      cout << TArray[i].id << " " << TArray[i].score << endl;
    }
  }
  return 0;
}
