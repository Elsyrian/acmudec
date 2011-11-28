/*************************************************************************************************************************
 * 10048
 * 
 *
 * Classification: Warshall Min-Max
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
#include <stdlib.h>
#include <stdio.h>
#include <climits>
#define INF 100000
#define MAX 210
using namespace std;

int decibel[MAX+1][MAX+1];
void Warshall() {
    for(int k = 1; k < MAX+1; k++) {
        for(int i = 1; i < MAX+1; i++) {
            for(int j = 1; j < MAX+1; j++) {
                decibel[i][j] = min(decibel[i][j], max(decibel[k][j], decibel[i][k]));
            }
        }
    }
}

int main(int argc, char** argv) {
    int C, S, Q;
    int c1, c2, d;
    int cases = 1;
    bool blank = false;
    while(1) {
        cin >> C >> S >> Q;
        if(C == 0 && S == 0 && Q == 0)
            break;
	
        for(int i = 1; i < MAX+1; i++) {
	    for(int j = 1; j < MAX+1; j++) {
		decibel[i][j] = INT_MAX;
	    }
	}
	
        for(int i = 0; i < S; i++) {
            cin >> c1 >> c2 >> d;
            decibel[c1][c2] = d;
            decibel[c2][c1] = d;
        }
	
	Warshall();
        
	if(blank)
	   cout << endl;
	blank = true;
	
	cout << "Case #" << cases++ << endl;
        for(int i = 0; i < Q; i++) {
            cin >> c1 >> c2;
	    if(decibel[c1][c2] != INT_MAX)
	      cout << decibel[c1][c2] << endl;
	    else
	      cout << "no path" << endl;
        }
    }
    return 0;
}

