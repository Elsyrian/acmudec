/*************************************************************************************************************************
 * 490
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
#include <stdio.h>
#define MAX 100
using namespace std;

int main(void) {
    char map[MAX+1][MAX+1];
    char tmp[MAX+1];
    int max = 0;
    int i, j, k;

    i = 0;
    while(cin.getline(tmp, MAX+1)) {
        strcpy(map[i], tmp);
        if(max < strlen(map[i]))
            max = strlen(map[i]);

        i++;
        if(i == 7)
            break;
    }

    for(k = 0; k < max; k++) {
        for(j = i-1; j >= 0; j--) {
            if(k < strlen(map[j]))
                cout << map[j][k];
            else
                cout << " ";
        }
        cout << endl;
    }
}
