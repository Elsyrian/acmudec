/*************************************************************************************************************************
 * 2017 - Hey, You're Not Marion Jones!
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=18
 *
 * Classification: Mathematics, String Processing
 *
 * Author:
 *   Stephano Beneventi <stephano.bg@gmail.com>
 *
 * Description:
 *   El problema en si no es dificil, solo hay que seguir bien las indicaciones. Lo que si puede implicar una difcultad,
 * es que el operador % no funciona igual que la operacion mod, por lo que se implemento manualmente la funcion.
 *
 */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

int mod5(int a){
	if(a==0 || a%5==0)return 0;
	if(a>0)return a%5;
	if(a<0)return a%5+5;
}

int G(int j){
	if(j==0)return 1;
	if(j==1)return 5;
	if(j==2)return 7;
	if(j==3)return 6;
	if(j==4)return 2;
	if(j==5)return 8;
	if(j==6)return 3;
	if(j==7)return 0;
	if(j==8)return 9;
	if(j==9)return 4;
}

int F(int i, int j){
	if(i==0)return j;
	if(i==1)return G(j);
	return F(i-1,G(j));
}

int ixj(int i, int j){
	if(i<5 && j<5)return mod5((i+j));
	if(i<5 && j>=5)return mod5((i+(j-5)))+5;
	if(i>=5 && j<5)return mod5(((i-5)-j))+5;
	if(i>=5 && j>=5)return mod5((i-j));
}

bool check(char * ID){
	int ans = ixj(ixj(ixj(ixj(ixj(ixj(ixj(F(0,ID[7]-48),F(1,ID[6]-48)),F(2,ID[5]-48)),F(3,ID[4]-48)),F(4,ID[3]-48)),F(5,ID[2]-48)),F(6,ID[1]-48)),F(7,ID[0]-48));
	if(ans==0)return true;
	else return false;
}

int number5(char c){
	if(c=='Z')return 0;
	if(c=='Y')return 1;
	if(c=='X')return 2;
	if(c=='W')return 3;
	if(c=='V')return 4;
}


main(){

	int casos,n,i,j,k;
	int num;

	string linea,base5;
	char ID[9];

	scanf("%d\n",&casos);

	for(i=0;i<casos;i++){

		for(j=0;j<8;j++){
			ID[j]='0';
		}
		ID[8]='\0';

		getline(cin,linea);

		n=linea.size();

		num=0;
		for (j=n-1,k=0;j>=0;j--,k++){
			num=num+number5(linea[j])*pow(5,k);
		}

		if(num>99999999){
			cout << linea << "/" << num << " is invalid id number" << endl;
		}
		else{

			j=7;
			while(num!=0){
				ID[j]=num%10+48;
				num=num/10;
				j--;
			}

			if(check(ID)){
				if     (ID[0]=='0' || ID[0]=='1')cout << linea << "/" << ID << " is valid athlete id number" << endl;
				else if(ID[0]=='2' || ID[0]=='3')cout << linea << "/" << ID << " is valid reserve id number" << endl;
				else if(ID[0]=='4' || ID[0]=='5')cout << linea << "/" << ID << " is valid judge id number" << endl;
				else if(ID[0]=='6' || ID[0]=='7')cout << linea << "/" << ID << " is valid staff id number" << endl;
				else if(ID[0]=='8' || ID[0]=='9')cout << linea << "/" << ID << " is valid press id number" << endl;
			}
			else {
				cout << linea << "/" << ID << " is invalid id number" << endl;
			}

		}

	}

}
