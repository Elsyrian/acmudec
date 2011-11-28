/*
3847 - The Seven Percent Solution
http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=1848

Classification: String Processing

Author:
       Ricardo Vásquez <ricardovasquez@udec.cl>

Description:
            Dentro de los identificadores de recursos existen caracteres que están reservados, el objetivo de este problema es, dada
            una tabla con caracteres reservados y su codificacion porcentual, reemplazar estos caracteres dentro de un string por
            su código equivalente.
*/

#include <stdio.h>
#include <string.h>

int main(){
    
    char frase[85];
    int i,j,l;
    
    while(1){
       scanf(" %[^\n]",frase);
       if(frase[0]=='#')break;
       
       l=strlen(frase);
       
       for(i=0;i<l;i++){
          if(frase[i]==' ')printf("%%20");
          else if(frase[i]=='!')printf("%%21");
          else if(frase[i]=='$')printf("%%24");
          else if(frase[i]=='%')printf("%%25");
          else if(frase[i]=='(')printf("%%28");
          else if(frase[i]==')')printf("%%29");
          else if(frase[i]=='*')printf("%%2a");
          else printf("%c",frase[i]);
       }
       printf("\n");
    }
    
    return 0;
}
