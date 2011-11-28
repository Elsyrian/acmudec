/*************************************************************************************************************************
 * 2202 - Vito's Family
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=5&page=show_problem&problem=203
 *
 * Classification: Sorting
 *
 * Author:
 *   Edgardo Moreno     <egyware@gmail.com>
 *   Stephano Beneventi <stephano.bg@gmail.com>
 *   Kristoffer Ulloa	<rewpoke@gmail.com>
 *
 * Description:
 *   En este problema, partimos con un arreglo de R elementos (R casas de vecinos), donde cada Ri es la cantidad de habitantes
 * de la residencia i. Luego Hacemos sorting del arreglo, y calculamos la mediana M, esta seria la ubicacion óptima para Vito.
 * Luego calculamos la distancia desde la ubicacion óptima para Vito hasta todos los residentes de esa calle (Eso significa que
 * si hay n residentes en la casa, se multiplica por n la distancia obtenida). La sumatoria se imprime en pantalla.
 *
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void bubbleSort(int v[], int num) {
	int temp,i,j;

	for (i=0;i<num-1;i++) {
		for (j=i+1;j<num;j++){
			if (v[i] > v[j]){
				temp=v[i];
				v[i]=v[j];
				v[j]=temp;
			}
		}
	}
}

int main(){
	int casos,nfam,i=0,j=0,ncalle,optimal,sum;
	scanf("%d",&casos);
	int arreglo[1000];
	for(i=0;i<casos;i++){
		scanf("%d",&nfam);
		for(j=0;j<nfam;j++){
			scanf("%d",&ncalle);
			arreglo[j]=ncalle;
		}
		bubbleSort(arreglo,nfam);
		if(nfam%2==0){
			optimal=arreglo[nfam/2];
		}
		else{
			optimal=arreglo[(nfam-1)/2];
		}
		sum=0;
		for(j=0;j<nfam;j++){
			sum=sum+abs(optimal-arreglo[j]);
		}
		printf("%d\n",sum);
	}
}
