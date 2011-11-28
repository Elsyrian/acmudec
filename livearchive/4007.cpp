/*************************************************************************************************************************
 * 4007 - Counting Squares
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=23&page=show_problem&problem=2008
 *
 * Classification: Computacional Geometry
 *
 * Author:
 *   Edgardo Moreno     <egyware@gmail.com>
 *   Stephano Beneventi <stephano.bg@gmail.com>
 *   Kristoffer Ulloa	<rewpoke@gmail.com>
 *
 * Description:
 *   En este problema se quiere encontrar la cantidad de cuadrados de 1x1 encerrados por un polígono en un espacio
 * discreto. Primero partimos del punto (0,0) luego vamos recorriendo punto a punto el poligono y guardamos todas las
 * líneas horizontales de largo 1. Supongamos punto1=(x1,y1) ; punto2=(x2,y2) ; tenemos que si y1=y2 tenemos una linea
 * horizontal (notar que la diferencia de x1,x2 no es mayor a uno), y guardamos la linea horizontal en la forma (k,y1)
 * con (k=min(x1,x2)) asi guardamos todas las lineas encontradas en un vector. Y calculamos la "integral" de forma
 * discreta para cada par de lineas.
 *
 */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class par{
	private:

	public:
		int x;
		int y;

		par(int a,int b){
			x=a;
			y=b;
		}

		void print();

};

bool compare(const par& a, const par& b) {
	if(a.x==b.x)return b.y < a.y;
	return a.x < b.x;
}

void par::print(){
	printf("[%d,%d]\n",this->x,this->y);
}

int main(){
	vector<par> lineas;
	string h;
	int px,py,ax,ay;
	int n,k;
	int i,j;
	int sum;
	int casos;
	getline(cin,h);
	casos=(h[0]-48);
	for(i=0;i<casos;i++){
		getline(cin,h);
		n=h.size();
		px=0;
		py=0;
		ax=0;
		ay=0;
		for(j=0;j<n;j++){
			if(h[j]=='U')py++;
			else if (h[j]=='D')py--;
			else if (h[j]=='L')px--;
			else if (h[j]=='R')px++;
			else {
				break;
			}
			if(ay==py)
                if(px<ax){
                    lineas.push_back(par(px,py));
                }
                else {
                    lineas.push_back(par(ax,py));
                }
            ax=px;
            ay=py;
        }

		sort(lineas.begin(),lineas.end(),compare);
		k=lineas.size();
		sum=0;
		for(j=0;j<k;j=j+2){
			sum=sum+(lineas[j].y-lineas[j+1].y);
		}
		printf("case %d: %d\n",i+1,sum);
		lineas.clear();
	}
}
