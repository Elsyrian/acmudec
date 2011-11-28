/*************************************************************************************************************************
 * 3600 - Root of the Problem
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=19&page=show_problem&problem=1601
 *
 * Classification: Mathematics
 *
 * Author:
 *   Stephano Beneventi <stephano.bg@gmail.com>
 *
 * Description:
 *   En este problema, dados 2 enteros B y N debemos encontrar un A tal que elevado
 * a N sea lo mas cercano a B. Lo que se hace es calcular la raiz N-esima de B
 * y ese valor lo truncamos a entero, luego se imprime ese valor o su sucesor,
 * despendiendo de cual este más cerca del valor B.
 *
 */

#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main(){
	int B,N;
	int d1,d2;
	float raiz;
	double exp;
	int ans;
	float diff;

	while(1){
	    scanf("%d %d ",&B,&N);
	    if(B==0 && N==0)break;
	    exp=(double)1/N;///calculamos
	    raiz=pow(B,exp);///la raiz N-esima de B
	    ans=(int)raiz;///redondeamos truncando el valor
	    d1=(int)pow(ans,N);
	    d2=(int)pow(ans+1,N);
	    if(abs(B-d1)<abs(B-d2))printf("%d\n",ans);
	    else printf("%d\n",ans+1);
    }
}
