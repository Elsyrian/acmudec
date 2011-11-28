/*********************************************************
* 4867 - Maximum Square
* http://acmicpc-live-archive.uva.es/nuevoportal/data/problem.php?p=4867
* (nueva) http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=2868
*
* Problema en el cual se pide encontrar el tamaño del maximo
* subcuadrado que puede encontrarse dentro de la matriz. La
* idea es ir viendo a medida que se recorre la matriz, el
* tamaño maximo del cuadrado hasta el momento, luego se busca
* el mayor valor resultante.
*
*                                      -- Rodrigo Castro
*
*/
#include<iostream>
using namespace std;

int min(int a, int b, int c){
  int m = a;
  if (m > b) m = b;
  if (m > c) m = c;
  return m;
}

void maxSubCuadrado(bool M[1000][1000],int R,int C){
    int i,j;
    int S[1000][1000];
    int max_s;

    for(i = 0; i < R; i++) S[i][0] = M[i][0];

    for(j = 0; j < C; j++) S[0][j] = M[0][j];

    for(i = 1; i < R; i++){
        for(j = 1; j < C; j++){
            if(M[i][j] == 1)
                S[i][j] = min(S[i][j-1], S[i-1][j], S[i-1][j-1]) + 1;
            else
                S[i][j] = 0;
            }
    }

    max_s = S[0][0];
    for(i = 0; i < R; i++){
        for(j = 0; j < C; j++){
            if(max_s < S[i][j]) max_s = S[i][j];
        }
    }
    cout << max_s << endl;
}

int main(int argc, char **argv){
    bool M[1000][1000];
    int x,y;
    while(true){
        cin >> x;
        cin >> y;
        if(x+y == 0) return 0;
        else {
            for(int i=0;i<x;i++){
                for(int j=0;j<y;j++){
                    cin >> M[i][j];
                }
            }
            maxSubCuadrado(M,x,y);
        }
    }
    return 0;
}
