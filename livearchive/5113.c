/****************************************************************************
 5113 - Cookie Piles
 http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=3114


						-Gabriela Lártiga
****************************************************************************/
#include <stdio.h>
int main(void){
int N, A, D;
int cases;
int sum;
int i, aux;
scanf("%i", &cases);

	while(cases>0){
		scanf("%i %i %i ", &N, &A, &D);
		
		if(N==1){
			sum=A;
		}

		else{
			for(i=1;i<N;i++){ 
				aux=A; 
				A=aux+D; 
				if(i==1){
					sum=aux; 
					sum=sum+A; 
				}
				if(i!=1){
					sum=sum+A; 
				}
			}
		}
	
	printf("%i\n", sum);
	cases--;
	}
return 0;
}
