/*
4843 - Sales
http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=2844

Classification: String Processing

Author:
       Ricardo Vásquez <ricardovasquez@udec.cl>
       
Description:
            El jefe de una empresa resive todos los dias un informe con las ventas del día, y él va comparando estos resultados
            con el de los días anteriores, y cada día, va guardando en una lista la cantidad de días anteriores que tuvieron una menor
            venta que el día actual. El objetivo del programa es, dada una lista con los resultados de las ventas, determinar la suma
            de todos los elementos de la lista elaborada por el jefe.
*/

#include <stdio.h>

int main(){
    
    int arr[1010];
    int i,j;
    int n;
    int casos;
    int total;
    
    scanf("%d",&casos);
    
    while(casos){
                 
       scanf("%d",&n);
       
       
       total=0;
       
       scanf("%d",&arr[0]);
       for(i=1;i<n;i++){
          scanf("%d",&arr[i]);
          for(j=0;j<i;j++){
       
             if(arr[i]>=arr[j])total++;
             
          }
       }
       printf("%d\n",total);
    
       casos--;
    }
    
    return 0;
}
