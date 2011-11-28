/*************************************************************************************************************************
 * 10055
 * 
 *
 * Classification:
 *
 * Author:
 *   Javier Gonzalez Nova <javigonzalez@udec.cl>
 *
 * Description:
 *
 *
 */

#include <stdio.h> /*scanf*/
#include <stdlib.h> /*abs*/
#include <iostream> /*cout*/
using namespace std;

int main(void) {
    long long n1, n2; /*Numero de soldados aliados y oponentes*/
    while(scanf("%lld", &n1) != EOF) {
        scanf("%lld", &n2);
        if(n1 < n2)
            cout << n2-n1 << endl;
        else
            cout << n1-n2 << endl;
    }
}
