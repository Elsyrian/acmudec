#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

/****************************************************************************
 * 4810 - Flowers Flourish from France
 *http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=2811
 *
 * El problema consiste en saber si en una linea dada, todas las palabras comienzan con la misma letra. Para ello se hace
 * un getline para obtener a linea y cada vez que se encuetra un espacio se va almacenando en un arreglo de char el caracter siguiente
 * al espacio. La unica complicacion entre comillas, es cuando hay minusculas y mayusculas, para ello ocupe la funciona tolower(),
 * que traspasa todo el contenido del string a minuscula. Saludos
 *											Benja Diaz. 
 *
 */


int main(int argc, char argv[]){
	string linea;	
	while(true){
	getline(cin,linea);
	if (linea=="*") break;
	int contador =1;
	int bit =0;
	char A[linea.length()];
	for(int i=0;i< linea.length(); i++ ){
		A[0]=linea[0];
		if(linea.at(i)==' '){
			
			A[contador]=linea[i+1];
			contador ++;
		}
	}

	
	for (int j=0;j<contador;j++){
		A[j] = tolower(A[j]);
		if(A[j]!=A[0])bit=1;	
		}
		
		if (bit==1) cout<<"N"<<endl;
		else cout << "Y"<<endl;
	}
	return 0;
	}
	
	
	

