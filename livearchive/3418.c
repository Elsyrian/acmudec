/*************************************************************************************************************************
 * 3418 - Shuffle'm Up
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=99999999&category=17&page=show_problem&problem=1419
 *
 * Classification: Comparacion?
 *
 * Author:
 *   Mathias Ercoreca
 *
 * Description:
 *   Se tenian 2 pilas de fichas, las cuales se mezclaban de forma unforme
 *  (la ultima de la 2º pila primero, luego la ultima de la 1º pila y asi sucesivamente)
 *  con esto se creaba una pila mas grande, la cual se dividia a la mitad y se repetia
 *  el proceso. La idea era detectar si alguna vez llegaba a alguna configuracion dada por el
 *  input y cuantas repeticiones requeria.
 */


#include <stdio.h>
#include <string.h>
int main(){

	int data,large,i,j,times,large2,l,k;
	char S1[101],S2[101],S12[202],S12F[202],S12T[20000][202];
	scanf("%i",&data);
	for(k=0;k<data;k++){
		for(i=0;i<101;i++){
			S2[i]='\0';
			S1[i]='\0';
		}
		for(i=0;i<202;i++){
			S12[i]='\0';
			S12F[i]='\0';
		}
		for(j=0;j<20000;j++){
			for(i=0;i<202;i++){
			S12T[j][i]='\0';
			}
		}
		scanf("%i",&large);
		scanf("%s",S1);
		scanf("%s",S2);
		scanf("%s",S12F);
		i=0;
		j=0;
		large2=large*2;
		while(i<large2){
			S12[i]=S2[j];
			S12T[0][i]=S2[j];
			i++;
			S12[i]=S1[j];
			S12T[0][i]=S1[j];
			i++;
			j++;
		}
		times=1;
		if(strcmp(S12,S12F)==0){
			printf("%i %i\n",k+1,times);
			goto fuera;
		}

		while(1){
			for(i=0;i<large;i++){
				S1[i]=S12[i];
				l=i+large;
				S2[i]=S12[l];
			}
			i=0;
			j=0;
			while(i<large2){
				S12[i]=S2[j];
				S12T[times][i]=S2[j];
				i++;
				S12[i]=S1[j];
				S12T[times][i]=S1[j];
				i++;
				j++;
			}
			times++;
			if(strcmp(S12,S12F)==0){
				printf("%i %i\n",k+1,times);
				break;
			}
			for(i=0;i<times-1;i++){
				if(strcmp(S12T[i],S12)==0){
					printf("%i -1\n",k+1);
					goto fuera;
				}
			}
		}
	fuera:;
	}
	return 0;
}
