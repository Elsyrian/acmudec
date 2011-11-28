/*************************************************************
* 3154 - Magic Trick
* http://acmicpc-live-archive.uva.es/nuevoportal/data/problem.php?p=3154 
*
* Para resolver este problema cree 3 funciones. Para transformar los caracteres a numeros y los numeros a caracteres y para dar un valor a las pintas(suits) de las cartas. Luego comparé sumé numeros con sus pintas y comparé
*
*                     --Gabriela Lártiga
*/
#include <stdio.h>

int f_numerito(char letrita){
int numerin;
if(letrita=='1'){numerin=1;}
if(letrita=='2'){numerin=2;}
if(letrita=='3'){numerin=3;}
if(letrita=='4'){numerin=4;}
if(letrita=='5'){numerin=5;}
if(letrita=='6'){numerin=6;}
if(letrita=='7'){numerin=7;}
if(letrita=='8'){numerin=8;}
if(letrita=='9'){numerin=9;}
if(letrita=='T'){numerin=10;}
if(letrita=='J'){numerin=11;}
if(letrita=='Q'){numerin=12;}
if(letrita=='K'){numerin=13;}
return numerin;
}

int f_cartita(char letrita){
int numerin;
if(letrita=='H'){numerin=1;}
if(letrita=='C'){numerin=100;}
if(letrita=='D'){numerin=100000;}
if(letrita=='S'){numerin=100000000;}
return numerin;
}

char f_letrita(int numerito){
int letrita;
if(numerito==1){letrita='1';}
if(numerito==2){letrita='2';}
if(numerito==3){letrita='3';}
if(numerito==4){letrita='4';}
if(numerito==5){letrita='5';}
if(numerito==6){letrita='6';}
if(numerito==7){letrita='7';}
if(numerito==8){letrita='8';}
if(numerito==9){letrita='9';}
if(numerito==10){letrita='T';}
if(numerito==11){letrita='J';}
if(numerito==12){letrita='Q';}
if(numerito==0){letrita='K';}
return letrita;
}


int main(){
int i;
int test_cases;
int therealvalue;
char cardvalue;
char cases[12];
int suit[4];
int numby[4];
scanf("%d\n", &test_cases);
while(test_cases>0){

for(i=0;i<12;i++){
scanf("%c",&cases[i]);
}

numby[0]=f_numerito(cases[0]);
numby[1]=f_numerito(cases[3]);
numby[2]=f_numerito(cases[6]);
numby[3]=f_numerito(cases[9]);


suit[1]=f_cartita(cases[4]);
suit[2]=f_cartita(cases[7]);
suit[3]=f_cartita(cases[10]);

therealvalue=numby[0];

numby[1]=numby[1]+suit[1];
numby[2]=numby[2]+suit[2];
numby[3]=numby[3]+suit[3];
 
if(numby[1]<numby[2] && numby[2]<numby[3] && numby[1]<numby[3]){therealvalue=therealvalue+1;}
if(numby[1]<numby[2] && numby[2]>numby[3] && numby[1]<numby[3]){therealvalue=therealvalue+2;}
if(numby[1]>numby[2] && numby[2]<numby[3] && numby[1]<numby[3]){therealvalue=therealvalue+3;}
if(numby[1]<numby[2] && numby[2]>numby[3] && numby[1]>numby[3]){therealvalue=therealvalue+4;}
if(numby[1]>numby[2] && numby[2]<numby[3] && numby[1]>numby[3]){therealvalue=therealvalue+5;}
if(numby[1]>numby[2] && numby[2]>numby[3] && numby[1]>numby[3]){therealvalue=therealvalue+6;}

therealvalue=therealvalue%13;
cardvalue=f_letrita(therealvalue);
printf("%c%c\n", cardvalue, cases[1]);
test_cases--;
}
return 0;
}


