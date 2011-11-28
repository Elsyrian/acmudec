/**************************************************************************************************************************
 * 2557 - The Drunk Jailer
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=207&page=show_problem&problem=558
 *
 * Author:
 *   Cathy Espinoza <nikkita126@gmail.com>
 *
 * Description:
 *   El problema nos pide determinar cuántas celdas quedan abiertas luego de que el carcelero
 * se pasee abriendo y cerrádolas alternadamente de acuerdo a la cantidad de recorridos que
 * ha hecho por el pasillo que da a las puertas de las celdas. No posee mayor complejidad, y
 * el truco para acelerar el proceso es darse cuenta la relación matemática entre la cantidad de
 * celdas y las puertas que quedan abiertas en cada caso.
 *
 *                                                      -- Cathy Espinoza
 */

#include <stdio.h>

int main(){
  
  int casos,celdas,i,total;
  scanf("%d",&casos);
  
  for(i=0;i<casos;i++){
    
    scanf("%d",&celdas);
    
    switch(celdas){

    case 5 ... 8:
      total=2;
      break;
    case 9 ... 15:
      total=3;
      break;
    case 16 ... 24:
      total=4;
      break;
    case 25 ... 35:
      total=5;
      break;
    case 36 ... 48:
      total=6;
      break;
    case 49 ... 63:
      total=7;
      break;
    case 64 ... 80:
      total=8;
      break;
    case 81 ... 99:
      total=9;
      break;
    case 100:
      total=10;
    }
    printf("%d\n",total);
    
  }
  
  return 0;
}

