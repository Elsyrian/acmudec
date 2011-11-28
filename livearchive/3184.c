/**************************************************************************************************************************
 * 3184 - I can't read it!
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=189&page=show_problem&problem=1185
 *
 * Author:
 *   Cathy Espinoza <nikkita126@gmail.com>
 *
 * Description:
 *   Problema sencillo. Se pide leer varios bloques de líneas e imprimir, en cada línea,
 * las palabras en orden invertido, respetando la posición de los espacios y de los saltos
 * de línea.
 *
 *                                                      -- Cathy Espinoza
 */

#include <stdio.h>
#include <string.h>

int main () {
  
  int casos,i,j,p,f;
  char linea[1001];
  char c;
  
  while(1){
    
    scanf("%d",&casos);
    getchar();
    
    if(!casos) break;
    
    p=0;
    f=0;
    i=casos;
    
    while(i){
      
      c=getchar();
      if(c==' '){
	if(p!=f){
	  for(j=f-1;j>=p;j--)
	    printf("%c",linea[j]);
	  p=f+1;
	  f=f+1;
	}
	printf(" ");
      }
      else if(c>='a' && c<='z'){
	linea[f]=c;
	f=f+1;
      }
      else if(c=='\n'){
	for(j=f-1;j>=p;j--)
	  printf("%c",linea[j]);
	printf("\n");
	i=i-1;
	p=0;
	f=0;
      }
    }
  }
  
  return 0;
}
