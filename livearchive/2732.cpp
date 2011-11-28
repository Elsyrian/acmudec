/****************************************************************************
 * 2732 - CD Titles
 * http://acmicpc-live-archive.uva.es/nuevoportal/data/problem.php?p=2732
 *
 * Se pedia un programa que dado varios titulos, los imprimiera en forma vertical
 * para de esta forma ponerle nombre a los CD.
 *
 *                                                      -- Francisco Serrano
 *
 */

#include <iostream>
#include <string>
using namespace std;

string nombres[51];
int tam[51];
int i=0,j,k;
int largo=0;

int main(int argc, char** argv) {
    while(true){
        getline(cin,nombres[i]);
        tam[i]=nombres[i].size();
        if(tam[i]>largo){
            largo=tam[i];
        }
         if(nombres[i]=="#"){
            break;
        }
        i++;
    }
    if(largo>=36)largo=36;
    for(j=0;j<((i*2)+1);j++){
        cout << "-";
    }
    cout << endl;
    for(k=0;k<largo;k++){
        for(j=0;j<i;j++){

            if(tam[j]<=k){
                cout << "| ";
            }
            else cout << "|" << nombres[j].at(k);
        }
        cout << "|"<< endl;
    }
    for(j=0;j<((i*2)+1);j++){
        cout << "-";
    }
    cout << endl;
  return 0;
 }
