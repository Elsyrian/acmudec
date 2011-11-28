/******************************************************************
 * 2362 - Financial Management
 * http://livearchive.onlinejudge.org/external/23/2362.html
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
int main(void){
float j=0,k=0,y=0;
for(k=0;k<12;k++){
	scanf("%f",&j);
y=y+j;

}
printf("$%.2f\n",y/12);
return 0;
}
