/*************************************************************************************************************************
 * 10405
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
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int LCS(string X,string Y)
{
     if(X.empty() || Y.empty())
        return 0;

     if (Y.length() > X.length())
        swap(X,Y);
     int m = X.length(),n=Y.length();
     vector< vector<int> > c(2, vector<int>(n+1,0));
     int i,j;
     for (i=1;i<=m;i++)
     {
         for (j=1;j<=n;j++)
         {
             if (X[i-1]==Y[j-1])
                c[1][j]=c[0][j-1]+1;
             else
                 c[1][j]=max(c[1][j-1],c[0][j]);
         }
    	 for (j=1;j<=n;j++)
    		 c[0][j]=c[1][j];
     }
     return (c[1][n]);
}

int main(void) {
    string s1, s2;
    while(getline(cin, s1)) {
        getline(cin, s2);
        cout << LCS(s1, s2) << endl;
    }
    return 0;
}
