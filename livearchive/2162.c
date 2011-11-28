#include <stdio.h>
#include <math.h>

/*************************************************************************************************************************
 * 2162 - S-Trees
 * 
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=163
 *
 * Classification: analisis de datos
 *
 * Author:
 *   Luis Jury <zeui16@gmail.com>
 *
 * Description:
 *
 * Dado un arbol binario, que representa una funcion boleana, hay que entregar el resultado que se tiene al evaluar ciertos
 * valores, en la funcion.
 *
 * El problema era simple, cada nodo, tiene 2 ramificaciones, si el argumento es 0, tomas la ramificacion izquierda, si el argumento
 * es 1, tomas la ramificacion derecha, lo interezante era darse cuenta, de que al tener que evaluar por ejemplo "1001", si uno
 * cambia el numero a base 10, se logra obtener facilmente el valor que se busca, el problema del ejercicio, era que la funcion 
 * tenia los argumentos desordenados, por lo que hay que ordenar el numero a "evaluar"
 * 
 */

int main()
{
  int n,m,i,j,t,k,total_nodes;
  int var_order[7];
  int vva[128];
  char func_res[9];
  char c;

  t=1;  

  while( scanf("%d", &n ) && n != 0 )
    {
      printf("S-Tree #%i\n",t);
      total_nodes = 1 << n;

      /* escanea el orden de las variables (argumento de la funcion) */
      i = 0;
      while( i < n)
	{
	  c = getchar(); 
	  if( c == 'x' )
	    {
	      var_order[i] = getchar()-'1';
	      i++;
	    }
	}
      
      for(i= 0; i < total_nodes; i++)
	scanf("%1d", &vva[i]);
  
      scanf("%d", &m);
     
      for(j = 0; j < m; j++)
	{
	  scanf(" %[^\n]", func_res);
	  
	  k = 0;

	  for(i = 0; i < n; i++)
	    {
	      /* Se pasa el numero de base 2 a base 10, siguiendo el orden que se entrego para los argumentos de la funcion */
	      if( func_res[var_order[i]]-'0' == 1 )
		{
		  k += pow(2,(n-i-1));
		}
	    }
	  printf("%i",vva[k]);
	}      
      printf("\n\n");

      t++;
    }
  return 0;
}
