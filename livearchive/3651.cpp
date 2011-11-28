/*************************************************************************************************************************
 * 3651 - Weekend Lottery
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=1652
 *
 *
 * Author:
 *   Rafael Sepúlveda
 *
 * Description:
 *   Dada una serie de resultados de loteria, determinar cuáles son los números que se han sorteado la menor cantidad de veces.
 */


#include <iostream>

using namespace std;

int main(int argc,char **argv){
    while(1){
        int N,C,K;
        cin >> N;
        cin >> C;
        cin >> K;
        if(N==0 && C==0 && K==0) break;
        int CxN=C*N;
        int numeros[CxN];
        for(int i=0; i<CxN; i++){
            cin >> numeros[i];
        }
        int contar[K];
        for(int j=0;j<K;j++) contar[j]=0;
        for(int i=0;i<CxN;i++){
            contar[numeros[i]-1]++;
        }
        int menor[2]={K+1,0};
        for(int i=0;i<K;i++){
            if(contar[i]<menor[0]){
                menor[0]=contar[i];
                menor[1]=1;
            }
            else if(contar[i]==menor[0]) menor[1]++;
        }
        if(menor[1]>1){
            int impresos=0;
            for(int i=0;i<K;i++){
                if(contar[i]==menor[0]){
                    if(impresos==0) {
                        cout << i+1;
                        impresos++;
                    }
                    else cout << " " << i+1;
                }
            }
        }
        else{
            for(int i=0;i<K;i++){
                if(contar[i]==menor[0]){
                    cout << i+1;
                }
            }
        }
        cout <<  endl;
    }
    return 0;
}
