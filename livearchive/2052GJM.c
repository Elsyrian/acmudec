/******************************************************************
 * 2052 - Number Steps
 * http://livearchive.onlinejudge.org/external/20/2052.html
 *
 * Author(Grupo):
 *   Gabriela Lartiga   <gabyganihonjindayo@gmail.com>
 *   Jose Troncoso  <jostroncoso@udec.cl>
 *   Mathias Ercoreca <darksefirothh@gmail.com>
 *
 * Description:
 *
 */

#include <stdio.h>

int aaaah(int x){
if(x==0)
	return 0;
else if(x==1)
	return 1;
else if(x%2==0)
	return aaaah(x-2)+4;
else
	return aaaah(x-1)+1;
}

int bbbbh(int x){
if(x==0)
	return 2;
else if(x==1)
	return 3;
else if(x%2!=0)
	return bbbbh(x-1)+1;
else
	return bbbbh(x-2)+4;
}



int main(void){
int pas=0,i;
int x[2];
scanf("%i",&pas);
for(i=0;i<pas;i++){
scanf("%i %i",&x[1],&x[0]);
if(x[0]== x[1])
	printf("%i\n",aaaah(x[0]));
else if(x[0]+2== x[1])
	printf("%i\n",bbbbh(x[0]));
else
	printf("No Number\n");
}
return 0;
}
