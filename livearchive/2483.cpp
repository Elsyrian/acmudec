/*************************************************************************************************************************
 * 2483 - House Numbering
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=7&page=show_problem&problem=484
 *
 * Classification: String Processing
 *
 * Author:
 *   Edgardo Moreno     <egyware@gmail.com>
 *   Stephano Beneventi <stephano.bg@gmail.com>
 *   Kristoffer Ulloa	<rewpoke@gmail.com>
 *
 * Description:
 *   Este problema es sencillo, dados los costos de un escribir un cero (A) y escribir un uno (B)
 * se debe calcular el costo de escribir un numero natural en binario. Primero se transforma el numero
 * natural a binario, y durante ese proceso se realiza la sumatoria de los costos de escritura.
 *
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main(){
	int a,b;
	int i,set=0;
	int numero,precio;
	char palabra[8];
	char c;

	scanf("%c",&c);
	while (1){
		if(c=='#'){
			break;
		}
		else {
				set++;
				printf("Set %d\n",set);
				while(c!=' '){
					scanf("%c",&c);
				}
				scanf("%c",&c);
				i=0;
				while(c!=' '){
					palabra[i]=c;
					scanf("%c",&c);
					i++;
				}
				palabra[i]=c;
				a=atoi(palabra);
				scanf("%c",&c);
				i=0;
				while(c!='\n'){
					palabra[i]=c;
					scanf("%c",&c);
					i++;
				}
				palabra[i]=c;
				b=atoi(palabra);
				scanf("%c",&c);
				while(c!='#' && c!='C'){
					i=0;
					while(c!='\n'){
						palabra[i]=c;
						scanf("%c",&c);
						i++;
					}
					palabra[i]=c;
					numero=atoi(palabra);
					precio=0;
					while(numero!=0){
						if(numero%2==0)precio=precio+a;
						else precio=precio+b;
						numero=numero/2;
					}
					printf("%d\n",precio);
					scanf("%c",&c);
			}
		}
	}
}
