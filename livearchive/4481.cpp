/*************************************************************************************************************************
 * 4481 - Jingle Composing
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=365&page=show_problem&problem=2482
 *
 * Classification: Mathematics
 *
 * Author:
 *   Rafael Sepulveda     <so.what.mdo@gmail.com>
 *
 * Description:
 *   El objetivo del problema es que dado cierta codificacion letra-valor (separadas por un slash), determinar cuántos subsets
 * de letras en una linea sumaban 1.
 *
 **************************************************************************************************************************/

#include <iostream>
using namespace std;

struct note{
    char nombre;
    float valor;

};

note array[7];



float obtener_valor(char letra){
    for(int i=0; i<7;i++){
        if (letra==array[i].nombre)return array[i].valor;
    }

}

int main(int argc, char* *argv){
array[0].nombre='W';
array[1].nombre='H';
array[2].nombre='Q';
array[3].nombre='E';
array[4].nombre='S';
array[5].nombre='T';
array[6].nombre='X';
array[0].valor=1;
array[1].valor=0.5;
array[2].valor=0.25;
array[3].valor=0.125;
array[4].valor=0.0625;
array[5].valor=0.03125;
array[6].valor=0.015625;

while (1){

    string line;
    cin >> line;
    if (line=="*") return 0;

    int correctas=0;
    for(int i=0;i<line.length();i++){
        if(i==line.length()-1)break;
        if (line.at(i)=='/'){

            int j=i+1;
            float sumaset=0;
            while(line.at(j)!='/'){
                sumaset=sumaset+obtener_valor(line.at(j));
                j++;
                if(line.at(j)=='/')i=j-1;

            }
            if(sumaset==1)correctas++;

        }



    }
    cout << correctas << endl;



}




return 0;


}
