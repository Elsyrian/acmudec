/*************************************************************************************************************************
 * 10474
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
#include <algorithm>
using namespace std;

int findMarble(vector<int> M, int n) {
    int i;
    for(i = 0; i < M.size(); i++) {
        if(M[i] == n)
            return i;
    }
    return -1;
}

int main(void) {
    int N, Q;
    int cases = 1;
    int tmp, pos;
    vector<int> Marbles;

    while(1) {
        cin >> N >> Q;
        if(N == 0 && Q == 0)
            break;
        Marbles.clear();
        while(N--) {
            cin >> tmp;
            Marbles.push_back(tmp);
        }
        sort(Marbles.begin(), Marbles.end());
        cout << "CASE# " << cases++ << ":" << endl;
        while(Q--) {
            cin >> tmp;
            pos = findMarble(Marbles, tmp);
            if(pos == -1)
                cout << tmp << " not found" << endl;
            else
                cout << tmp << " found at " << pos+1 << endl;
        }
    }

    return 0;
}
