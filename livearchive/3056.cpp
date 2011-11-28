/*************************************************************************************************************************
 * 3056 - Flow Layout
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=199&page=show_problem&problem=1057
 *
 * Author:
 *   Rafael Sepúlveda
 *
 * Description:
 *   Se desea ubicar una serie de bloques rectangulares en un área cuadrada cuya única restricción es el ancho. En caso de que un bloque no alcance en el ancho
 * se añade en la siguiente fila a la altura del bloque con el alto mayor en la fila anterior.
 *
 */


#include <iostream>

using namespace std;

int main(int argc,char **argv){
    while(1){
        int m;
        cin >> m;
        if (m==0) break;

        int curw=0,curh=0;
        int maxhline=0;
        int maxwcol=0;
        while(1){
            int w,h;
            cin >> w;
            cin >> h;
            if(w==-1 && h==-1)break;

            if(w+curw<=m){
                curw+=w;
                if(h+maxhline>curh)curh=h+maxhline;
                if(curw>maxwcol)maxwcol=curw;
            }
            else{
                if(curw>maxwcol)maxwcol=curw;
                curw=w;
                maxhline=curh;
                curh+=h;
            }
        }
            cout << maxwcol << " x " << curh << endl;
    }
    return 0;
}

