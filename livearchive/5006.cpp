/*************************************************************************************************************************
 * 5006 - Binary Number
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=33&page=show_problem&problem=3007
 *
 * Classification: Mathematics
 *
 * Author:
 *   Stephano Beneventi <stephano.bg@gmail.com>
 *
 * Description:
 *   Dados 2 conjuntos de numeros binarios A y B y una funcion f que calcula el numero
 * de bits distintos de 2 numeros binarios, que recibe como entrada 2 naturales,
 * hay que calcular para cada elemento de B el elemento de A que minimiza el valor de f,
 * y ademas imprimirlo en pantalla.
 *
 */

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int f(int a, int b){
	int dif=0;
	int may,min;
	if(a<b)	{may=b;min=a;}
	else	{may=a;min=b;}
	while(min>0){
		if(may%2!=min%2){
			dif++;
		}
		min=min/2;
		may=may/2;
	}
	while(may>0){
		if(may%2)dif++;
		may=may/2;
	}
	return dif;
}

int main(){

	int casos;
	int n,m;
	int i,j,k;
	int temp;
	vector<int> A;
	vector<int> B;
	int min,mini;

	scanf("%d",&casos);

	for(i=0;i<casos;i++){
		scanf("%d %d",&m,&n);

		for(j=0;j<m;j++){
			scanf("%d",&temp);
			A.push_back(temp);
		}

		sort(A.begin(),A.begin()+m);

		for(j=0;j<n;j++){
			scanf("%d",&temp);
			B.push_back(temp);
		}

		for(j=0;j<n;j++){
			min=10000000;
			for(k=0;k<m;k++){
				temp=f(A[k],B[j]);
				if(temp<min){
					min=temp;
					mini=k;
				}
			}
			printf("%d\n",A[mini]);
		}
		A.clear();
		B.clear();
	}
}
