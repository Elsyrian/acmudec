/*************************************************************************************************************************
 * 539
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
#define MAX 25
using namespace std;

vector<int> edges[MAX];
bool vis[MAX][MAX];

int dfs(int x, int l) {
    int mx = l;
    for(int i = 0; i < edges[x].size(); i++) {
        if(!vis[x][edges[x][i]]) {
            vis[x][edges[x][i]] = true;
            vis[edges[x][i]][x] = true;
            mx = max(dfs(edges[x][i], l+1), mx);
            vis[x][edges[x][i]] = false;
            vis[edges[x][i]][x] = false;
        }
    }



    return mx;
}

int main(void) {
    int n_nodes, n_edges;
    int node1, node2;

    while(1) {
        cin >> n_nodes >> n_edges;
        if(n_nodes == 0 && n_edges == 0)
            break;

        for(int i = 0; i < n_nodes; i++)
            edges[i].clear();

        while(n_edges--) {
            cin >> node1 >> node2;
            edges[node1].push_back(node2);
            edges[node2].push_back(node1);
        }


        int mx = 0;
        for(int i = 0; i < n_nodes; i++) {
            memset(vis, false, sizeof(vis));
            mx = max(dfs(i, 0), mx);
        }

        cout << mx << endl;
    }
}
