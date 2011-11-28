
#include <iostream>
using namespace std;

/****************************************************************************
 * 4197 - Combination Lock
 *http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=2198
 *
 * El problema consiste en encontrar el maximo de giros que se le realiza a un candado para
 * Poner la contraseña consistente en tres numeros. No tiene ninguna dificultad de programacion
 * , la dificultad esta en encontrar la formula matematica. Saludos, este entrete este.
 *                                                      -- Benjamin Diaz
 *
 */

int mod1(int x, int y){
	int r = x-y;
	if (r<0) r=r*(-1);
		return r;
}

int main(int argc, char argv[]){
	int x,y,z,w,c,v;
	int N,T1,T2,T3;
	int A[4];
while(true){
	for(int i=0;i<4;i++){
		cin>>A[i];
	}
	if(A[0]==0 && A[1]==0 && A[2]==0 && A[3]==0) break;
	y=0;
	x=0;
	z=0;
	w=0;
	c=0;
	v=0;
	N=A[0];
	T1=A[1];
	T2=A[2];
	T3=A[3];
	
	x=3*N;
	w=N-1;
	
		c=mod1(T1,T2);
		v=mod1(T2,T3);
	
	if(T1<T2) y=c;
	if(T1>T2) y=N-c;
	if(T2<T3) z=N-v;
	if(T2>T3) z=v;
	
	
	cout<< x+y+z+w << endl;
	
	
	
		
	

}

return 0;
}