#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>

using namespace std;

/*************************************************************************************************************************
 * 4886 - Page Count
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=2887
 *
 * Classification: analisis de datos
 *
 * Author:
 *   Mauricio Echavarria  <mechavarria@udec.cl>
 *
 * Description:
 * se tiene como input una cola de impresion, pero algunos intervalos son invalidos (como 8-4) y otros se
 * sobreponen (1-5,7-8,2-3,7) y otros se salen del total de paginas del documento (son 10 paginas y se pide
 * imprimir de la 5 a la 14); se debe crear un programa que tome la cola de impresion e identifique los
 * intervalos validos e invalidos y determine cuantas paginas son las que finalmente se imprimen
 *
 */

void MarcaPagina_individual(int *arreglo,int pagina,int numero_paginas){
    if(pagina<=numero_paginas) arreglo[pagina-1]=1;
}

void MarcaPagina_intervalo(int *arreglo,int extremo1,int extremo2,int numero_paginas){
    for(int i=extremo1-1;i<extremo2;i++){
        if(i<=numero_paginas-1)arreglo[i]=1;
    }
}

int main(int argc,char *argv[]){
    int numero_paginas;
    char Cnumero_paginas[6];
    int extremo1,extremo2,indicador_extremo=1;
    char Cextremo1[5],Cextremo2[5];
    int largo_linea;
    int i,j=0;
    char linea[1005];
    int paginas[1005];
    int se_imprimen=0;
    while(1){

        for(i=0;i<1005;i++) paginas[i]=0;
        gets(Cnumero_paginas);
        numero_paginas=atoi(Cnumero_paginas);
        if(numero_paginas==0) return 0;
        gets(linea);
        largo_linea=strlen(linea);
        paginas[numero_paginas]=2;
        linea[largo_linea]='\n';
        linea[largo_linea+1]='\0';

        for(i=0;i<largo_linea+1;i++){
            if(linea[i]>=48 && linea[i]<=57 && indicador_extremo==1){
                Cextremo1[j]=linea[i];
                j++;
            }
            else if(linea[i]=='-'){
                indicador_extremo=2;
                Cextremo1[j]='\0';
                j=0;
                extremo1=atoi(Cextremo1);
            }
            else if(linea[i]>=48 && linea[i]<=57 && indicador_extremo==2){
                Cextremo2[j]=linea[i];
                j++;
            }
            else if(linea[i]==',' || linea[i]=='\n'){
                if(indicador_extremo==1){
                    Cextremo1[j]='\0';
                    j=0;
                    extremo1=atoi(Cextremo1);
                    MarcaPagina_individual(paginas,extremo1,numero_paginas);
                }
                else if(indicador_extremo==2){
                    indicador_extremo=1;
                    Cextremo2[j]='\0';
                    j=0;
                    extremo2=atoi(Cextremo2);
                    if(extremo1<=extremo2){
                        MarcaPagina_intervalo(paginas,extremo1,extremo2,numero_paginas);
                    }
                }
            }
        }


        for(i=0;paginas[i]!=2;i++){
            if(paginas[i]==1) se_imprimen++;
            /*cout << paginas[i];*/
        }

        printf(/*"\nse imprimen: */"%d\n",se_imprimen);
        se_imprimen=0;


        /*cout << endl;*/

    }
    return 0;
}
