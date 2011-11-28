/*************************************************************************************************************************
 * 3473 - Where are my genes
 * http://livearchive.onlinejudge.org/external/34/3473.html
 *
 *
 * Author:
 *   Javier Gonzalez NOva    <javigonzalez@udec.cl>
 *   
 * Description:
 *   Dada una cadena de genes, y sabiendo que se produce una mutacion que "da vuelta" una porcion de la cadena. Nos piden
 *   encontrar la posicion de un gen en especifico, luego de que este sufriera una serie de mutaciones.
 */

#include <stdio.h> /*scanf, printf*/

void mutarGenome(int *genome, int comienzo, int termino);

int main(int argc, char* argv[]) {
    int genome[50000];
    int cantidad_genes;
    int cantidad_mutaciones;
    int cantidad_peticiones;
    int peticion_actual;
    int numGenome;
    int peticiones[100];
    int comienzo_mutacion[1000];
    int termino_mutacion[1000];
    int i;

    numGenome = 0;
    cantidad_genes = -1;

    while(cantidad_genes != 0) {
        scanf("%i", &cantidad_genes);
        for(i = 0; i < cantidad_genes; i++) {
            genome[i] = i+1;
        }

        if(cantidad_genes != 0) {
            scanf("%i", &cantidad_mutaciones);

            for(i = 0; i < cantidad_mutaciones; i++) {
                scanf("%i %i", &comienzo_mutacion[i], &termino_mutacion[i]);
            }
            while(i != 0) {
                mutarGenome(genome, comienzo_mutacion[i-1], termino_mutacion[i-1]);
                i--;
            }

            scanf("%i", &cantidad_peticiones);
            for(i = 0; i < cantidad_peticiones; i++) {
                scanf("%i", &peticion_actual);
                peticiones[i] = genome[peticion_actual-1];
            }

            numGenome++;
            printf("Genome %i\n", numGenome);
            for(i = 0; i < cantidad_peticiones; i++) {
                printf("%i\n", peticiones[i]);
            }
        }
    }
    return 0;
}

void mutarGenome(int *genome, int comienzo, int termino) {
    int i, j, tmp;
    for(i = comienzo-1, j = termino-1; i < j; i++, j--) {
        tmp = genome[i];
        genome[i] = genome[j];
        genome[j] = tmp;
    }
}

