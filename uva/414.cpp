/*************************************************************************************************************************
 * 414
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
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
    return (a > b);
}

int main(void) {
    char line[26];
    int n;
    int i;
    int voids;
    char* tmp;

    while(1) {
        cin >> n;
        if(n == 0)
            break;

        vector<int> rows(n, 0);
        rows.clear();
        for(i = 0; i < n; i++) {
            cin >> line;
            rows[i] += strlen(line);

            if(rows[i] < 25) {
                cin >> line;
                rows[i] += strlen(line);
            }
        }

        sort(rows.begin(), rows.begin()+n, compare);

        voids = 0;
        for(i = 1; i < n; i++) {
            voids += rows[0] - rows[i];
        }

        cout << voids << endl;
    }

    return 0;
}
