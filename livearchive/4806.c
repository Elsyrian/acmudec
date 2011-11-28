/*************************************************************************************************************************
 * 4806 - Bingo!
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=2807
 *
 * Classification: 
 *
 * Author:
 *   Luis Jury <zeui16@gmail.com>
 *
 * Description:
 *    En este problema, hablan de un nuevo Bingo, en el cual se juega de la siguiente forma.
 * Se saca la primera bola, se devuelve y se saca una segunda y el numero anunciado sera la diferencia absoluta entre los dos
 * anteriores, antes de comenzar el juego un conjunto de bolas son removidas (al menos dos deben quedar ).
 * La idea es ver si aun es posible que salgan todos los numeros (entre 0 y N) 
 *
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{

  int n,b;
  int left[90];
  int i, j;
  int pos[90];
  int k;
  int temp;
  int sol;
  while(scanf("%i %i", &n, &b) && n != 0 && b != 0 )
    {
      k = 0;
      
      for(i = 0; i < b; i++)
	scanf("%i", &left[i]); 

      for(i = 0; i < 90; i++)
	pos[i] = -1;

      for(i = 0; i < b; i++){
	for( j = 0; j < b; j++){
	  
	    temp = abs(left[i]-left[j]);
	    pos[temp] = temp;
	  
	}
        
      }

      for(i = 0; i < n; i++)
	{
	  if( pos[i] == -1 )
	    {
	      sol = -1;
	      break;
	    }
	  else
	    sol = 1;
	  
	}
    
      if( sol == 1 )
	printf("Y\n");
      else
	printf("N\n");
      
    }
  
  
  return 0;
}
