#include <iostream>
using namespace std;


/****************************************************************************
 * 4964 - What's Next?
 *http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=2965
 *
 * El problema consiste en saber si tres numeros dados son una progresion geometrica o aritmetica
 * hay que indicar que tipo de prrogresion es y dar el 4to numero, bastante simple. Para hacerlo
 * hice un ciclo que va desde uno a diez mil (cantidad de entradas) viendo si cada i del ciclo es 
 * un coeficiente Gemotrico o aritmetico, un poco ineficiente pero funciona y fue aceptado. Saludos.
 *                                                      -- Benjamin Diaz
 *
 */

int main(int argc, char argv[]){
        int n;
        int A[3]={1,1,1};
while(true){
        for(int i=0;i<3;i++){
                cin>>A[i];
        }
        if(A[0]==0 && A[1]==0 && A[2]==0) break;
        if ((-10000>A[0] || A[0]>10000 || -10000>A[1] || A[1]>10000 || -10000>A[2] || A[2]>10000)) break;
        for(int j=1; j<10000+1; j++){
                
                if(A[0]+j==A[1] && A[1]+j==A[2] ) cout<< "AP "<< A[2]+j<<endl;
                if(A[0]-j==A[1] && A[1]-j==A[2] ) cout<< "AP "<< A[2]-j<<endl;
                if(A[0]*j==A[1] && A[1]*j==A[2] ) cout<< "GP "<< A[2]*j<<endl;
                if(A[0]*(-j)==A[1] && A[1]*(-j)==A[2] ) cout<< "GP "<< A[2]*(-j)<<endl;
                
                
        }

}

return 0;
}