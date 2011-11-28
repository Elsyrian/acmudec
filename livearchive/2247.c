/*************************************************************************************************************************
 * 2247 - Prime Digital Roots
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=207&page=show_problem&problem=248
 *
 * Classification: Prime numbers
 *
 * Authors:
 *   Cathy Espinoza <nikkita126@gmail.com>
 *
 * Description:
 *   Se pide encontrar, de ser posible, la raiz prima digital de un número, que corresponde 
 * al primer valor primo que se obtiene al ir sumando los dígitos que lo componen.
 *   Problema típico de números primos.
 *                                                      -- Cathy Espinoza
 */


#include <stdio.h>
#include <string.h>
#define MAX 999999

int primos[MAX];

void criba(){
  
  int i, h;
  
  primos[0] = 0;
  primos[1] = 0;
  for(i=2;i<=MAX;i++) primos[i]=1;
  
  for(i=2;i*i<=MAX;i++) {
    if(primos[i]) {
      for(h=2;i*h<=MAX;h++)
	primos[i*h]=0;
    }
  }
}

int sumaDigitos(int num){
  
  int i,s;
  s=0;
  
  for(i=0;num;i++){
    s=s+(num%10);
    num=num/10;
  }
  return s;
  
}

int primeDigitalRoot(int n){
  
  int p,s;
  if(primos[n]==1) p=n;
  
  else {
    if(n<10) p=0;
    
    else{
      s=sumaDigitos(n); 
      p=primeDigitalRoot(s);
    }  
  }
  return p;
  
}

int main () {
  
  int num,root;
  criba(num);
  
  while(1){
    
    scanf("%d", &num);
    
    if(!num) break;
    
    root=primeDigitalRoot(num);
    
    if(num>0 && num<10)
      printf("      ");
    else if(num>=10 && num<100)
      printf("     ");
    else if(num>=100 && num<1000)
      printf("    ");
    else if(num>=1000 && num<10000)
      printf("   ");
    else if(num>=10000 && num<100000)
      printf("  ");
    else if(num>=100000 && num<1000000)
      printf(" ");
    
    printf("%d",num);
    
    if(!root)
      printf("    none\n");
    else if(root>0 && root<10)
      printf("       %d\n",root);
    else if(root>=10 && root<100)
      printf("      %d\n",root);
    else if(root>=100 && root<1000)
      printf("     %d\n",root);
    else if(root>=1000 && root<10000)
      printf("    %d\n",root);
    else if(root>=10000 && root<100000)
      printf("   %d\n",root);
    else if(root>=100000 && root<1000000)
      printf("  %d\n",root);
	
  }

  return 0;   
}
