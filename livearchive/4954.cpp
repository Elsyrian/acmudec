/*********************************************************
* 4954 - Lawn mower
* http://acmicpc-live-archive.uva.es/nuevoportal/data/problem.php?p=4954
* (nueva) http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=2955
*
* Problema en el cual hay que determinar si el procedimiento para cortar
* el cesped es el correcto. No es muy difil, la dificultad radica en
* darse cuenta del calculo matematico / geometrico del problema.
*
*                                      -- Rodrigo Castro
*
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int compare (const void * a, const void * b){
  return ( *(float*)a > *(float*)b );
}

int main(int argc, char *argv[]){
    float nf,tmp, x[1000], y[1000];
    int nx, ny;
    bool a=true,b=true;
    while(true){
        scanf("%d %d %f",&nx,&ny,&nf);
        if(nx+ny+nf==0) return 0;
        else {
            for(int i=0; i<nx; i++){
                cin >> tmp;
                x[i]=tmp;
            }
            for(int i=0; i<ny; i++){
                cin >> tmp;
                y[i]=tmp;
            }
            qsort(x,nx,sizeof(float),compare);
            qsort(y,ny,sizeof(float),compare);

            for(int i=0; i<nx; i++){
                if(i==0) {
                    if(x[0]-nf/2>0) { a = false; break;}
                } else if(i==nx-1){
                    if(x[i]+nf/2<75 || x[i]-nf/2 > x[i-1]+nf/2) a = a && false;
                } else{
                    if(x[i]-nf/2 > x[i-1]+nf/2){ a = a && false; break; }
                }
            }
            for(int i=0; i<ny; i++){
                if(i==0) {
                    if(y[0]-nf/2>0) { b = false; break;}
                } else if(i==ny-1){
                    if(y[i]+nf/2<100 || y[i]-nf/2 > y[i-1]+nf/2) b = b && false;
                } else{
                    if(y[i]-nf/2 > y[i-1]+nf/2){ b = b && false; break; }
                }
            }
            if(a&&b) cout << "YES" << endl;
            else cout << "NO" << endl;
            a = b = true;
        }
    }
    return 0;
}
