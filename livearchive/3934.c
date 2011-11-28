/*************************************************************************************************************************
 * 3934 - He is Offside!
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=1935
 *
 * Classification: 
 *
 * Author:
 *   Luis Jury  <zeui16@gmail.com>
 *
 * Description:
 *  El problema simula un partido en las cuales te dan las distancias de los jugadores al arco defensivo, en base 
 * a esto, uno debe calcular si hay algun jugador (ofensivo) offside, el problema es muy simple, ya que solo
 * hay que verificar las distancias ( eso si el codigo esta horrible )
 */


#include <stdio.h>


int main()
{
  int A, D;
  int B[11], C[11];
  int nearA,nearD,snearD, nearDindex;
  int nearDCount;
  int i, flag;

  while( scanf("%i %i \n", &A, &D) &&  A != 0 && D != 0 ) 
    {
      flag = 0;
      for( i=0; i<A; i++)
	scanf("%i", &B[i]);

      for( i=0; i<D; i++)
	scanf("%i", &C[i]);

      nearA = B[0];

      /*se busca el atacante mas cercano*/
      for(i = 1; i<A;i++)
	{
	  if( B[i] < nearA)
	    nearA = B[i];

	    
	}

      nearD = C[0];
      nearDindex = 0;
      nearDCount = 1;
      /*se busca el defensa mas cercano*/
      
      for(i = 1; i<D;i++)
	{
	  
	  if( C[i] < nearD)
	    {
	      nearDindex = i;
	      nearD = C[i];
	      nearDCount = 1;
	    }
	  else if( C[i] == nearD )
	    {
	      
	      nearDCount++;
	    }
	  
	}
      /*se busca el segundo defensa mas cercano*/
      if(nearDCount >= 2)
	snearD = nearD;
      else
	{
	  if( nearDindex != 0)
	    {
	      snearD = C[0];   
	      i = 1;
	    }
	  else
	    {
	      snearD = C[1];
	      i = 0;
	      flag = 1;
	    }
	  for(     ; i<D;i++)
	    {
	      if( C[i] < snearD && i != nearDindex)
		snearD = C[i];
	      if( flag == 1)
		{
		  i++;
		  flag = 0;
		}
	    }
	}
    
      // condiciones de NO offside
      if( (nearA == snearD) || (nearA >= nearD && nearDCount >= 2) ||  nearA > snearD )
	printf("N\n");
      else
	printf("Y\n");

    }

}
