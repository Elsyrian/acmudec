/******************************************************************
 * 2617 - Noise Effect
 * http://livearchive.onlinejudge.org/external/26/2617.html
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
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_ROWS 400

double myRound(double r,int n_digit)
{
  int n=pow(10,n_digit);
  r=((float)((int)(r*n+0.5)))/n;
  return(r);
}

int main(void){
  int standard[MAX_ROWS][MAX_ROWS];
  int matrizOriginal[MAX_ROWS][MAX_ROWS];
  int matrizRotada[MAX_ROWS][MAX_ROWS];
  int i,j,k,l;
  int temp;
  int intento;
  float confiabilidad;
  int n;
  int finish;
  int row, col;
  int posiciones[8];

  for(i = 0; i < 8; i++){
    posiciones[i] = 0;
  }
  row = col = 0;
  finish = FALSE;
  n = 0;
  confiabilidad = 0;
  intento = 0;
  temp = 0;
  i = j = k = l = 0;
  
  while(!finish){
    scanf("%i", &n);
    if(n == 0) 
      finish = TRUE;
    else{
      for(i = 0; i < n; i++){
	for(j = 0; j < n; j++){
	  scanf("%i", &standard[i][j]);
	}
      }

      for(i = 0; i < n; i++){
	for(j = 0; j < n; j++){
	  scanf("%i", &matrizOriginal[i][j]);
	}
      }
      
      while(intento <= 7){
	/*Comparando pixel a pixel para ver si la imagen cuadra.*/
	for(i = 0; i < n; i++){
	  for(j = 0; j < n; j++){
	    if(abs(standard[i][j] - matrizOriginal[i][j]) <= 100){
	      posiciones[intento]++;
	    }
	  }
	}

	if(intento == 3){
	  /*Vertical*/
	  j = n-1;
	  for(l = 0; l < j; l++){    
	    for(i = 0; i < n; i++){
	      temp = matrizOriginal[l][i];
	      matrizOriginal[l][i] = matrizOriginal[j][i];
	      matrizOriginal[j][i] = temp;
	    }
	    j--;
	  }
	  intento++;
	}else{
	  /*Gira la matriz en 90º en sentido horario*/
	  for(row = 0; row < n; row++){
	    for(col = 0; col < n; col++){
	      matrizRotada[row][col] = matrizOriginal[n-col-1][row];
	    }
	  }
	  
	  /*La matriz original ahora sera la rotada*/
	  for(row = 0; row < n; row++){
	    for(col = 0; col < n; col++){
	      matrizOriginal[row][col] = matrizRotada[row][col];
	    }
	  }
	  intento++;
	}
      }

      confiabilidad = 0;
      for(i = 0; i < 8; i++){
	if(confiabilidad < posiciones[i])
	  confiabilidad = posiciones[i];
      }

      printf("%.2f\n", (float)myRound((confiabilidad*100)/(n*n),2));
      intento = 0;

      for(i = 0; i < 8; i++){
	posiciones[i] = 0;
      }
    }
  }
  
  return 0;
}
