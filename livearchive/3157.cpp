/*************************************************************************************************************************
 * 3157 - Grandpa is famous
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=1158
 *
 * Classification: Mathematics
 *
 * Author:
 *   Rafael Sepulveda     <so.what.mdo@gmail.com>
 *
 * Description:
 *   El objetivo del problema es contar las apariciones de ciertos participantes en un ranking semanal y determinar cual
 * Jugador es el que obtiene el segundo lugar en apariciones.
 *
 **************************************************************************************************************************/

#include <iostream>
using namespace std;


void caso(int n, int m){
    int test[n][m];
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin >> test[i][j];
        }
    }
    int rank[10000];

    for(int i=0; i<10000;i++){
            rank[i]=0;
    }
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){

            rank[test[i][j]-1]++;
        }
    }
    int mayor=0, id;
    for(int i=0; i<10000 ;i++){
        if(rank[i]>mayor){
            mayor=rank[i];
            id=i+1;
        }
    }
    rank[id-1]=0;
    mayor=0;
    id=0;
    for(int i=0; i<10000 ;i++){
        if(rank[i]>mayor){
            mayor=rank[i];
            id=i+1;
        }
    }
    for(int i=0; i<10000 ;i++){
        if(i==id-1){
            if(rank[i]==mayor) cout << i+1 ;
        }
        else{
            if(rank[i]==mayor)  cout << " " << i+1 ;
        }

    }
    cout << endl;


}

int N=1,M=1;
int main(int argc,char **argv){
    cin >>N;
    cin>>M;
    if(N!=0 && M!=0 ){
        while(N!=0 && M!=0){
            caso(N,M);
            cin >> N;
            cin >> M;
        }
    }

return 0;
}
