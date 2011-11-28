/******************************************
*           2651 - ISBN
*           http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=652
*
*           Programa relativamente sencillo, es mas eficiente leer la entrada como un string y
*           luego trabajar sobre ella, transformando a enteros.
*
*           autor: Javier Rodriguezq.
*/
#include <stdio.h>

int main() {

    int a,i,num[10];
    char in[15];

    while(scanf("%s",in) != EOF) {

        i = 0;
        a = 0;
        while(i<9) {
            if(in[a] != '-') {
                num[i] = in[a]-48;
                i++;
            }
            a++;
        }
        a = num[0]*10 + num[1]*9 + num[2]*8 + num[3]*7 + num[4]*6 + num[5]*5 + num[6]*4 + num[7]*3 + num[8]*2;
        i = 0;
        while(a%11 != 0) {
            a++;
            i++;
        }
        if(i == 10) printf("%s-X\n",in);
        else printf("%s-%d\n",in,i);


    }



    return 0;
}
