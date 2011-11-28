/*************************************************************************************************************************
 * 4825 - Shares
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=2826
 *
 * Classification:
 *
 * Author:
 *   Gabriela Lartiga <gabyganihonjindayo@gmail.com>
 *
 * Description:
 *
 *  Programa simple donde se debia dividir una cantidad de cosas en una cantidad
 * de personas. La unica dificultad que podria presentar el programa era que terminaba con EOF
 * y de lectura, pues tenias que dividirlo en la cantidad mas 1.
 *
 */

#include <stdio.h>
int main(){

	int people,shares,shared;
	while(scanf("%i %i",&people,&shares)!=EOF){
		shared=shares/(people+1);
		printf("%i\n",shared);
	}
return 0;
}
