#include<stdio.h>
#include<stdlib.h>

/*************************************************************************************************************************
 * 2733 - Caesar Cipher
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=176&page=show_problem&problem=734
 *
 * Classification: codificacion
 *
 * Author:
 *   Mauricio Echavarria  <mechavarria@udec.cl>
 *
 * Description:
 *
 * cifrar ciertas lineas de texto de manera que cada letra quede desplazada una cierta
 * cantidad de espacios en el alfabeto, considerando el alfabeto circular. ej. si entra
 * una 'g' y debe ser desplazada 4 se obtiene 'k', si entra una B y debe ser desplazada
 * -4 se obtiene 'X'. lo mismo para los numeros. cualquier otro caracter queda igual a
 * como entra.
 *
 */

char cambiaminuscula(char car,int cantidad,int signo){
    if(signo==0) return car;
    if(signo==-1){
        if((car-97)>cantidad){
            return (car-cantidad);
        }
        else if((car-97)==cantidad){
            return 97;
        }
        else if((car-97)<cantidad){
            return (car+26-cantidad);
        }
    }
    if(signo==1){
        if((car-97)+cantidad>=26){
            return (car+cantidad-26);
        }
        else if((car-97)+cantidad<26){
            return (car+cantidad);
        }
        else if(cantidad==0){
            return car;
        }
    }
}

char cambiamayuscula(char car,int cantidad,int signo){
    if(signo==0) return car;
    if(signo==-1){
        if((car-65)>cantidad){
            return (car-cantidad);
        }
        else if((car-65)==cantidad){
            return 65;
        }
        else if((car-65)<cantidad){
            return (car+26-cantidad);
        }
    }
    if(signo==1){
        if((car-65)+cantidad>=26){
            return (car+cantidad-26);
        }
        else if((car-65)+cantidad<26){
            return (car+cantidad);
        }
        else if(cantidad==0){
            return car;
        }
    }
}

char cambianumero(char car,int cantidad,int signo){
    if(signo==0) return car;
    if(signo==-1){
        if((car-48)>cantidad){
            return (car-cantidad);
        }
        else if((car-48)==cantidad){
            return 48;
        }
        else if((car-48)<cantidad){
            return (car+10-cantidad);
        }
    }
    if(signo==1){
        if((car-48)+cantidad>=10){
            return (car+cantidad-10);
        }
        else if((car-48)+cantidad<10){
            return (car+cantidad);
        }
        else if(cantidad==0){
            return car;
        }
    }
}

int main(int argc,char *argv[]){
    char linea[240],cantidad[15];
    int i=0,numero;
    int numero_letra,numero_digito,signo;
    while(1){
        gets(linea);
        if(linea[0]=='#') return 0;
        else {
            while(linea[i]=='-' || (linea[i]>=48 && linea[i]<=57)){
                cantidad[i]=linea[i];
                i++;
            }
            cantidad[i]='\0';
            numero=atoi(cantidad);
            i++;

            numero_letra=numero_digito=numero;
            if(numero>0){
                signo=1;
                while(numero_letra>26) numero_letra=numero_letra-26;
                while(numero_digito>10) numero_digito=numero_digito-10;
            }
            else if(numero<0){
                signo=-1;
                numero_digito=numero_digito*(-1);
                numero_letra=numero_letra*(-1);
                while(numero_letra>26) numero_letra=numero_letra-26;
                while(numero_digito>10) numero_digito=numero_digito-10;
            }
            else signo=0;

            while(linea[i]!='\0'){
                if(linea[i]>=48 && linea[i]<=57) printf("%c",cambianumero(linea[i],numero_digito,signo));
                else if(linea[i]>=65 && linea[i]<=90) printf("%c",cambiamayuscula(linea[i],numero_letra,signo));
                else if(linea[i]>=97 && linea[i]<=122) printf("%c",cambiaminuscula(linea[i],numero_letra,signo));
                else printf("%c",linea[i]);
                i++;
            }
            printf("\n");
            i=0;
            numero=0;
        }
    }
    return 0;
}
