/*********************************************************
* 5118 - Always Follow the Rules in Zombieland 
* http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=34&page=show_problem&problem=3119
*
*
* Programa que pedia almacenar strings como reglas y luego preguntar
* por ellas, de existir tenia que entregar la regla, si no, imprimir
* "No such rule", bastante facil, pero era de zombies no podias decirle
* que no.
*
*
*                                      -- Mathias Ercoreca
*
*/

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main(){
    string A[51];
    char B[66];
    int rules,i,k,s,j;
    s=0;
    k=0;
    j=0;
    cin >> rules;
    for(i=0;i<=rules;i++){
        cin.getline(B,65,'\n');
        A[i] = B;
    }
    cin >> k;
    while(k>0){
        cin >> s;
        if(s<=i-1 && s>0){
            for(j=0;j<51;j++){
                if(s==j){
                    cout << "Rule " << j <<": " << A[j] << "\n";
                }
            }
        }
        if(s>i-1 || s<=0){
            cout << "Rule " << s <<": No such rule\n";
        }
        k--;
    }
    return 0;
}
