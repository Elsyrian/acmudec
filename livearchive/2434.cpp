#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctype.h>

/*************************************************************************************************************************
 * 2434 - Money Lesson
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=342&page=show_problem&problem=435
 *
 * Classification: AdHoc
 *
 * Author:
 *   Benjamin Diaz <benjadiaz@udec.cl>
 *
 * Description:
 *  El problema consiste en saber quien de los n alumnos tiene mas dinero y quien tiene menos.
 *  Cada alumno tiene tres tipos de monedas y hay que acer la suma para saber el total. Para ello se ocuparon 
 *  estructuras para cada alumno que contengan cada una el nombre y el total de dinero del alumno. Asi
 *  despues se busca el maximo con un algoritmo simple y el minimo tambien. Si todos son iguales se modifica 
 *  un bit de igualdad que indica que todos tienen la misma cantidad. Eso . Saludos
 *
 */

using namespace std;


int main(int argc, char argv[]){
	struct persona{
		string nombre;
		int total;
	};
	
	int n=0;
	
	int medio,uno,dos;
	while (true){
		cin >> n;
		if (n==-1)break;
		persona aux[n];
		string nombre;
		int uno;
		int medio;
		int dos;
		for(int i=0;i<n;i++){
			cin >> nombre;
			cin >> medio;
			cin >> uno;
			cin >> dos;
			aux[i].nombre=nombre;
			aux[i].total=0;
			aux[i].total=aux[i].total+medio+2*uno+4*dos;
			uno=0;
			medio=0;
			dos=0;
		}
		persona max, min;
		int bit=0;
		max.total=aux[0].total;
		max.nombre=aux[0].nombre;
		min.nombre=aux[0].nombre;
		min.total=aux[0].total;		
		for (int j=1;j<n;j++){
			if (aux[j-1].total!=aux[j].total) bit =1;
			if (max.total<aux[j].total) {
				max.total=aux[j].total;
				max.nombre=aux[j].nombre;
			}
			if (min.total>aux[j].total){ 
				min.total=aux[j].total;
				min.nombre=aux[j].nombre;
			}
		}
		
		if(bit==0) cout << "All have the same amount." << endl;
		else{
			cout<< max.nombre << " has most, " << min.nombre << " has least money."<< endl;
		} 
	}
	
		



	return 0;
	}
	
	
	

