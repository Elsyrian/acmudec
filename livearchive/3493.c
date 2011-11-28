/******************
*   3493 - 01000001
*   http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=1494
*   un problema sencillo de sumar dos numeros binarios. decidi realizarlo 
*   sin usar alguna conversion sino las reglas basicas de suma binaria
*               -- Jose Troncoso
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(void){
  int i,j,n,k,l,m,co;
  char a[90],b[90],c[90];
  scanf("%d",&i);
  for(j=0;j<i;j++){
    scanf("%s %s",a,b);
    n=strlen(a);
    k=strlen(b);
    l=abs(k-n)+1;
    if(n>k){
      for(m=0;m<l;m++)
	c[m]='0';
      for(m=0;m<k;m++)
	c[m+l]=b[m];
      strcpy(b,c);
      for(m=1;m<n;m++)
	c[m+1]=a[m];
      strcpy(a,c);
      for(m = n-1; m >= 0;m--)
	if(a[m]=='1' && b[m]=='1' && co!= 1){
	  c[m]=0;
	  co=1;                           
	}	    
    }
  }
  return 0;
}
