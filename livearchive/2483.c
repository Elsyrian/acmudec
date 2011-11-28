#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void){
 char cost[] = "COST";
 int num, num2;
  char inputC[4];
  int a,b, c;
  int w = 1;
  int cuenta[2] = {0,0};
  int cont = 1;
  int last = 0;
  char end[] = "#";
  int precio = 0;
  int set = 1;
  int pos = 1;

  while( 1 )
    {
      scanf("%s", inputC);
      if( strcmp(inputC, cost) == 0 )
	{  
	  printf("Set %i\n", set);
	  set++;
	  scanf("%i %i", &a, &b);
	}
      else if( strcmp(inputC, end) == 0 )
	  break;
      else
	{
	  
	  num = atoi(inputC);
	  num2 = num;
	  pos = 0;
	  
	  if (num >= 1<<16) { num >>= 16; pos += 16; }
	  if (num >= 1<< 8) { num >>=  8; pos +=  8; }
	  if (num >= 1<< 4) { num >>=  4; pos +=  4; }
	  if (num >= 1<< 2) { num >>=  2; pos +=  2; }
	  if (num >= 1<< 1) {           pos +=  1; }


	  for( w = 0; w < (pos+1); w++)
	    {
	      if((~(~0<<1) & num2>>w) == 1)
		{
		  cuenta[1]++;
		  last = w;
		}     
	    } 
	  
	  cuenta[0] = (last+1)-cuenta[1];
	  precio = cuenta[0]*a + cuenta[1]*b;
	  
	  printf("%i\n", precio);
	  cuenta[0] = 0;
	  cuenta[1] = 0;
	} 
    }  
  return 0;
}

 
