/**********************************************
 * 2759 - Common Subsequence
 * http://acmicpc-live-archive.uva.es/nuevoportal/data/problem.php?=2759
 * 
 * Se pide encontrar la subsecuencia mas larga de 2 strings
 *                                          -- Daniel Campos
 *
 *********************************************/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  string s1, s2;
  int mat[2][1000000]; //no es necesario almacenar toda la matriz solo la fila
  							  //que se esta analizando y la anterior

  while(1){
    s1 = ""; //en el juez no sirve s1.clear() por eso se ocupo esto
    cin >> s1 >> s2; //se leen los strings
    if(s1.empty()) //si el primero esta vacio termina la entrada
      break;
    
    for(unsigned int i=0;i<=s1.size();i++)
      mat[0][i] = 0;

    for(unsigned int i=0;i<s2.size();i++){
      mat[1][0] = 0;
      for(unsigned int j=1;j<=s1.size();j++){
      	//caso en que los caracteres sean iguales
      	//no considera que se haya usado antes a este caracter para formar una
      	//subsecuencia
			if(s2[i] == s1[j-1])
	  			mat[1][j] = mat[0][j-1]+1;
	  		
	  		//si los caracteres son distintos, se elige el maximo sin dar
	  		//importancia a si se ocupo o no el caracter que se esta analizando
			else
	  			mat[1][j] = max(mat[0][j], mat[1][j-1]);
      }
		
		//la final que se acaba de analizar pasa a ser la final anterior
      for(unsigned int j=0;j<=s1.size();j++)
			mat[0][j] = mat[1][j];
    	}
    
    cout << mat[1][s1.size()] << endl;
  }
}
