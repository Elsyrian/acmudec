/*************************************************************************************************************************
 * 4936 - Atlas Pagination
 * http://livearchive.onlinejudge.org/external/49/4936.html
 *
 * Classification: String Processing
 *
 * Author:
 *   Javier González     <javigonzalez@udec.cl>
 *
 * Description:
 *   Tenemos que, dado un mapa, seccionarlo en cuadrados iguales y luego identificar las zonas donde no hay sombra y
 * darles un numero de pagina  a estas(de izquierda a derecha, de arriba hacia abajo). Y entregar la informacion 
 * de cada pagina y sus referencias(Referencia: Lugar sin sombra en alguna de las direcciones de una pagina). 
 */

#include <stdio.h> /*scanf, printf*/

int main(int argc, char* argv[]) {
  int columnas; /*Columnas del mapa*/
  int filas; /*Filas del mapa*/
  int mapa[30][30]; /*Mapa, maximo de 30x30*/
  int i, j; /*Contadores*/
  int paginaActual; /*Ultimo numero que se uso para paginar*/
  char grid; /*Indica si el cuadrado actual es .(sin sombra) o X(sombra)*/

  while(scanf("%d", &filas) != EOF) {
    scanf("%d", &columnas);
    
    getchar(); /*Esto es porque al apretar enter, hay que captuar el \n*/

    paginaActual = 1;
    /*Se recorre el array mapa, y al mismo tiempo se va recolectando la 
      informacion de input.*/
    for(i = 0; i < filas; i++) {
      for(j = 0; j < columnas; j++) {
	grid = getchar();
	if(grid == '.') {
	  mapa[i][j] = paginaActual;
	  paginaActual++;
	} else {
	  mapa[i][j] = 0;
	}
      }
      getchar(); /*Este captura el salto de linea*/
    }

    /*Se vuelve a recorrer el array mapa, pero ahora esta lleno con informacion*/
    /*Si la zona no tiene sombra, se imprime su nº de pagina y las paginas 
      que estan arriba, abajo, derecha e izquierda de la zona actual*/
    /*Se imprime el numero de pagina, si no tiene sombra, 0 en caso contrario*/
    for(i = 0; i < filas; i++) {
      for(j = 0; j < columnas; j++) {
	if(mapa[i][j] != 0) {
	  printf("%d ", mapa[i][j]);
	  
	  /*top*/
	  if((i-1) < 0)
	    printf("%d ", 0);
	  else
	    printf("%d ", mapa[i-1][j]);

	  /*right*/
	  if((j+1) >= columnas)
	    printf("%d ", 0);
	  else
	    printf("%d ", mapa[i][j+1]);

	  /*bottom*/
	  if((i+1) >= filas)
	    printf("%d ", 0);
	  else
	    printf("%d ", mapa[i+1][j]);

	  /*left*/
	  if((j-1) < 0)
	    printf("%d", 0);
	  else
	    printf("%d", mapa[i][j-1]);

	  printf("\n");
	}
      }
    }
    printf("\n");
  }

  return 0;
}
