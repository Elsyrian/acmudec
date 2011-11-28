/****************************************************************************************************
 * 2007 - Tag Checker
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=207&page=show_problem&problem=8
 *
 * Author:
 *   Cathy Espinoza <nikkita126@gmail.com>
 *
 * Description:
 *   El problema pide revisar un párrafo con etiquetas, estilo HTML, verificando si éstas están
 * apropiadamente cerradas y corrigiendo en el caso en que los tags de cierre se encuentren mal
 * anidados, o que falte o sobre una etiqueta de cierre.
 *   Basta con implementar una pila con las etiquetas de apertura e irlas sacando una a una, según
 * corresponda, para determinar si el párrafo está bien etiquetado o no.
 *
 *                                                      -- Cathy Espinoza
 */

#include <stdio.h>
#include <string.h>
#define MAX 100000

int main () {
  
  char parrafo[MAX];
  int i,tags,largo,fallo;
  char etiquetas[MAX];
  
  while (1){
    
    tags=0;
    fallo=0;
    scanf("%[^#]", parrafo);
    getchar();
    largo=strlen(parrafo);
    if(largo==0 || (largo==1 && parrafo[0]=='\n')) break;
    
    etiquetas[0]='#';
    
    for(i=0; i<largo; i++){
      
      if(parrafo[i]=='<') {
        if(parrafo[i+2]=='>' && parrafo[i+1]>64 && parrafo[i+1]<91) {
          tags=tags+1;
          etiquetas[tags]=parrafo[i+1];
        }
        else if (parrafo[i+1]=='/' && parrafo[i+2]>64 && parrafo[i+2]<91 && parrafo[i+3]=='>'){
          if((parrafo[i+2]!=etiquetas[tags]) && etiquetas[tags]!='#'){
            printf("Expected </%c> found </%c>\n", etiquetas[tags],parrafo[i+2]);
            fallo=1;
            break;
          }
          else if (etiquetas[tags]=='#') {
            printf("Expected # found </%c>\n",parrafo[i+2]);
            fallo=1;
            break;
          }
          else {
            if(tags) tags=tags-1;
	  }
	}
      }
    }
    
    if(etiquetas[tags]!='#' && !fallo) {
      printf("Expected </%c> found #\n", etiquetas[tags]);
      fallo=1;
    }
    
    if(!fallo) printf("Correctly tagged paragraph\n");
  }
  
  return 0;
}
