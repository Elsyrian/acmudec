/****************************************************************************
 * 4215 - Feynman
 *http://acm.uva.es/archive/nuevoportal/data/problem.php?p=4215
 *
 * Problema MUY fácil. La única "dificultad" es darse cuenta de la relación
 * matemática del total de cuadrados.
 *                                                      -- Cathy Espinoza
 *
 */



#include <stdio.h>
 
int main () {
 
  int num, i, cuad;
 
  while (1) {
 
    scanf("%d", &num);
 
    if (num==0) break;
 
    cuad=0;
 
    for(i=1; i<=num; i++) {
 
      cuad=cuad+i*i;
 
    }
 
    printf("%d\n", cuad);
 
  }
 
 
 
  return 0;
}
