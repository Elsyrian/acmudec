/*********************************************************************
* Nombre(Codigo): T-shirt Size Distribution(4937)                    *
* URL: http://acm.uva.es/archive/nuevoportal/data/problem.php?p=4937 *
* Problema: Calcular la cantidad de poleras estimada de cada talla   *
*           dado una serie de datos previos.                         *
* Autor: Javier Gonzalez Nova                                        *
* ********************************************************************

#include <stdio.h> /*scanf y printf*/

/*entry point*/
int main(void){
  int n[7]; /*Cantidad de poleras de cada talla, XS, S, M, L, XL, XXL, XXXL respectivamente.*/
  int p[7]; /*T-shirt size count de cada talla.*/
  float N; /*Cantidad total de poleras*/
  float P; /*Cantidad estimada de poleras a comprar*/
  int S; /*Cantidad estimada - Sumatoria de todos los T-Shirt size count*/
  int sumP; /*Sumatoria de todos los T-Shirt size count*/
  int emptyCount; /*Actua como bool(Verdad o falso). Es verdad si es que no hay ningun p(T-Shirt size count) que sea 0*/

  int i; /*Contador*/

  S = -1; /*Se le asigna un valor de -1 para poder entrar al while por primera vez*/

 while(scanf("%d %d %d %d %d %d %d %f", &n[0], &n[1], &n[2], &n[3], &n[4], &n[5], &n[6], &P) != EOF){
   N = 0; /*Se resetea en cada loop*/
   sumP = 0; /*Se resetea en cada loop*/
   
   /*Se calcula la cantidad total de poleras*/
   for(i = 0; i < 7; i++){
     N += n[i]; 
   }
   
   /*Se calcula cada T-Shirt size count y ademas, la sumatoria de todas ellas.*/
   for(i = 0; i < 7; i++){
     p[i] = (int)((P*n[i])/(N));
     sumP += p[i];
   }
   
   /*Calcula S*/
   S = P - sumP;
   while(S != 0){
     sumP = 0; /*Se resetea en cada loop*/
     /*Se calcula sumP*/
     for(i = 0; i < 7; i++){
       sumP += p[i];
     }
     
     /*Se vuelve a comprobar el valor de S, en el primer loop no tiene mucho sentido. 
     Es para el segundo loop y superiores.*/
     S = P - sumP;

     /*Si S aun es distinto de 0, buscamos los p que sean 0 y les sumamos 1. 
     Si ya no quedan p que sean 0, sumamos 1 al p correspondiente a la talla XL hasta que S = 0*/
     if(S != 0){
       emptyCount = 1;
       for(i = 0; i < 7; i++){
	 if(p[i] == 0){
	   p[i]++;
	   emptyCount = 0;
	   break;
	 }
       }

       if(emptyCount){
	 p[4]++;
       }
     }
   }
   
   /*Se imprime el resultado en pantalla. 
   El if esta porque el problema especifica que no pueden haber espacios ni antes ni despues del output.*/
   for(i = 0; i < 7; i++){
     if(i < 6)
       printf("%d ", p[i]);
     else
       printf("%d", p[i]);
   }
   printf("\n");
 }

 return 0; /*exit success*/
}
