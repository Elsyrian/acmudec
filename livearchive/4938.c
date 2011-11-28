/************************************************************
*	4938 	Manual Cipher
*	http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=2939
*
*	Problema de alguna de las competencias grupales,un poco dificil, aparte de eso
*	no hay mucho que decir.
*
*
*/

#include <stdio.h>
#include <string.h>

char tabla[100][100];



int main() {

    char codeword[100],code[100];
    int i = 0,a,b,c,d;
    char asd;
    int rep[100];
    char recibir[100];
    char temp;

    scanf("%[^\n]",code);
    while(code[i] != ':') {
        codeword[i] = code[i];
        i++;
    }
    codeword[i] = '\0';
    i++;
    a = strlen(codeword);

    for(b=0 ; b<a ; b++) {
        rep[b] = code[i] - 48;
        i++;
    }

    for(b=0 ; b<a ; b++) {
        tabla[b][0] = codeword[b];
    }

    for(b=0 ; b<a ; b++) {
        asd = tabla[b][0];
        d = 1;
        for(c=1 ; c<27 ; c++) {
            if(tabla[b][c-1] == 'Z') {
                tabla[b][c] = '1';
                asd = 'A';
                d = -1;
            }
            else tabla[b][c] = asd+d;
            d++;
        }
    }


    i = 0;
    while(scanf(" %[^\n]",(recibir)) != EOF) {


        i = 0;
        b = 0;
        c = 0;
        while(recibir[i] != '\0') {

            for(b=0 ;  b<rep[c] ; b++) {
                temp = recibir[i];
                if(temp == '\0') break;
                d = 0;
                while(1) {
                    if(tabla[c][d] == temp) break;
                    if(tabla[c][d] == '1') {
                        if(temp == ' ') break;
                    }
                    d++;
                }
                if(d <= 25) printf("%c",'a'+d);
                else printf(" ");
                i++;
            }
            c++;
            if(c == strlen(codeword)) {
                c = 0;
            }
        }
        printf("\n");
    }

    return 0;
}
