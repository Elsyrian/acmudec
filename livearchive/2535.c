/*
2535 - Magnificent Meatballs
http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=536

Classification: String Processing

Author: 
   Ricardo Vásquez <ricardovasquez@udec.cl>

Description:
   El problema trata sobre una pareja de meseros que les gusta servir albondigas de una manera muy particular. Comenzando a servir
  desde posiciones una al lado de otra, la mujer comienza a servir en sentido antihorario mientras que el hombre lo hace en sentido horario
  en una mesa redonda. Cada persona en la mesa pide cierta cantidad de albondigas, y el objetivo del problema, es determinar si es posible
  que el hombre y la mujer lleven la misma cantidad de albondigas y puedan servirle a todos los clientes, y en el caso de que así fuera,
  indicar la posición en que terminaron el hombre y la mujer.
*/

#include <stdio.h>

int main(){

  int n,i;
  int a[30];
  int p, q;
  int r,s;

  while(1){

    scanf("%d",&n);

    if(n==0)break;

    for(i=0;i<n;i++){
      scanf("%d",&a[i]);
    }

    r=s=0;
    p=a[0];
    q=a[n-1];

    while(r!=(n-s-2)){

      if(p<=q){
	r++;
	p+=a[r];
      }
      else{
	s++;
	q+=a[(n-1)-s];
      }
    }
    if(p!=q)printf("No equal partitioning.\n");
    else printf("Sam stops at position %d and Ella stops at position %d.\n",r+1,r+2);

  }

  return 0;

}
