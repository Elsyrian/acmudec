/*************************************************************************************************************************
 * 10397
 * 
 *
 * Classification: MST
 *
 * Author:
 *   Javier Gonzalez Nova <javigonzalez@udec.cl>
 *
 * Description:
 *
 *
 */

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#define MAX 750
using namespace std;

int N;
double d[10000];
double weight[MAX+1][MAX+1];
char inTree[10000];

typedef struct {
  double x;
  double y;
} Point;

/*Prim*/
void updateDist(int target) {
 for(int i = 1; i <= N; i++) {
  if((weight[target][i] != -1) && (d[i] > weight[target][i])) {
   d[i] = weight[target][i];
  }
 }
}	

double dist(Point n1, Point n2) {
  return (sqrt( ((n1.x-n2.x)*(n1.x-n2.x)) + ((n1.y-n2.y)*(n1.y-n2.y))) );
}

int main(void) {
  while(cin >> N) {
    Point buildings[N];
    for(int i = 1; i <= N; i++) {
      cin >> buildings[i].x >> buildings[i].y;
    }
    int cables;
    cin >> cables;
    
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {	
	weight[i][j] = -1;
      }
    }
    
    for(int i = 0; i < cables; i++) {
      int c1, c2;
      cin >> c1 >> c2;
      weight[c1][c2] = weight[c2][c1] = 0;
    }
    
    for(int i = 1; i <= N; i++) {
     for(int j = 1; j <= N; j++) {
	if(weight[i][j] == -1) {
	 weight[i][j] = dist(buildings[i],buildings[j]); 
	}
     }
    }
    
     for(int i = 1; i <= N; i++) {
      d[i] = 1000000;
      inTree[i] = 0;
     }
     
     /*Prim*/
     inTree[1] = 1;
     updateDist(1);
     double total = 0;
     for(int i = 2; i <= N; i++) {
      int mn = -1;
      for(int j = 1; j <= N; j++) {
	if(!inTree[j]) 
	 if((mn == -1) || (d[mn] > d[j]))
	   mn = j;
      }
	
      inTree[mn] = 1;
      total += d[mn];
      updateDist(mn);
     }
     
     
     printf("%.2f\n", total);
    }
    
  return 0; 
}
