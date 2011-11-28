/****************************************************************************
 * 3719 - Grass is Green
 * http://acmicpc-live-archive.uva.es/nuevoportal/data/problem.php?p=3719
 * (nueva) http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=1720
 *
 * El problema consiste en que se debe calcular cuanta gente puede comprar
 * un terreno cuadrado, con pasto y cerca, mas grande que el de uno.
 * La clave es sacar la formula matematica que permite calcular el lado del
 * cuadrado a comprar y compararlo con el resto.
 *                                                      -- Rodrigo Castro
 *
 */

#include <iostream>
#include <cmath>
using namespace std;
float calcX(float pasto, float valla, float terreno, float plata){
    return (sqrt(4*valla*valla + pasto*plata + terreno*plata)-2*valla)/(pasto + terreno);
}
int main(int argc, char **argv){
    int pers, acm;
    float terr, psto, vall, pta, Xm;
    while(true){
        acm = 0;
        cin >> pers;
        cin >> terr;
        if(pers==0 && terr==0) return 0;
        cin >> pta;
        cin >> psto;
        cin >> vall;
        Xm = calcX(psto,vall,terr,pta);
        for(int i=1; i<pers; i++){
            cin >> pta;
            cin >> psto;
            cin >> vall;
            if( calcX(psto,vall,terr,pta) > Xm ) acm++;
        }
        cout << acm << endl;
    }
    return 0;
}
