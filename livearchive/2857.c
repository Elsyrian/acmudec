/*
2857 - Keep on Truckin'
http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=858

Classification: Ad hoc (?)

Author: Ricardo Vásquez <ricardovasquez@udec.cl>

Description: Dos personas van en un camion de noche y saben que hay 3 pasos inferiores hasta llegar a su destino.
             El objetivo es, conociendo las alturas maximas permitidas por los pasos, determinar si habra un accidente o no.
             En el caso de que se produzca un accidente, hay que decir la altura maxima que superó el camión.
*/

#include <stdio.h>

int main(){
    
    int a,b,c;
    
    scanf("%d %d %d",&a,&b,&c);
    
    if(a<=168)printf("CRASH %d\n",a);
    else if(b<=168)printf("CRASH %d\n",b);
    else if(c<=168)printf("CRASH %d\n",c);
    else printf("NO CRASH\n");
    
    return 0;
}
