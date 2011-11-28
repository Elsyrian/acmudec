#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define isNumber(p) isdigit( p [0] )

char unidad[9][6]={"I","II","III","IV","V","VI","VII","VIII","IX"};
char decena[9][6]={"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
char centena[9][6]={"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
char mil[3][6]={"M","MM","MMM"};
void a_romano(int n);
void a_arabico(char *);
int main(){
   char input[1024];
   char help[1024];
   sprintf(input,"a");
   while(1){
     sprintf(help,"%s",input);
     scanf("%s",input);
     if(strcmp(input,help)==0)
           return 0;
     if(isNumber(input)){
          a_romano(atoi(input));
     }else{
        a_arabico(input);
     }
   } 
}

void a_romano(int n){
   int miles=0,centenas=0,decenas=0,unidades=0;
      miles=n/1000;
   centenas=(n%1000)/100;
    decenas=(n%100)/10;
   unidades=(n%10)/1;
   if(miles>0)
     printf("%s",mil[miles-1]);
   if(centenas>0)
     printf("%s",centena[centenas-1]);
   if(decenas>0)
     printf("%s",decena[decenas-1]);
   if(unidades>0)
     printf("%s",unidad[unidades-1]);
  

   printf("\n");

}
void a_arabico(char *input){
   int resultado=0;
   int n = strlen(input);
   int i;
   char valor='.';
   for(i=0;i<n;i++){
      if(input[i]=='M'){
         if(valor=='C')
          resultado = resultado + 800;
        else
          resultado = resultado+1000; 
        valor='M';
      }else if(input[i]=='C'){
        if(valor=='X')
          resultado = resultado+80;
        else
         resultado = resultado+100; 
        valor='C';
      }else if(input[i]=='D'){
        if(valor=='C')
          resultado = resultado +300;
        else
         resultado = resultado + 500;
        valor='D';
      }else if(input[i]=='X'){
         if(valor=='I')
           resultado = resultado + 8;
         else
           resultado = resultado + 10;
         valor='X';
      }else if(input[i]=='L'){
         if(valor == 'X')
           resultado = resultado +30;
         else
          resultado = resultado + 50;
         valor='L';
      }else if(input[i]=='I'){
         resultado = resultado + 1;
         valor='I';
      }else if(input[i]=='V'){
         if(valor=='I')
            resultado = resultado + 3; 
         else
         resultado = resultado + 5;
         valor='V';
      }
      
   }
   
   

   printf("%i\n",resultado);

}


