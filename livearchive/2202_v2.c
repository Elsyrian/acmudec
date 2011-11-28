/******************************************************************
 * 2022 - Vito's Family
 * http://livearchive.onlinejudge.org/external/22/2202.html
 *
 * Author(Grupo):
 *   Luis Jury 			   <zeui16@gmail.com>
 *   Javier Gonzalez Nova  <javigonzalez@udec.cl>
 *   
 * Description:
 *	 
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int casos;
  int i;
  int j;
  int k;
  int suma_menor;
  int suma_parcial = 0;
  int calleG;
  int fam;
  int calles[500];
 
  scanf("%i",&casos);
  
  for(i = 0; i < casos; i++){
    scanf("%i", &fam);
   
    for(j = 0; j < fam; j++){
      
      scanf("%i", &calles[j]);

    }

 


   for(j = 0; j < fam; j++){
     calleG = calles[j];
     suma_parcial = 0;
     for( k = 0; k < fam; k++)
       {
	 suma_parcial += abs( calleG - calles[k] );
       }
     
     if(j == 0)
       suma_menor = suma_parcial;
     else
       {
	 if( suma_menor > suma_parcial )
	   suma_menor = suma_parcial;
	   
       }
       
     

    }
   printf("%i\n", suma_menor);

  }
  return 0;
}