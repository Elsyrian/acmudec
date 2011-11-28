/**************************************************************************************************************************
 * 2389 - Palindrom Numbers
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=207&page=show_problem&problem=390
 *
 * Author:
 *   Cathy Espinoza <nikkita126@gmail.com>
 *
 * Description:
 *   Este problema trata el ya conocido tópico de los números palíndromos, pero con una dificultad
 * extra pues se pide verificar si determinado número es palíndromo en todas las bases entre 2 y 16.
 *
 *                                                      -- Cathy Espinoza
 */

#include <stdio.h>
#include <string.h>

char conv[500];

void itoaInv(int num, int base){
  
  int i;
  
  switch(base){
    
  case 2 ... 10:
    for(i=0;num;i++){
      conv[i]=(num%base) + '0';
      num=num/base;
    }
    conv[i]='\0';
    break;
    
  case 11 ... 16:
    for(i=0;num;i++){
      conv[i]=(num%base) + '0';
      if (conv[i]>'9')
	conv[i]=conv[i] + 'A' - '9' - 1;
      num=num/base;
    }
    conv[i]='\0';
    break;
    
  default:
    break;
  }
}

int palindromo (char num[]){
  
  int largo = strlen(num);
  int j;
  for(j=0;j<(largo/2);j++){
    if(num[j]!=num[largo-1-j]) return 0;
  }
  
  return 1;
}

int main() {
  
  int num,i,c,flag;
  int bases[16];
  
  while(1){
    c=0;
    flag=0;
    
    scanf("%d",&num);
    
    if(!num) break;
    
    for(i=2;i<17;i++){
      itoaInv(num,i);
      if(palindromo(conv)){
	flag=1;
	bases[c]=i;
	c=c+1;
      }
    }
    
    if(flag){
      printf("Number %d is palindrom in basis", num);
      for(i=0;i<c;i++) printf(" %d",bases[i]);
      printf("\n");
    }
    
    else printf("Number %d is not palindrom\n",num);
  }
  return 0;
}
