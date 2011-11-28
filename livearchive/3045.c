/*************************************************************************************************************************
 * 3045 - Gold Coins
 * http://livearchive.onlinejudge.org/external/25/2515.html
 *
 * Author(Grupo):
 *   Javier Gonzalez Nova    <javigonzalez@udec.cl>
 *   Luis Jury               <zeui16@gmail.com>           
 *   
 * Description:
 *   Un rey le paga a su caballero en monedas de oro siguiente un patron determinado, el primer dia recibe una moneda
 *   el segundo y tercero dos monedas, el tercer, cuarto y quinto dia 3 monedas y asi sucesivamente.
 *   Nos piden que calculemos cuando dinero ha recibido el caballero luego de ciertos dias.
 */

#include <stdio.h>

int main()
{
  int i;
  int d;
  int diaActual;
  int diasTotales;
  int monedas;

  monedas = 0;
  diasTotales = 1;
  diaActual = 0;

  while( scanf("%d", &d) && d != 0 )
    {
      
      while(diaActual != d){
      for( i = 0; i < diasTotales; i++ )
	{
	  monedas += diasTotales;
	  diaActual++;
	  if(diaActual == d)
	    break;
	}
      diasTotales++;
      }

      printf("%d %d\n", d, monedas);
      monedas = 0;
      diasTotales = 1;
      diaActual = 0;
    }


  

  return 0;
}

