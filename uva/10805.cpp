/*************************************************************************************************************************
 * 10805
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
using namespace std;

int main(void) {
    int inputs;
    int cases = 1;
    int n, k, p;

    cin >> inputs;
    while(inputs--) {
        cin >> n >> k >> p;
        vector<int> players;
        for(int i = 1; i <= n; i++) {
            players.push_back(i);
        }

        int player = k;
        for(int j = 0; j < p; j++) {
            if(player == n) {
                player = 1;
            } else {
                player++;
            }
        }
        cout << "Case " << cases++ << ": " << player << endl;
    }
}

