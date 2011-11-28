/****************************************************************************
 * 4475 - Dinner Hall
 * http://acmicpc-live-archive.uva.es/nuevoportal/data/problem.php?p=4475
 * (nueva) http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=2476
 *
 * El problema consiste en encontrar la cantidad maxima de personas que hay
 * al mismo tiempo en una cafeteria durante el dia. Hay que considerar que
 * al comienzo deldia no hay nadie, y al finalizar tampoco. Basicamente se
 * ordenan los registros por hora, y luego se procede al conteo.
 *
 *                                                      -- Rodrigo Castro
 *
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct{
   int HH;
   int MM;
   int SS;
   char x;
} hora;

int comparar(const void *a, const void *b){
   hora *x = (hora *) a;
   hora *y = (hora *) b;
   if(x->HH > y->HH) return 1;
   if(x->HH < y->HH) return -1;
   if(x->HH == y->HH) {
       if(x->MM > y->MM) return 1;
       if(x->MM < y->MM) return -1;
       if(x->MM == y->MM){
           if(x->SS > y->SS) return 1;
           if(x->SS < y->SS) return -1;
       }
   }
}

int main(int argc,char *argv[]){
   int casos=0,i=0;
   char tmpT='0';
   int tmp,mayor=0;
   char horas[3],min[3],seg[3];
   int contador=0,contadorE=0,contadorX=0,incgX=0,incgE=0;
   hora registros[64800];
   while(scanf("%i",&casos)>0){
       if(casos==0) return 0;
       for(i=0;i<casos;i++){
           tmp=scanf("%[^:]:%[^:]:%s %c ",horas,min,seg,&tmpT);
           registros[i].HH = atoi(horas);
           registros[i].MM = atoi(min);
           registros[i].SS = atoi(seg);
           registros[i].x = tmpT;
           if(tmpT=='E') contadorE++;
           if(tmpT=='X') contadorX++;
       }
       incgE = casos/2 - contadorE;
       incgX = casos/2 - contadorX;

       qsort(registros,casos,sizeof(hora),comparar);

       if(registros[0].x=='?'){ registros[0].x='E'; incgE--; contadorE++;}
       if(registros[casos-1].x=='?'){ registros[casos-1].x='X'; incgX--; contadorX++; }

       for(i=0;i<casos;i++){
           if(registros[i].x=='E'){
               contador++;
           }
           else if(registros[i].x=='X'){
               contador--;
           }
           else if(registros[i].x=='?'){
               if(incgE>0){
                   contador++;
                   incgE--;
               } else if(incgX>0){
                   contador--;
                   incgX--;
               }
           }
           if(mayor<contador) mayor=contador;
       }

       printf("%i\n",mayor);
       mayor=contador=contadorX=contadorE=0;
   }
   return 0;
}
