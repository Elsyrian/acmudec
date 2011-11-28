/*************************************************************************************************************************
 * 4808 - Digits Count
 * http://livearchive.onlinejudge.org/external/48/4808.html
 *
 * Author:
 *   Javier Gonzalez Nova     <javigonzalez@udec.cl>
 *   
 * Description:
 *   Dados dos numeros a y b, con a < b. Nos piden contar cuantas veces se repite cada digito (0-9) entre a y b, inclusive.
 */

#include <stdio.h>
#include <vector>

using namespace std;

vector<int> countDigits(int number);

int main(int argc, char* argv[]) {
	int start, end;
	int i;
	vector<int> numStart, numEnd;
	
	while(1) {
		scanf("%d %d", &start, &end);
		
		if((start == 0) && (end == 0)) 
			break;
		
		/*Le resto 1 a start porque despues restare numStart y numEnd y tendre que sumarle
		la interseccion entre ambos. A menos que le reste 1 a start =D*/
		numStart = countDigits(start-1); 
		numEnd = countDigits(end);
		
		for(i = 0; i < 10; i++) 
			numEnd[i] -= numStart[i];
			
		printf("%d", numEnd[0]);
		for(i = 1; i < 10; i++) {
			printf(" %d", numEnd[i]); 	
		}				
		printf("\n");
	}	
	
	return 0;
}

vector<int> countDigits(int number) {
	vector<int> digits(10, 0); /*Vector con 10 elementos y todos con valor 0.*/
	int currentNumber;	
	int i;	
	
	if(number > 30000) {
		/*Contamos por fuerza bruta hasta que encontremos un numero que termine en 9999*/
		while((number%10000) != 9999) {
			currentNumber = number;
			while(currentNumber) {
				digits[currentNumber%10]++;
				currentNumber /= 10;
			}
			number--;				
		}	
		
		/*Vamos a contar hasta que lleguemos a 19999*/
		/*Vamos a usar este patron
			X0000 a X9999 = [4000, 4000, 4000, 4000, 4000, 4000, 4000, 4000, 4000, 4000]
			donde X es un numero cualquiera. Luego al array de los digitos sumamos 10000 a cada digito
			que aparece en X. (Ejemplo: X = 12, Entonces sumamos mil veces 1 y mil veces 2*/
		while(number > 20000) {
			/*Se suman los 4000 a cada digitos, estos estaran si o si*/
			for(i = 0; i < 10; i++)
				digits[i] += 4000;		
			/*Sumamos 10000 a cada digito que aparece*/
			currentNumber = number/10000; /*Si el numero es 12349999, currentNumber es 1234*/
			while(currentNumber) {
				digits[currentNumber%10] += 10000;
				currentNumber /= 10;
			}				
			number -= 10000; /*Si el numero es 39999, queda en 29999. Y repetimos el proceso hasta 19999*/
		}
	}
	
	if(number > 3000) {
		/*Contamos por fuerza bruta hasta que encontremos un numero que termine en 999*/
		while((number%1000) != 999) {
			currentNumber = number;
			while(currentNumber) {
				digits[currentNumber%10]++;
				currentNumber /= 10;	
			}	
			number--;
		}	
		
		/*Vamos a contar hasta que lleguemos a 1999*/
		/*Vamos a usar este patron
			X000 a X999 = [300, 300, 300, 300, 300, 300, 300, 300, 300, 300]
			donde X es un entero cualquiera. Luego se le suma 1000 a cada digito que aparece en X.*/
		while(number > 2000) {
			for(i = 0; i < 10; i++)
				digits[i] += 300;	
			
			currentNumber = number/1000;
			while(currentNumber) {
				digits[currentNumber%10] += 1000;	
				currentNumber /= 10;
			}				
			number -= 1000;
		}
	}
	
	for(i = 1; i <= number; i++) {
		currentNumber = i;
		while(currentNumber) {
			digits[currentNumber%10]++;
			currentNumber /= 10;	
		}
	}
	
	return digits;	
}
