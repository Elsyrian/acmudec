/****************************************************************************
 * 2362 - Financial Management
 * http://acm.uva.es/archive/nuevoportal/data/problem.php?p=2362
 * 
 * Classification: AdHoc
 *
 * Author: 
 *   Diego Caro <diegocaro@gmail.com>
 *
 * Description: 
 *   Este problema es fácil de resolver, solo es necesario calcular el
 * promedio de los salarios y tener cuidado al imprimir los números decimales.
 *
 * Este es un problema muy facil! Tipo queso.
 *
 *                                                      -- Diego Caro
 */

#include<stdio.h>

int main() {
    float a,b;  
    while(scanf("%f", &a)!=EOF) {
    
        b += a/12;
    
    }
    printf("$%.2f\n",b);
}
