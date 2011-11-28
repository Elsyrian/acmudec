/*************************************************************************************************************************
 * 4796 - Sudoku Checker
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=30&page=show_problem&problem=2797
 *
 * Classification: AdHoc
 *
 * Author:
 *   Stephano Beneventi <stephano.bg@gmail.com>
 *
 * Description:
 *   Dado un puzzle sodoku de S caracteres, revisar si este se rellenó correctamente.
 * Para ello primero se revisan los sub-cuadrados N*N, luego las filas y por último,
 * las filas. En cada uno de estos casos, se imprimen en pantalla los elementos faltantes
 * o repetidos junto con el numero del cuadrante, fila, o columna segun corresponda.
 * Y al final se imprime si el puzzle esta correcto o no.
 *
 */

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector <int>check;
int s,s2;
bool error=false;

void printError1(int tipo, bool fe, int block, int num){
	if(fe){
		if(tipo==0)
			printf("Square %d has no %ds",block,num);
		if(tipo==1)
			printf("Row %d has no %ds",block,num);
		if(tipo==2)
			printf("Column %d has no %ds",block,num);
	}
	else {
		if(tipo==0)
			printf(" and no %ds",num);
		if(tipo==1)
			printf(" and no %ds",num);
		if(tipo==2)
			printf(" and no %ds",num);
	}
}

void printError2(int tipo, int num1,int num2){
	if(tipo==0)
		printf(" and %d %ds",num1,num2);
	if(tipo==1)
		printf(" and %d %ds",num1,num2);
	if(tipo==2)
		printf(" and %d %ds",num1,num2);
}

void chequear(int tipo, int block){
	sort(check.begin(),check.begin()+s2);
	bool fe=true;
	int index=1;
	int i;

	for(i=0;i<s2;i++){
		if(index==check[i]){
			index++;
		}
		else if(index<check[i]){
			i--;
			printError1(tipo,fe,block,index);
			fe=false;
			index++;
		}
	}

	while(index<=s2){
		printError1(tipo,fe,block,index);
		fe=false;
		index++;
	}

	int count=0;
	int num=check[0];
	for(i=0;i<s2;i++){
		if(num==check[i]){
		count++;
		}
		else {
			if(count<=1){
				num=check[i];
			}
			else {
				printError2(tipo,count,num);
				num=check[i];
				count=1;
			}
		}
	}
	if(!fe){
		printf("\n");
		error=true;
	}
}

int main(){

	int sodoku[144][144];
	int casos;
	int temp;
	int gp,hp;
	int i,j,k,g,h;
	int num,count;
	scanf("%d",&casos);

	for(k=0;k<casos;k++){
		scanf("%d",&s);
		printf("Puzzle %d\n",k+1);
		s2=s*s;
		for (i=0;i<s2;i++){
			for (j=0;j<s2;j++){
				scanf("%d",&sodoku[i][j]);
			}
		}

		for(g=0;g<s;g++){
			gp=g*s;
			for(h=0;h<s;h++){
				hp=h*s;
				for(i=0;i<s;i++){
					for(j=0;j<s;j++){
						check.push_back(sodoku[gp+i][hp+j]);
					}
				}
				chequear(0,gp+h+1);
				check.clear();
			}
		}

		for(i=0;i<s2;i++){
			for(j=0;j<s2;j++){
				check.push_back(sodoku[i][j]);
			}
			chequear(1,i+1);
			check.clear();
		}

		for(i=0;i<s2;i++){
			for(j=0;j<s2;j++){
				check.push_back(sodoku[j][i]);
			}
			chequear(2,i+1);
			check.clear();
		}

		if(error)printf("The solution is invalid.\n");
		else printf("The solution is valid.\n");

		error=false;

	}
}
