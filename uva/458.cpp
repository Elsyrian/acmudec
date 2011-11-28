/*************************************************************************************************************************
 * 458
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
using namespace std;

#define MAX 1000

char* decode(char* text) {
    int i;
    for(i = 0; text[i]; i++)
        text[i] -= 7;
    return text;
}

int main(void) {
    char text[MAX+1];

    while(cin >> text) {
        cout << decode(text) << endl;
    }

    return 0;
}
