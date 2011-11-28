/***********************************************************************
 * 2617 - Noise effect
 * http://acmicpc-live-archive.uva.es/nuevoportal/data/p2617.pdf
 *
 * Problema del primer ensallo 2011, tener cuidado de tomar las 8
 * comparaciones de la ficha y de tener las comparaciones correctas.
 *
 *                                          maker: Javier Rodriguez
 */


#include <stdio.h>

int main() {

    int stand[1000][1000],scan[1000][1000];
    int n,up,side, yes,tmp;
    float porcent,total;



    while(1) {

        scanf("%d",&n);
        if(n == 0) break;
        yes = 0;
        total = 0;
        for(up=0 ; up<n ; up++) {
            for(side=0 ; side<n ; side++) {
                scanf("%d",&stand[up][side]);
            }
        }
        for(up=0 ; up<n ; up++) {
            for(side=0 ; side<n ; side++) {
                scanf("%d",&scan[up][side]);
            }
        }

        /*comparaciones*/


        for(up=0 ; up<n ; up++) {
            for(side=0 ; side<n ; side++) {
                tmp = stand[up][side] - scan[n-side-1][up];
                if(tmp < 0) tmp = -tmp;
                if(tmp <= 100) yes++;
            }
        }
        if(total < yes) total = yes;
        yes = 0;

        for(up=0 ; up<n ; up++) {
            for(side=0 ; side<n ; side++) {
                tmp = stand[up][side] - scan[side][n-up-1];
                if(tmp < 0) tmp = -tmp;
                if(tmp <= 100) yes++;
            }
        }
        if(total < yes) total = yes;
        yes = 0;

        for(up=0 ; up<n ; up++) {
            for(side=0 ; side<n ; side++) {
                tmp = stand[up][side] - scan[n-up-1][n-side-1];
                if(tmp < 0) tmp = -tmp;
                if(tmp <= 100) yes++;
            }
        }
        if(total < yes) total = yes;
        yes = 0;

        for(up=0 ; up<n ; up++) {
            for(side=0 ; side<n ; side++) {
                tmp = stand[up][side] - scan[up][side];
                if(tmp < 0) tmp = -tmp;
                if(tmp <= 100) yes++;
            }
        }
        if(total < yes) total = yes;
        yes = 0;




        /*dar vuelta*/

        for(up=0 ; up<n ; up++) {
            for(side=0 ; side<n ; side++) {

                if(side*2 == n) break;

                tmp = scan[up][side];
                scan[up][side] = scan[up][n-side-1];
                scan[up][n-side-1] = tmp;

                if(side*2 + 1 == n) break;

            }
        }
        /*segundas comparaciones*/





        for(up=0 ; up<n ; up++) {
            for(side=0 ; side<n ; side++) {
                tmp = stand[up][side] - scan[n-side-1][up];
                if(tmp < 0) tmp = -tmp;
                if(tmp <= 100) yes++;
            }
        }
        if(total < yes) total = yes;
        yes = 0;

        for(up=0 ; up<n ; up++) {
            for(side=0 ; side<n ; side++) {
                tmp = stand[up][side] - scan[side][n-up-1];
                if(tmp < 0) tmp = -tmp;
                if(tmp <= 100) yes++;
            }
        }
        if(total < yes) total = yes;
        yes = 0;

        for(up=0 ; up<n ; up++) {
            for(side=0 ; side<n ; side++) {
                tmp = stand[up][side] - scan[n-up-1][n-side-1];
                if(tmp < 0) tmp = -tmp;
                if(tmp <= 100) yes++;
            }
        }
        if(total < yes) total = yes;
        yes = 0;

        for(up=0 ; up<n ; up++) {
            for(side=0 ; side<n ; side++) {
                tmp = stand[up][side] - scan[up][side];
                if(tmp < 0) tmp = -tmp;
                if(tmp <= 100) yes++;
            }
        }
        if(total < yes) total = yes;
        yes = 0;



        porcent = total/(n*n)*100;


        printf("%.2f\n",porcent);

    }




    return 0;
}
