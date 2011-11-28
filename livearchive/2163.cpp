/****************************************************************************
 * 2163 - Led Codes
 * http://acmicpc-live-archive.uva.es/nuevoportal/data/problem.php?p=2163
 *
 * Se dan ciertas entradas con string, pero en algunos casos se da una secuencia de
 * numeros que representan a una letra del abecedario con luces LED. La dificultad
 * radicaba en saber que secuencia identificaba a cada letra y programar algo que
 * identificara estas secuencias.
 *                                                      -- Francisco Serrano
 *
 */

#include <iostream>
#include <string>
using namespace std;

string caracter;
int i;

void letra(){
    if(caracter.at(i)=='1'){ //1
        i++;
        if(caracter.at(i)=='2'){ //12
            i++;
            if(caracter.at(i)=='3'){ //123
                i++;
                if(caracter.at(i)=='4'){ //1234
                    i++;
                    if(caracter.at(i)=='5'){ // 12345
                        i++;
                        if(caracter.at(i)=='6'){ // 123456
                            i++;
                            if(caracter.at(i)=='7'){// 1234567 B
                                cout <<"B";
                                return;
                            }
                        }
                        else if(caracter.at(i)=='7'){// 123457 A
                            cout << "A";
                            return;
                        }
                        else if(caracter.at(i)=='9'){// 123459 R
                            cout << "R";
                            return;
                        }
                    }
                    else if(caracter.at(i)=='7'){ //12347 Q
                        cout << "Q";
                        return;
                    }
                }
                if(caracter.at(i)=='5'){ //1235
                    i++;
                    if(caracter.at(i)=='6'){ //12356
                        i++;
                        if(caracter.at(i)=='7'){//123567 O
                            cout << "O";
                            return;
                        }
                    }
                    else if(caracter.at(i)=='7'){ //12357 M
                        cout << "M";
                        return;
                    }
                }
            }
            else if(caracter.at(i)=='4'){ //124
                i++;
                if(caracter.at(i)=='5'){
                    i++;
                    if(caracter.at(i)=='6'){//12456 E
                        cout << "E";
                        return;
                    }
                }
                else if(caracter.at(i)=='6'){ //1246
                    i++;
                    if(caracter.at(i)=='7'){ // 12467 S
                        cout << "S";
                        return;
                    }
                }
                else if(caracter.at(i)=='9'){ //1249 F
                    cout << "F";
                    return;
                }

            }
            else if(caracter.at(i)=='5'){ //125
                i++;
                if(caracter.at(i)=='6'){ //1256
                    i++;
                    if(caracter.at(i)=='9'){ //12569 G
                        cout << "G";
                        return;
                    }
                }
            }
        }
        else if(caracter.at(i)=='3'){ //13
            i++;
            if(caracter.at(i)=='4'){ //134
                i++;
                if(caracter.at(i)=='5'){ //1345
                    i++;
                    if(caracter.at(i)=='7'){ //13457 H
                        cout << "H";
                        return;
                    }
                    else if(caracter.at(i)=='9'){//13459 K
                        cout << "K";
                        return;
                    }
                }
                else if(caracter.at(i)=='7'){ //1347 Y
                    cout << "Y";
                    return;
                }
            }
            else if(caracter.at(i)=='5'){ //135
                i++;
                if(caracter.at(i)=='6'){ //1356
                    i++;
                    if(caracter.at(i)=='7'){//13567 U
                        cout << "U";
                        return;
                    }
                }
                else if(caracter.at(i)=='7'){ //1357
                    i++;
                    if(caracter.at(i)=='9'){ //13579
                        i++;
                        if(caracter.at(i)=='0'){ // 135790 W
                            cout << "W";
                            return;
                        }
                    }
                }
            }
            else if(caracter.at(i)=='7'){//137
                i++;
                if(caracter.at(i)=='9'){//1379 V
                    cout << "V";
                    return;
                }
            }
        }
        else if(caracter.at(i)=='4'){//14
            i++;
            if(caracter.at(i)=='5'){ //145
                i++;
                if(caracter.at(i)=='8'){ //1458 P
                    cout << "P";
                    return;
                }
            }
        }
        else if(caracter.at(i)=='5'){//15
            i++;
            if(caracter.at(i)=='6'){ //156 L
                cout << "L";
                return;
            }
            else if(caracter.at(i)=='8'){ //158
                i++;
                if(caracter.at(i)=='0'){ //1580 D
                    cout << "D";
                    return;
                }
            }
        }
    }
    else if(caracter.at(i)=='2'){ //2
        i++;
        if(caracter.at(i)=='3'){ //23
            i++;
            if(caracter.at(i)=='4'){ //234
                i++;
                if(caracter.at(i)=='5'){ //2345
                    i++;
                    if(caracter.at(i)=='6'){ // 23456 Z
                        cout << "Z";
                        return;
                    }
                }
            }
        }
        else if(caracter.at(i)=='7'){ //27
            i++;
            if(caracter.at(i)=='8'){ //278 T
                cout << "T";
                return;
            }
        }
    }
    else if(caracter.at(i)=='3'){ //3
        i++;
        if(caracter.at(i)=='5'){ //35
            i++;
            if(caracter.at(i)=='6'){ //356
                i++;
                if(caracter.at(i)=='7'){ //3567 J
                    cout << "J";
                    return;
                }
            }
            else if(caracter.at(i)=='7'){ //357
                i++;
                if(caracter.at(i)=='9'){ //3579 N
                    cout << "N";
                    return;
                }
            }
        }
        else if(caracter.at(i)=='7'){ //37 I
            cout << "I";
            return;
        }
    }
    else if(caracter.at(i)=='4'){
        i++;
        if(caracter.at(i)=='5'){
            i++;
            if(caracter.at(i)=='6'){ //456 C
                cout << "C";
                return;
            }
        }
    }
    else if(caracter.at(i)=='9'){
        i++;
        if(caracter.at(i)=='0'){ //90 X
            cout << "X";
            return;
        }
    }
}

int main(int argc, char** argv) {

    int casos;
    cin >> casos;
    int j;
    int largo;
    getline (cin,caracter);
    for(j=0;j<casos;j++){
        getline (cin,caracter);
        largo=caracter.size();
        cout << "Phrase "<< j+1 <<": ";
        for(i=0;i<largo;i++){
        if(caracter.at(i)=='0')cout << " ";
        else if(caracter.at(i)=='1' || caracter.at(i)=='2' || caracter.at(i)=='3' || caracter.at(i)=='4' || caracter.at(i)=='5' || caracter.at(i)=='6' || caracter.at(i)=='7' || caracter.at(i)=='8' || caracter.at(i)=='9') letra();
        else cout << caracter.at(i);
        }
        i=0;
        cout << endl;


    } // FIN for

  return 0;
 }
