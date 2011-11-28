 /*************************************************************************************************************************
 * 3045 - Gold Coins
 * http://livearchive.onlinejudge.org/external/25/2515.html
 *
 * Author(Grupo):
 *   Gabriela Lartiga   <gabyganihonjindayo@gmail.com>
 *   Jose Troncoso  <jostroncoso@udec.cl>
 *   Mathias Ercoreca <darksefirothh@gmail.com>
 *
 * Description:
 *   Un rey le paga a su caballero en monedas de oro siguiente un patron determinado, el primer dia recibe una moneda
 *   el segundo y tercero dos monedas, el tercer, cuarto y quinto dia 3 monedas y asi sucesivamente.
 *   Nos piden que calculemos cuando dinero ha recibido el caballero luego de ciertos dias.
 */

#include <stdio.h>
int main (void){
while(1){
    int days,i,k,coin,temp,h,var,p;
    scanf("%i",&days);
    k=1;
    coin=0;
    temp=0;
    var=0;
    h=0;
    p=1;
    if (days==0){
        return 0;
    }

   for(i=1;temp<=days;i++){
   temp=temp+i;
   }
   if(temp == days){
   while(h<i){
   for(k=0;k!=h;k++){
   coin=coin+h;
   }
   h++;
   }
   }
   else{
   var=temp-days;
   while(h<i-1){
   for(k=0;k!=h;k++){
   coin=coin+h;
   }
   h++;
   }
   }
   while(p<i-var){
   coin=coin+h;
   p++;
   }

   printf("%i %i\n",days,coin);
   }
    return 0;
}
