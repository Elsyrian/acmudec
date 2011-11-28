/*************************************************************************************************************************
 * 575
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

#include <iostream>
#include <string.h>
#define MAX 100
using namespace std;

int myPow(int n) {
    int i;
    int result = 1;
    for(i = 0; i < n; i++)
        result *= 2;
    return (result-1);
}

void reverse(char* n) {
    int i, j;
    char tmp;
    for(i = 0, j = strlen(n)-1; i < j; i++, j--) {
        tmp = n[i];
        n[i] = n[j];
        n[j] = tmp;
    }
}

long long decimal(char* n) {
    long long result = 0;
    int i;
    reverse(n);
    for(i = 1; i <= strlen(n); i++) {
        result += (myPow(i) * (int)(n[i-1]-'0'));
    }
    return result;
}

int main(void) {
    char n[MAX+1];
    while(cin >> n) {
        if(n[0] == '0')
            break;
        cout << decimal(n) << endl;
    }

}
