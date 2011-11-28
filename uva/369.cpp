/*************************************************************************************************************************
 * 369 - Combinations
 * http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=305
 *
 * Classification: String Processing
 *
 * Author:
 *   Rodrigo Castro <r.kstro15@gmail.com> (para competencia por equipos)
 *
 * Description:
 *   Se debe calcular C = N! / ( (N-M)! * M! ), para ello de acuerdo a propiedades de los
 * Factoriales y como M <= N se hace una simplificacion de N! con M! o (N-M)! luego se calcula
 * lo que queda en el dividendo. El resultado del dividendo se va dividiendo por cada uno de los
 * factores resultantes de la expasion del factorial del divisor. En todos los casos se usan los
 * numeros divididos por 100 para no desvordar. Finalmente se muestra la salida de acuerdo a lo
 * pedido, con los modificadores de la salida para precidion y numeros "fixed" que no los muestra
 * en notacion cientifica.
 *
 */
#include <iostream>
using namespace std;

int main(int argc, char **argv){
	int N,M,NmM,N2;
	int divd[101];
	double C=1;
	while(true){
		cin >> N;
		cin >> M;
		if (N+M==0) return 0;
		NmM = N-M;
		N2 = N;
		if(M>=NmM)
			while(N2!=M) N2--;
		else
			while(N2!=NmM) N2--;
		N2++;
		for(int i=N2;i<=N;i++) C *= i/100.0;

		if(M>=NmM){
			for(int i=1;i<=NmM;i++) C = C/(i/100.0);
		} else {
			for(int i=1;i<=M;i++) C = C/(i/100.0);
		}

		cout.precision(0);
		cout << N << " things taken " << M << " at a time is " << fixed << (double)C << " exactly." << endl;
		C = 1;
	}
	return 0;
}
