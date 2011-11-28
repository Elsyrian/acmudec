/*************************************************************************************************************************
 * 4814 - Jollo
 * 
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=2815
 *
 * Classification: 
 *
 * Author:
 *   Luis Jury <zeui16@gmail.com>
 *
 * Description:
 *
 *  Jollo es un juego de cartas, donde a cada jugador se le entregan 3 cartas y se desea saber, luego de entregar 3 cartas al primer
 * jugador y 2 al segundo, cual carta se le debe entregar al segundo jugador para que sea imposible que el pierda *
 * 
 */

#include <stdio.h>


int main() {
  int A,B,C,X,Y;
  int i, j;
  int m;
  int temp;
  int ps[3];
  int ord[3];
  int index;
  int min;
  int max;
  int index2;
  int need_card;

  while( scanf("%i %i %i %i %i", &A,&B,&C,&X,&Y))
    {
      need_card = 0;
      if( A == B && B == C && C == X && X == Y && A == 0)
	break;

      ps[0] = A;
      ps[1] = B;
      ps[2] = C;
      temp = A;
      
      for(j = 0; j<3; j++)
	{
	  for(i = 0; i <3; i++)
	    if( ps[i] != -1)
	      temp = ps[i];
	  for(i = 0; i < 3; i++){
	    if( ps[i] < temp && ps[i] != -1 )
	      temp = ps[i];
	  }
	  ord[j] = temp;
	  for(i = 0; i < 3; i++){
	    if( ps[i] == temp)
	      ps[i] = -1;
	  }
	  
	}
      if( Y > X)
	{
	  min = X;
	  max = Y;
	}
      else
	{
	  min = Y;
	  max = X;
	}
      
     
      index = -1;
      for(i = 0; i <3; i++)
	{
	  if(ord[i] > min)
	    {
	      index = i;
	      break;
	    }
	}
      if(index == -1)
	{
	  need_card = 1;
	}
       
      if(need_card == 0)
	{
	  ord[index] = -1;
	  
	  for(i = 0; i <3; i++)
	    {
	      if(ord[i] > max )
		{
		  need_card = -1;
		}
	      
	    }
      
	  if( need_card != -1)
	    {
	      temp = 0;
		for( i = 0; i < 3; i++)
		  {
		    
		    if( ord[i] > temp)
		      {
		
		      temp = ord[i];
		      }
		  }
	      need_card = temp+1;
	    }
	  
	}

      while( A == need_card || B == need_card || C == need_card || X == need_card || Y == need_card )
	need_card++;

      if( need_card > 52)
	need_card = -1;

      printf("%i\n", need_card);

	
	
	

	}
  
  
  
  
  return 0;
}
