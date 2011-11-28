/*************************************************************************************************************************
 * 2362 - Financial Management
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=363
 *
 * Author:
 *   Benjamín Díaz
 *   Rafael Sepúlveda
 *
 * Description:
 *   Problema simple en el que se pide calcular un promedio entre números flotantes
 *
 */

#include <iostream>

using namespace std;

int main(int argc, char **argv){

    float nums[12];
    for(int i=0;i<12;i++)cin >> nums[i];
    float suma=0;
    for(int i=0;i<12;i++)suma+=nums[i];
    float prom=suma/12;
    cout << "$" << prom << endl;
    return 0;
}
