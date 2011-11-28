/*********************************************************
* 2107 - Double, Double, Toil and Trouble
* http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=108
*
* El problema consiste en verificar si con los datos del input se puede
* saber si los datos corresponden a un area segura, para lo cual de acuerdo
* con el problema se verifican 2 ecuaciones a ver si se cumplen.
*
*                                      -- Rodrigo Castro
*
*/
#include <iostream>
using namespace std;
double calc(float a, float b, float T,float V){
    return ( a*T + b*V);
}
int main(int argc, char **argv){
    int c=0,i;
    double a1,a2,a3,a4,b1,b2,b3,b4,c1,c2,c3,c4,T,V;
    bool safe = true;
    cin >> c;
    for(i=1;i<=c;i++){
        cin >> a1; cin >> b1; cin >> c1;
        cin >> a2; cin >> b2; cin >> c2;
        cin >> a3; cin >> b3; cin >> c3;
        cin >> a4; cin >> b4; cin >> c4;
        cin >> T; cin >> V;

        if(calc(a1,b1,T,V)>=c1) safe = safe & true;
        else safe = safe & false;

        if(calc(a2,b2,T,V)>=c2) safe = safe & true;
        else safe = safe & false;

        if(calc(a3,b3,T,V)<=c3) safe = safe & true;
        else safe = safe & false;

        if(calc(a4,b4,T,V)<=c4) safe = safe & true;
        else safe = safe & false;

        if(safe)
            cout << i << " SAFE" << endl;
        else
            cout << i << " UNSAFE" << endl;
        safe = true;
    }
    return 0;
}
