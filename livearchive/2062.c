/*************************************************************************************************************************
 * 2062 - Easier Done than Said?
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=63
 *
 * Classification:
 *
 * Author:
 *   Gabriela Lartiga <gabyganihonjindayo@gmail.com>
 *
 * Description:
 *
 *  El programa conciste en verificar si las claves entregadas son aceptadas o rechazadas
 * de acuerdo a ciertos parametros entregados en el problema.
 *
 */

#include <stdio.h>
#include <string.h>

int main(){
	char pass[21];
	int i;
	int acceptable;
	int hasvowel;

	while(1){
		scanf("%s", &pass[0]);

		if(pass[0]=='e' && pass[1]=='n' && pass[2]=='d') return 0;

		acceptable=0;
		hasvowel=0;

		for(i=0;i<strlen(pass);i++){
			if((pass[i]==pass[i+1])&&(pass[i]!='e')&&(pass[i]!='o')){
				printf("<%s> is not acceptable.\n", pass);
				acceptable++;
				goto jump;
			}
		}

		for(i=0;i<strlen(pass);i++){
			if(pass[i]=='a'){ hasvowel++;}
			if(pass[i]=='e'){ hasvowel++;}
			if(pass[i]=='i'){ hasvowel++;}
			if(pass[i]=='o'){ hasvowel++;}
			if(pass[i]=='u'){ hasvowel++;}
		}
		if(hasvowel==0){
			printf("<%s> is not acceptable.\n", pass);
			acceptable++;
			goto jump;
		}
		if((strlen(pass)-1)!=0){
		for(i=0;i<strlen(pass)-2;i++){

			if(pass[i]!='a'&&pass[i]!='e'&&pass[i]!='i'&&pass[i]!='o'&&pass[i]!='u'){
				if(pass[i+1]!='a'&&pass[i+1]!='e'&&pass[i+1]!='i'&&pass[i+1]!='o'&&pass[i+1]!='u'){
					if(pass[i+2]!='a'&&pass[i+2]!='e'&&pass[i+2]!='i'&&pass[i+2]!='o'&&pass[i+2]!='u'){
						printf("<%s> is not acceptable.\n", pass);
						acceptable++;
						goto jump;
					}
				}
			}
			if(pass[i]=='a'||pass[i]=='e'||pass[i]=='i'||pass[i]=='o'||pass[i]=='u'){
				if(pass[i+1]=='a'||pass[i+1]=='e'||pass[i+1]=='i'||pass[i+1]=='o'||pass[i+1]=='u'){
					if(pass[i+2]=='a'||pass[i+2]=='e'||pass[i+2]=='i'||pass[i+2]=='o'||pass[i+2]=='u'){
						printf("<%s> is not acceptable.\n", pass);
						acceptable++;
						goto jump;
					}
				}
			}
		}
		}
		jump:
		if(acceptable==0){
			printf("<%s> is acceptable.\n", pass);
		}

	}
	return 0;
}
