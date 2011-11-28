/************************************************************************
* 3470 - Pascal Library
* http://acmicpc-live-archive.uva.es/nuevoportal/data/problem.php?p=3470 
*
* En este problema se entrega como entrada en la primera linea un numero de * alumnos(num) y un numero de cenas(din).
* Las siguientes lineas serán el numero de cenas que contienen tantos ceros * o unos como alumnos se haya indicado en la primera linea.
* Los ceros indican que el alumno no fue a la cena y los unso que el alumno * fue a la cena.
*
* Para resolver el problema utilicé un arreglo bidimensional y los fui
* comparando por "columna".
* Si existe un alumno que asistió a todas las cenas, el programa imprime
* "yes".
* Si no existe un alumno que asistió a todas las cenas, el programa imprime
* "no".
*  La condición de cierre de programa es 0 0
*                                     --Gabriela Lártiga
*/
#include <stdio.h>


int main(){
  int num=0;
  int din=0;
  int i=0;
  int j=0;
  int si=0;
  int diners[100][500];

while(1){

  si = 0;
    scanf("%i %i", &num, &din);
    if(num==0 && din==0){return 0;} /* Condición de cierre de programa */

	for(i=0;i<din;i++){
	   for(j=0;j<num;j++){
		scanf("%i", &diners[j][i]);
	   }
	}


   	for(i=0;i<num;i++){

 	    for(j=0;j<din;j++){
	     	if(diners[i][j]==1){
		si++;
		}
	    }
	    if(si==din){
		goto answer;
	    }
	    else
		si=0;
	}

answer:
	if(si==din){
	   printf("yes\n");
	}
	if(si!=din){
	   printf("no\n");
	}

}

 return 0;
}

