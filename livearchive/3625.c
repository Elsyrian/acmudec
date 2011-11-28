/*************************************************************************************************************************
 * 3625 - Rounders
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=99999999&category=19&page=show_problem&problem=1626
 *
 * Classification: Mathematics
 *
 * Author:
 *   Mathias Ercoreca
 *
 * Description:
 *   Programa simple donde se pedia redondear una serie de numeros
 *
 */

#include <stdio.h>
int main(){

	int Num,round,Numaux,mod,modaux;
	scanf("%i",&round);
	while(round>0){
		mod=10;
		scanf("%i",&Num);
		while(Num>mod){
			if(Num<=10){
				printf("%i",Num);
				break;
			}
			Numaux=Num%mod;
			modaux=mod/10;
			if(Numaux>4*modaux){
			Num=Num+mod-Numaux;
			}
			else if(Numaux<5*modaux){
				Num=Num-Numaux;
			}
			mod=mod*10;
		}
		printf("%i\n",Num);
		round--;
	}
	return 0;
}
