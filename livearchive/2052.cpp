/*************************************************************************************************************************
 * 2052 - Number Steps
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=53
 *
 * Classification: Mathematics
 *
 * Author:
 *   Edgardo Moreno     <egyware@gmail.com>
 *   Stephano Beneventi <stephano.bg@gmail.com>
 *   Kristoffer Ulloa	<rewpoke@gmail.com>
 *
 * Description:
 *   La idea de este problema es que dada una numeracion del espacio finito {y=x-1, y=x} , con x,y en los naturales
 * que el programa reciba un par de coordenadas (x,y) y si se cumple y=x-1 o y=x que imprima el numero correspondiente
 * a la numeracion, en caso contrario que imprima "No Number".
 *
 */

#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	int x,y,casos;
	int resp;
	scanf("%d",&casos);
	for(int i=0;i<casos;i++){
		scanf("%d %d",&x,&y);
		if(x==y || x==y+2){
            if(x%2==0)resp=x+y;
            else resp=x+y-1;
            printf("%d\n",resp);
        }
        else printf("No Number\n");
	}
}
