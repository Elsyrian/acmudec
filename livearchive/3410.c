/**************************************
 * 3410 - Laserbox
 *
 * Problema de dificultad media, un poco enredado darse cuenta de todas 
 * las condiciones.
 * Usado un arreglo bidimensional de structs para poder visualisar bien
 * todas las condiciones de termino(ver caminos ya recorridos)
 *
 * http://acmicpc-live-archive.uva.es/nuevoportal/data/p3410.pdf
 * 
 *                                           maker: Javier Rodriguez
 */

#include <stdio.h>

typedef struct ch{
  char a,b,c,d,e;
}dato;

dato tabla[100][100];
 
void limpiar(){
  int i, n;  
 for(i=0 ; i<60 ; i++){
    for(n=0 ; n<60 ; n++){
      tabla[i][n].a = 'V';
      tabla[i][n].b = 'V';         
      tabla[i][n].c = 'V'; 
      tabla[i][n].d = 'V';  
      tabla[i][n].e = 'V';
    }
  }
}

char cambio(char a){
  if(a == 'U') return 'R';
  if(a == 'D') return 'L';
  if(a == 'R') return 'D';
  if(a == 'L') return 'U';
  return a;
}


int main(){

  int i,o,casos,tam,las,x,y;
  char dir;

  scanf("%d",&casos);

  for(i=0 ; i<casos ; i++){

    limpiar();
    scanf("%d %d", &tam, &las);
    for(o=0 ; o<las ; o++){
      scanf("%d %d",&y,&x);
      tabla[y-1][x-1].a = 'T';
    }
    scanf("%d %d",&y , &x);
    if(tam + 1 == x){
      dir = 'L';
      y--;
      x = tam-1;
    }
    else if(tam + 1 == y){
      dir = 'U';
      y = tam-1;
      x--;
    }
    else if(x == 0){
      dir = 'R';
      y--;
    }
    else if(y == 0){
      dir = 'D';
      x--;
    }

    while(1){
      if(tabla[y][x].a == 'T'){
       	if(dir == 'U') tabla[y][x].b = 'U';
	if(dir == 'D') tabla[y][x].c = 'D';
	if(dir == 'L') tabla[y][x].d = 'L';
	if(dir == 'R') tabla[y][x].e = 'R';
	dir = cambio(dir);
      }
      if(dir == 'L') x--;
      if(dir == 'U') y--;
      if(dir == 'R') x++;
      if(dir == 'D') y++;

      if(tabla[y][x].b == dir || tabla[y][x].c == dir || tabla[y][x].d == dir || tabla[y][x].e == dir){
	printf("0 0\n");
	break;
      }

      if(x == -1){
	printf("%d 0\n",y+1);
	break;
      }
      if(x == tam){
	printf("%d %d\n",y+1 ,tam+1);
	break;
      }
      if(y == -1){
	printf("0 %d\n",x+1);
	break;
      }
      if(y == tam){
	printf("%d %d\n",tam+1 ,x+1);
	break;
      }
    }  
  }

  return 0;
}
