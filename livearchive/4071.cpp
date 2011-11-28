/*************************************************************************************************************************
 * 4071 - Bubble Gum, Bubble Gum, in the dish, how many pieces do you wish?
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=2072
 *
 *
 * Author:
 *   Rafael Sepúlveda
 *
 * Description:
 *   Este problema emula un juego de azar infantil en el que de un grupo de personas, se inicia un conteo regresivo iterando entre cada uno de los participantes
 * el ultimo en ser contado, gana. El numero a contar debe ser mayor al numero de participantes. La mayor dificultad es obtener los datos de la entrada y manejar
 * el arreglo con los nombres de los jugadores.
 */

#include <iostream>
#include <string>
#include <climits>

using namespace std;

int main(int argc,char **argv){

    int t;
    cin >> t;
    cin.ignore(INT_MAX,'\n');
    for(int i=0;i<t;i++){
        string line;
        string linea;
        getline(cin,linea);
        line=linea;
        size_t pos;
        pos=line.find(' ');
        int count=1;
        int kidcount=0;

       while(pos!=string::npos){
            string subline;
            subline=line.substr(0,pos);
            line=line.substr(pos+1);
            pos=line.find(' ');
            count++;
        }

        line=linea;
        pos=line.find(' ');
        string kid[count];

        while(pos!=string::npos){
            string subline;
            kid[kidcount]=line.substr(0,pos);
            line=line.substr(pos+1);
            pos=line.find(' ');
            kidcount++;
        }
        kid[kidcount]=line;
        string start;
        cin >> start;
        cin.ignore(INT_MAX,'\n');
        int n;
        cin >> n;
        cin.ignore(INT_MAX,'\n');
        int gum;
        for(int q=0;q<count;q++){
            if(start==kid[q]){
                gum=q;
                break;
            }
        }
        int win,gana;
        for(int h=0, win=gum;h<n;h++,win++){
            gana=win;
            if(win==count-1)win=-1;

        }
        cout << kid[gana] << endl;




    }


    return 0;
}
