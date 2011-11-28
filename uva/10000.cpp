/*************************************************************************************************************************
 * 10000
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
#include <string.h>
#define MAX 101
using namespace std;

int N;
int dist[MAX][MAX];

void Warshall() {
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(dist[i][k] != 0 && dist[k][j] != 0)
                    dist[i][j] = max(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main(void) {
    int s;
    int source, final;
    int cases = 1;


    while(1) {
        cin >> N;
        if(N == 0)
            break;

        cin >> s;
        memset(dist, 0, sizeof(dist));
        while(1) {
            cin >> source >> final;
            if(source == 0 && final == 0)
                break;
            dist[source][final] = 1;
        }

        Warshall();

        int mx = 0;
        int d = 0;
        for(int i = 1; i <= N; i++) {
            if(mx < dist[s][i]) {
                mx = dist[s][i];
                d = i;
            } else if(mx == dist[s][i] && d > i) {
                d = i;
            }
        }

        cout << "Case " << cases++ << ": The longest path from " << s << " has length " << mx << ", finishing at " << d << "." << endl << endl;
    }
    return 0;
}
