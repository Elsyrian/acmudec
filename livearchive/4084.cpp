/****************************************************************************
 * 4084 - Judging Olympia
 *http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=2085
 *
 * Author: Rafael Sepúlveda
 *
 */


#include <iostream>


using namespace std;

int main(int argc, char **argv){
	float grades[6];
	for(int i=0; i<6;i++){
		cin>>grades[i];
	}

	while(1){
		if(grades[0]==0 && grades[1]==0 && grades[2]==0 && grades[3]==0 && grades[4]==0 && grades[5]==0) break;
		float mayor=grades[0];
		float menor=grades[0];

		for(int i=0;i<6;i++){
			if(grades[i]>=mayor)mayor=grades[i];

			if(grades[i]<=menor)menor=grades[i];
		}


		for(int i=0;i<6;i++){
			if(grades[i]==mayor){
				grades[i]=0;
				break;
			}
		}
		for(int i=0;i<6;i++){
			if(grades[i]==menor){
				grades[i]=0;
				break;
			}
		}
		float prom=0;
		for(int i=0;i<6;i++){
			prom=prom+grades[i];
		}
		prom=prom/4;
		cout << prom << endl;

		for(int i=0; i<6;i++){
			cin>>grades[i];
		}
 	}



	return 0;

}
