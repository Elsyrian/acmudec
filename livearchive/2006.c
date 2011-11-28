/*************************************************************************************************************************
 * 2006 - Most Wanted Word
 * http://livearchive.onlinejudge.org/external/20/2006.html
 *
 * Classification: String Processing
 *
 * Author:
 *   Javier Gonzalez Nova  <javigonzalez@udec.cl>
 *   
 * Description:
 *   Nos piden encontrar, en un texto, la palabra que mas se repite. Tenemos que indiciar que palabra es y cuantas veces se repite.
 */

#include <stdio.h>
#include <string.h>

char palabras[20000][200];
char palabraActual[200];
char frecuencia[20000];
char line[20000];
int end;
int i,j,k;
int igualdad;
int palabrasDif;
int inword;
int hayAlmenosUna;
int mayorParcial;
int primerOrden;

int main(void){

  hayAlmenosUna = 0;
  inword = 0;
  palabrasDif = 0;
  igualdad = 0;
  end = 0;
  for(i = 0; i < 200; i++){
    frecuencia[i] = 0;
  }

  while(!end){
    fgets(line, 2000, stdin);

    k = 0;
    for(i = 0; line[i] != '\0'; i++){
      if(line[i] >= 65 && line[i] <= 90)
	line[i] += 32;

      if(line[i] >= 97 && line[i] <= 122){
	palabraActual[k] = line[i];
	inword = 1;
	k++;
	hayAlmenosUna = 1;
      }else{
	if(inword)
	{
	  palabraActual[k] = '\0';
	  igualdad = 0;
	  for(k = 0; k < palabrasDif; k++){
	    if(strcmp(palabraActual, palabras[k]) == 0){
	      igualdad = 1;
	      frecuencia[k]++;
	      primerOrden = 1;
	      for(j = 0; j < palabrasDif; j++){
		if(strcmp(palabras[k], palabras[j]) != 0){
		  if(frecuencia[k] <= frecuencia[j]){
		    primerOrden = 0;
		  }
		}
	      }
	      if(primerOrden){
		mayorParcial = k;
	      }
	    }
	  }
	  if(!igualdad){
	    strcpy(palabras[palabrasDif], palabraActual);
	    palabrasDif++;
	  }
	  k = 0;
	  inword = 0;
	}
      }
    }
    
    if(line[0] == '#'){
      if(hayAlmenosUna){
	printf("%4i %s\n", frecuencia[mayorParcial]+1, palabras[mayorParcial]);
      }else{
	end = 1;
      }

      for(i = 0; i < palabrasDif; i++){
	frecuencia[i] = 0;
      }
      palabrasDif = 0;
      hayAlmenosUna = 0;
    }
  }
  
  return 0;
}

