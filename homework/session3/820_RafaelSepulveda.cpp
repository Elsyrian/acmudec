#include <string.h>
#include <iostream>
#include <queue>

using namespace std;

// the maximum number of vertices
#define NN 5

// adjacency matrix (fill this up)
int cap[NN][NN];

// flow network
int fnet[NN][NN];

// BFS
int q[NN], qf, qb, prev[NN];

int fordFulkerson( int n, int s, int t )
{
    // init the flow network
    memset( fnet, 0, sizeof( fnet ) );

    int flow = 0;
	cout << "caca" << endl;

    while(1)
    {
        // find an augmenting path
        memset( prev, -1, sizeof( prev ) );
        qf = qb = 0;
        prev[q[qb++] = s] = -2;
        while( qb > qf && prev[t] == -1 )
            for( int u = q[qf++], v = 0; v < n; v++ )
                if( prev[v] == -1 && fnet[u][v] - fnet[v][u] < cap[u][v] )
                    prev[q[qb++] = v] = u;

        // see if we're done
        if( prev[t] == -1 ) break;

        // get the bottleneck capacity
        int bot;
        for( int v = t, u = prev[v]; u >= 0; v = u, u = prev[v] )
            bot = cap[u][v] - fnet[u][v] + fnet[v][u];

        // update the flow network
        for( int v = t, u = prev[v]; u >= 0; v = u, u = prev[v] )
            fnet[u][v] += bot;

        flow += bot;
	cout << "Parcial: " << flow << endl;
    }

    return flow;
}

//----------------- EXAMPLE USAGE -----------------
int main(int argc, char** argv)
{
    memset( cap, 0, sizeof( cap ) );

    int numVertices;
	int s,t,c;
	int networknum = 0;
    cin >> numVertices;

	while (numVertices !=0){
		networknum++;
		int s,t,c;
		cin >> s;
		s--;
		t--;
		cin >> t;
		cin >> c;
		for(int i=0; i < c ;i++){
			int nod1,nod2,f;
			cin >> nod1;
			cin >> nod2;
			cin >> cap[nod1-1][nod2-1];	
			cap[nod2-1][nod1-1] = cap[nod1-1][nod2-1];

		}

		for(int i=0; i<NN;i++){
			for(int j=0; j<NN; j++){
				cout << cap[i][j] << " ";
			}
			cout << endl;
		}
		cout << "Network " << networknum << endl;
		int flow=fordFulkerson( numVertices, s, t );
		cout << "The bandwidth is " << flow << "." << endl;
		memset( cap, 0, sizeof( cap ) );
		cin >> numVertices;
	}
    
   
    
    
    return 0;
}

