/*************************************************************************************************************************
 * 488
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

int main(void) {
    int cases;
    int i, j, k, l;
    int amplitude, freq;
    char num[2];

    cin >> cases;
    for(i = 0; i < cases; i++) {
        cin.getline(num, 2);
        cin >> amplitude >> freq;
        for(j = 0; j < freq; j++) {
            for(k = 1; k <= amplitude; k++) {
                for(l = 0; l < k; l++) {
                    cout << k;
                }
                cout << endl;
            }
            for(k = amplitude-1; k >= 1; k--) {
                for(l = 0; l < k; l++)
                    cout << k;
                cout << endl;
            }
            if(j != freq-1)
                cout << endl;
        }

        if(i != cases-1)
            cout << endl;

    }

    return 0;
}
