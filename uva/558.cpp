/*************************************************************************************************************************
 * 558
 * 
 *
 * Classification: Bellmand-Ford, Ciclos negativos
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
#include <string.h>
#include <algorithm>
#define INF 10000
#define MAX 3000
using namespace std;

vector< vector<int> > el;
vector<int> tmp(3);
int v, e, dist[MAX];

int main(void) {
    int cases;
    cin >> cases;
    while(cases--) {
        cin >> v >> e;
        el.clear();
        for(int i = 0; i < e; i++) {
            cin >> tmp[0] >> tmp[1] >> tmp[2];
            el.push_back(tmp);
        }
        memset(dist, INF, sizeof(dist));
        dist[0] = 0;
        for(int i = 0; i < v; i++) {
            for(int j = 0; j < el.size(); j++) {
                dist[el[j][1]] = min(dist[el[j][0]] + el[j][2], dist[el[j][1]]);
            }
        }
        bool bIsPossible = false;
        for(int i = 0; i < e; i++) {
            if(dist[el[i][1]] > dist[el[i][0]] + el[i][2]) {
                bIsPossible = true;
                break;
            }
        }
        if(bIsPossible)
            cout << "possible" << endl;
        else
            cout << "not possible" << endl;
    }

    return 0;
}
