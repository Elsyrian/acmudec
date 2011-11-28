#include <stdio.h>
unsigned long long int fac(unsigned long long int a,unsigned long long int b,unsigned long long int c){
	if(a==b && c>3) return 1;
	else if(a==b) return 1;
	else if(a==0) return 0;
	else if(c>=2)	return((a*fac(a-1,b,c-1))/c);
	else return((a*fac(a-1,b,c-1))/1);
}


int main(){
unsigned long long int a,b;
while(1){
scanf("%lli %lli",&a,&b);
if(a==0 && b==0){break;}
if(a-b > b)
printf("%lli things taken %lli at a time is %lli exactly.\n",a,b,fac(a,a-b,b));
else printf("%lli things taken %lli at a time is %lli exactly.\n",a,b,fac(a,b,a-b));
}
return 0;
}
