/******************************************************************
 * 2362 - Financial Management
 * http://livearchive.onlinejudge.org/external/23/2362.html
 *
 * Author(Grupo):
 *   Luis Jury 			   <zeui16@gmail.com>
 *   Javier Gonzalez Nova  <javigonzalez@udec.cl>
 *   
 * Description:
 *	 
 */

#include <stdio.h>

int main(void)
{
  float mensualidad;
  float total;
  int meses;
  float numFinal;
  float decimal;
  
  numFinal = 0;
  mensualidad = 0;
  total = 0;
  meses = 0;
  decimal = 0;

  while(meses < 12)
  {
    scanf("%f", &mensualidad);
    total += mensualidad;
    meses++;
  }
  numFinal = total/12;

  printf("$%.2f\n", numFinal);
  
  return 0;
}