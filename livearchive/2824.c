/************************************************************
 * 2824 - Crypto Columns                                    *
 * http://livearchive.onlinejudge.org/external/28/2824.html *
 * Tenemos que resolver una frase "encriptada" en base a    *
 * una palabra clave.                                       *
 * El problema pasa primordialmente por manejar strings     *
 * Autor: Javier González Nova                              *
 ************************************************************/

#include <stdio.h> /*scanf, printf*/
#include <string.h> /*strcmp, strcat*/

/*Almacena una letra y la cantidad de veces que aparece en un texto.*/
typedef struct{
  char letter;
  int ocurrence;
}Letter;

int main(int argc, char* argv[]){
  char keyword[11]; /*Palabra clave, la dan en el input*/
  int order[10]; /*Orden en el que iran las columnas*/
  int orderSorted[10]; /*Orden "ordenado" por numero de columna*/
  int finalPos; /*Usado para obtener orderSorted*/
  Letter letters[10]; 
  char ciphertext[101]; /*Se da en el input*/
  char originaltext[101]; /*Texto final, no encriptado*/
  int keywordLength; /*Largo de la palabra clave*/
  int ciphertextLength; /*Largo del Ciphertext*/
  int i,j,k; /*Contadores*/
  int isRegister; /*Flag:Indicia si el array letras contiene una letra en especifico*/
  int colHeight; /*Altura de las columnas*/
  char fragments[10][20]; /*Cada fila sera un fragmento de texto*/

  /*Le damos valores iniciales a Letters y order para evitar errores*/
  for(i = 0; i < 10; i++){
    letters[i].letter = 'a';
    letters[i].ocurrence = 0;
    order[i] = 0;
  }

  while(1){
    scanf("%s", keyword);
    scanf("%s", ciphertext);

    /*Si keyword es THEEND, se termina el programa*/
    if(strcmp(keyword, "THEEND") == 0)
      break;

    /*Almacenamos las longitudes de keyword y ciphertext*/
    keywordLength = strlen(keyword);
    ciphertextLength = strlen(ciphertext);

    /*Obtenemos las posiciones de las columnas, deducido de keyword*/
    for(i = 0; i < keywordLength; i++){
      for(j = 0; j < keywordLength; j++){
	/*Si una letra es mayor a otra (Comparacion ASCII, es igual que el abc)
	  Entonces significa que estara una posicion mas adelante que esa letra*/
	if(keyword[i] > keyword[j]){
	  order[i]++;
	}
	/*Revisamos si la letra esta repetida, nos interesa que sean letras
	  que esten antes de la letra actual en el texto solamente.*/
	if((keyword[i] == keyword[j]) && (i > j)){
	  isRegister = 0;
	  /*Si ya habia una ocurrencia, seguimos sumando...*/
	  for(k = 0; k < 10; k++){
	    if(letters[k].letter == keyword[i]){
	      letters[k].ocurrence++;
	      isRegister = 1;
	      break;
	    }
	  }
	  /*Si no habia ninguna, tomamos un elemento del array letras que este vacio
	    (con una a) y le asignamos nuestra letra actual*/
	  if(!isRegister){
	    for(k = 0; k < 10; k++){
	      if(letters[k].letter == 'a'){
		letters[k].letter = keyword[i];
		letters[k].ocurrence = 1;
		break;
	      }
	    }
	  }
	}
      }
      /*Ya tenemos calculado la posicion, pero sin contar letras repetidas.
	Asi que sumamos el numero de ocurrencias.*/
      for(k = 0; k < 10; k++){
	if(keyword[i] == letters[k].letter){
	  order[i] += letters[k].ocurrence;
	  letters[k].ocurrence = 0;
	}
      }

    }

    /*Ordenamos de la primera columna a la ultima
     i = 0, primera columna. i = 1, segunda....*/
    for(i = 0; i < keywordLength; i++){
      finalPos = 0;
      for(j = 0; j < keywordLength; j++){
	if(order[i] > order[j]){
	  finalPos++;
	}
      }
      orderSorted[finalPos] = i;
    }

    /*Cambio el indice por el valor, por ejemplo si L[0]=32. 
      Lo cambio por L[32] = 0. Lo hago por que es mas facil trabajar
      asi despues.*/
    for(i = 0; i < keywordLength; i++){
      order[orderSorted[i]] = i;
    }
    
    colHeight = ciphertextLength/keywordLength;
    /*order[j]: Columna
      colHeight: Altura
      Asi por ejemplo, para obtener la primera letra de la columna 2
      Es: Columna: 1(Parte de 0), colHeight: 4(por ejemplo), i:0 (primera letra)
      Entonces, 4*1+0 = 4. 4 es el indice donde esta la letra que buscamos.*/
    for(i = 0; i < colHeight; i++){
      for(j = 0; j < keywordLength; j++){
	fragments[i][j] = ciphertext[(order[j]*colHeight)+i];
      }
      fragments[i][j] = '\0';
    }

    /*Finalmente, unimos todos los fragmentos con strcat.*/
    for(i = 0; i < colHeight; i++){
      strcat(originaltext, fragments[i]);
    }
    
    /*Imprimimos el resultado*/
    printf("%s\n", originaltext);
    originaltext[0] = '\0';
    
    /*Y listo!, volvemos a los valores iniciales para que el juez siga preguntando.*/
    for(i = 0; i < 10; i++){
      letters[i].letter = 'a';
      letters[i].ocurrence = 0;
      order[i] = 0;
    }

  }
  return 0;
}
