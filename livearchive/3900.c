/*********************************************************
* 3900 - Molar Mass
* http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=22&page=show_problem&problem=1901
*
*
* Problema donde debias calcular la masa molar de un compuesto quimico.
* La dificultad radicaba en que debias encontrar el cambio entre los numeros
* y las palabras, es decir C22H100O3, solo usaba 4 elementos quimicos, "C","H","O","N"
* y tenias que calcular la suma de la masa molar de la molecula.
*
*
*                                      -- Mathias Ercoreca
*
*/
#include <stdio.h>
#include <string.h>
int main(){
    int number,i,x,b,z,j,w,s;
    float sum;
    char A[80],B[80];
    scanf("%i",&number);
    z=0;
    while(z<number){
    sum=0;
    j=1;
    i=0;
    scanf("%s",&A);
    b=strlen(A);
    while(i<b){
       if(A[i+1]=='1' || A[i+1]=='2' || A[i+1]=='3' || A[i+1]=='4' || A[i+1]=='5' || A[i+1]=='6' || A[i+1]=='7' || A[i+1]=='8' || A[i+1]=='9'){
            while(A[i+j]=='1' || A[i+j]=='2' || A[i+j]=='3' || A[i+j]=='4' || A[i+j]=='5' || A[i+j]=='6' || A[i+j]=='7' || A[i+j]=='8' || A[i+j]=='9' || A[i+j]=='0'){
                B[j-1]=A[i+j];
                j++;
            }
            x=atoi(B);
            if(A[i]=='C'){
                sum=sum+x*12.01;
            }
            if(A[i]=='H'){
                sum=sum+x*1.008;
            }
            if(A[i]=='O'){
                sum=sum+x*16;
            }
            if(A[i]=='N'){
                sum=sum+x*14.01;
            }
            i=i+j;
            j=1;
            for(s=0;s<80;s++){
            B[s]='\0';
            }
        }
        else{
            if(A[i]=='C'){
                sum=sum+12.01;
            }
            if(A[i]=='H'){
                sum=sum+1.008;
            }
            if(A[i]=='O'){
                sum=sum+16;
            }
            if(A[i]=='N'){
                sum=sum+14.01;
            }
            i++;
        }
    }
    printf("%.3f\n",sum);
    z++;
    }
    return 0;
}
