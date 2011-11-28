/*
3758 - Walk Like an Egyptian
http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=1759

Classification: Ad hoc (?)

Author:
       Ricardo Vásquez <ricardovasquez@udec.cl>

Description:
            En el antiguo Egipto, los niños jugaban a poner piedras dentro de una "malla" de una forma bastante particular, 
        comenzaban colocando una piedra en la esquina inferior izquierda, luego iban colocando piedras de manera ordenada en todas
        las celdas que la rodeaban en sentido antihorario, luego hacian lo mismo pero en sentido horario, y en cada celda colocaban
        una piedra mas que en la anterior. El objetivo del programa es determinar cual sera la cantidad de piedras que hay en la 
        esquina superior derecha al conocer el ancho de la matriz (matriz cuadrada).
*/

#include <stdio.h>

int main(){
    
    int n;
    
    while(1){
             
       scanf("%d",&n);
       if(n==0)break;
       
       printf("%d => %d\n",n,(n*n)-(n-1));
    }
    return 0;
}
