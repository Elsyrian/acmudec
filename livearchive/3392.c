/*
3392 - Triangular Sums
http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=262&page=show_problem&problem=1393

Classification:
               
Author:
       Ricardo Vásquez <ricardovasquez@udec.cl>

Description:
            Primero se indica que los numeros triangulares tienen la forma T(n)=1+2+...+n, y el programa es básicamente implementar
            una función que calcule el valor de una función W(n)=k*T[k+1], k=1,2,...,n

*/

#include <stdio.h>

int T[305];

int func(int numero){
    
    int suma=0,i;
    
    for(i=1;i<=numero;i++){
       suma+=(i*T[i+1]);
    }
    
    return suma;
}    

int main(){
    
    int veces,numero;;
    int i,j,k;
    
    T[0]=0;
    for(i=1;i<305;i++)T[i]=T[i-1]+i;
    
    scanf("%d",&veces);
    
    for(k=1;k<=veces;k++){
    
       scanf("%d",&numero);
       
       printf("%d %d %d\n",k,numero,func(numero));
    
    }
    return 0;
}
    
    
