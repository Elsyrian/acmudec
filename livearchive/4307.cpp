/****************************************************************************
 * 4307 - Binary Clock
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=329&problem=2308
 *
 * El problema consiste en traducir la hora de un reloj, en formato binario expresados por
 * () como 0 y (*) como 1, a formato decimal en formato HH:MM:SS. La funcion exp(int a, int b)
 * calcula a^b, bin2dec(string bin) transforma un numero binario como string, a al valor decimal.
 * El problema se aborda recibiendo cada uno de los digitos por separados y transformandolos
 * cada uno a decimal.
 *
 *                                                      -- Rodrigo Castro
 *
 */


#include <iostream>
#include <string>
using namespace std;

int exp(int b, int e){
    int acm = 1;
    for(int i=0;i<e;i++) acm *= b;
    return acm;
}

int bin2dec(string bin){
    int tam = bin.length();
    int acm = 0;
    for(int i=0;i<tam;i++){
        acm += (bin[tam-i-1]-'0')*exp(2,i);
    }
    return acm;
}

int main(int argc, char **argv){
    int casos, count=0, tam;
    string buffer, hr1="", hr2="", min1="", min2="", seg1="", seg2="";
    cin >> casos;
    cin.ignore();
    for(int i=1;i<=casos;i++){
        hr1=""; hr2=""; min1=""; min2=""; seg1=""; seg2="";
        count = 0;
        getline(cin,buffer);
        tam = buffer.length();
        for(int j=0;j<tam;j++){
            if(buffer[j]=='('){
                count++;
                if(buffer[j+1]==')'){
                    if(count<=2) hr1 += '0';
                    else if(count>2 && count<=6) hr2 += '0';
                    else if(count>6 && count<=9) min1 += '0';
                    else if(count>9 && count<=13) min2 += '0';
                    else if(count>13 && count<=16) seg1 += '0';
                    else if(count>16 && count<=20) seg2 += '0';
                    j++;
                } else if(buffer[j+1]=='*') {
                    if(count<=2) hr1 += '1';
                    else if(count>2 && count<=6) hr2 += '1';
                    else if(count>6 && count<=9) min1 += '1';
                    else if(count>9 && count<=13) min2 += '1';
                    else if(count>13 && count<=16) seg1 += '1';
                    else if(count>16 && count<=20) seg2 += '1';
                    j +=2;
                }
            }
        }
        cout << "Case " << i << ": " << bin2dec(hr1) << bin2dec(hr2) << ":" << bin2dec(min1) << bin2dec(min2) << ":" << bin2dec(seg1) << bin2dec(seg2) << endl;
    }
    return 0;
}
