/******************************************************************
 * 2052 - Number Steps
 * http://livearchive.onlinejudge.org/external/20/2052.html
 *
 * Author(Grupo):
 *   Luis Jury 			   <zeui16@gmail.com>
 *   Javier Gonzalez Nova  <javigonzalez@udec.cl>
 *   
 * Description:
 *	 
 */


#include <stdio.h>

int main(void){
  int n; /*Numero input*/
  int i, j; /*Contador*/
  int x, y;
  int suma;

  x = y = 0;
  suma = 0;

  scanf("%i", &n);
  for(j = 0; j < n; j++){
    scanf("%i %i", &x, &y);

    if(y == x){
      for(i = 0; i < y; i++){
	if(i%2 != 0){
	  suma += 3;
	}else{
	  suma += 1;
	}
      }
      printf("%i\n", suma);
    }else if(y == (x-2)){
      suma = 2;
      for(i = 0; i < y; i++){
	if(i%2 != 0){
	  suma += 3;
	}else{
	  suma += 1;
	}
      }
      printf("%i\n", suma); 
    }else{
      printf("No Number\n");
    }
  
  suma = 0;
  }

  return 0;
}