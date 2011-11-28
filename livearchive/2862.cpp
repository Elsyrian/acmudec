/****************************************************************************
 * 2862 - Series Determination
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=863
 *
 * El problema consiste en calcular el valor de 3 funciones f(3),f(4),f(5).
 * En el input del problema dan los valores de f(0),f(1),f(2) y en la especificacion
 * del problema se da que f(x) = A*x^2+B*x+C por lo que se debe determinar A,B,C y
 * calcular los valores de f(3),f(4),f(5).
 *                                                      -- Rodrigo Castro
 *
 */
#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char **argv){
	int d, e, f;
	int A, B, C;
	while(scanf("%d %d %d",&d,&e,&f)!=EOF){
		C = d;
		A = (f+d-2*e)/2;
		B = (4*e-3*d-f)/2;
		cout << (int)(A*9+B*3+C) << " ";
		cout << (int)(A*16+B*4+C) << " ";
		cout << (int)(A*25+B*5+C) << endl;		
	}
	return 0;
}
