/**************************************************************************************************************************
 * 3389 - Quick Change
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=207&page=show_problem&problem=1390
 *
 * Authors:
 *   Cathy Espinoza <nikkita126@gmail.com>
 *   Javier Rodríguez
 *   Ricardo Vásquez
 *
 * Description:
 *   Dado un valor correspondiente al vuelto asociado a una compra, se pide determinar la
 * cantidad de monedas de 25, 10, 5 y 1 centavo que completan el valor del vuelto, de modo
 * que el total de monedas entregado sea el menor posible.
 *
 *                                                      -- Cathy Espinoza
 */

#include <stdio.h>

int main(){
  
  int k,veces;
  int numero;
  int q,d,n;
  
  scanf("%d",&veces);
  
  for(k=1;k<=veces;k++){
    scanf("%d",&numero);
    
    
    q=numero/25;
    numero-=(q*25);
    d=numero/10;
    numero-=(d*10);
    n=numero/5;
    numero-=(n*5);
    
    printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",k,q,d,n,numero);
  }
  return 0;
}
