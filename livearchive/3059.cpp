/*************************************************************************************************************************
 * 3059 - Speed Limit
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=199&page=show_problem&problem=1060
 *
 * Author:
 *   Rafael Sepúlveda
 *
 * Description:
 *   Dado un set de velocidades y lapsos de tiempo, determinar el total de millas recorridas. La única dificultad del problema
 * que los tiempos del set son todos dados respecto al inicio y no por intervalos.
 */

#include <iostream>

using namespace std;

struct par{
    int vel;
    int time;
};

int main(int argc,char **argv){
    while(1){
        int n;
        cin >> n;
        if(n==-1)break;

        par estudio[n];

        for(int i=0;i<n;i++){
            cin >> estudio[i].vel;
            cin >> estudio[i].time;
        }

        int total=0;
        for(int j=0;j<n;j++){
            if(j==0)total=estudio[j].vel*estudio[j].time;
            else total+=estudio[j].vel*(estudio[j].time-estudio[j-1].time);
        }

        cout << total << " miles" << endl;



    }
    return 0;
}
