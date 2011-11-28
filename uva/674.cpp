/*************************************************************************************************************************
 * 674
 * 
 *
 * Classification: Dynamic Programming
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
#define NUM_COIN 5
#define MAX 7489
using namespace std;

int coin[5] = {1, 5, 10, 25, 50};
long long nway[MAX+1];

int main(void) {
    memset(nway, 0, sizeof(nway));
    nway[0] = 1;
    for(int i = 0; i < NUM_COIN; i++) {
        for(int j = coin[i]; j < MAX+1; j++) {
            nway[j] += nway[j-coin[i]];
        }
    }
    int n;
    while(cin >> n) {
        cout << nway[n] << endl;
    }
    return 0;
}
