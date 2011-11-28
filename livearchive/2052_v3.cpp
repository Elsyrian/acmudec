/*************************************************************************************************************************
 * 2052 - Number Steps
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=53
 *
 * Author:
 *   Benjamín Díaz
 *   Rafael Sepúlveda
 *
 * Description:
 *   Dado un par de numeros indicando las cordinadas en el plano, determinar si el punto pertenece a una serie indicada en el problema
 */

#include <iostream>

using namespace std;

int main(int argc, char **argv){
	int N;
	cin >> N;

	for(int i=0;i<N;i++){
	    int x,y;

		cin >> x;
		cin >> y;

		if(x==y || x==y+2){
		    int out;
            if(x%2==0)out=x+y;

            else out=x+y-1;

            cout << out << endl;
        }

        else cout << "No Number" << endl;
	}

	return 0;
}
