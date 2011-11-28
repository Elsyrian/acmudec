/*
2540 - The Hardest Problem Ever
http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=541

Classification: String Processing

Author:
   Ricardo Vásquez <ricardovasquez@udec.cl>
   
Description:
   Julio Cesar enviaba mensajes codificados a sus generales, el objetivo es decifrar que es lo que el Cesar quería decir.
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    
    char frase[210];
    string a;
    int i,l;
    
    while(1){
    
       cin>>a;
       
       if(a=="ENDOFINPUT")break;
       
       scanf(" %[^\n]",frase);
       
       l=strlen(frase);
       for(i=0;i<l;i++){
          if(frase[i]>='F'&& frase[i]<='Z')printf("%c",frase[i]-5);
          else if(frase[i]>='A' && frase[i]<='E')printf("%c",frase[i]+21);
          else printf("%c",frase[i]);
       }
       printf("\n");
       cin>>a;
    }
    return 0;
}
