#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

/****************************************************************************
 * 3093 - Ip Adress
 *http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=1094 *
 *Este problema consistia en pasar un string de 32 unos y ceros a 4 numeros binarios de 8 bits cada uno. 
 *Lo mas dificil es la conversion de binario a decimal, para la cual se utilizo una funcion, y el manejo de strings a enteros.
 *Como en este caso eran solo 1's y 0's lo hice en un ciclo para no ocupar funciones de conversion. Ver Codigo.
 *			Saludos
 *                                                      -- Benjamin Diaz
 *
 */

int potencia(int x){
	int i;
	int y=1;
	if (x==0) return y;
	for(i=0;i<x;i++) y=y*2;
	return y;
}


int main(int argc, char argv[]){
	int n;
	cin >> n;
	
while(n>0){
	string str;
	cin >>str;
	int i;
	int cont =7;
	string s1,s2,s3,s4;
	int A[7],B[7],C[7],D[7];
	int x=0,y=0,z=0, w=0;
	s1=str.substr(0,8);
	s2=str.substr(8,8);
	s3=str.substr(16,8);
	s4=str.substr(24,8);
		
	
	for (i=0;i<8;i++){
		
		if(s1[i]=='1'){
			A[i]=1;
			}
		if(s1[i]=='0'){
			A[i]=0;
		}
		if(s2[i]=='1'){
			B[i]=1;
			}
		if(s2[i]=='0'){
			B[i]=0;
		}	
		if(s3[i]=='1'){
			C[i]=1;
		}
		if(s3[i]=='0'){
			C[i]=0;
		}
		if(s4[i]=='1'){
			D[i]=1;
		}
		if(s4[i]=='0'){
			D[i]=0;
		}

	}
	

		
	for (int j=0;j<8;j++){
		
		x=x+A[j]*potencia(cont);
		y=y+B[j]*potencia(cont);
		z=z+C[j]*potencia(cont);
		w=w+D[j]*potencia(cont);
		
		cont --;
	}
	
	cout << x <<"."<<y<<"."<<z<<"."<<w<<endl;

	n --;
}
return 0;
}
