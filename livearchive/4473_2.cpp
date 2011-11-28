/****************************************************************************
 * 4473 - Brothers
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=99999999&category=365&page=show_problem&problem=2474
 * Este problema era el B de la ACM 2009 que participe con mi equipo.
 * La verdad es que me traia buenos recuerdos, ya que yo lo programe
 * en dicha ocasion. Ahora quise probar si se facilitaba algo más con C++,
 * pero lo unico que mejore fue como se utilizaron los ciclos (creo, ya que no
 * tengo el archivo de dicha ocasion).
 * Lo subo igual, ya que lo programe en C++ a diferencia de javier y sale en menos lineas.
 *                                                      -- Francisco Serrano
 *
 */

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
  int inicial[100][100];
  int final[100][100];
  int n,r,c,k,i,j,f;

  while(true){
    cin >> n;
    cin >> r;
    cin >> c;
    cin >> k;
    if(n==0 && r==0 && c==0 && k==0)return 0;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin >> inicial[i][j];
            final[i][j]=inicial[i][j];
        }
    }
    for(f=0;f<k;f++){
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if(inicial[i][j]==n-1){
                    if(inicial[i-1][j]==0 && i>0) final[i-1][j]=inicial[i][j];
                    if(inicial[i+1][j]==0 && i+1<r) final[i+1][j]=inicial[i][j];
                    if(inicial[i][j-1]==0 && j>0) final[i][j-1]=inicial[i][j];
                    if(inicial[i][j+1]==0 && j+1<c) final[i][j+1]=inicial[i][j];
                }
                if(inicial[i][j]!=n-1){
                    if(inicial[i-1][j]-1==inicial[i][j] && i>0) final[i-1][j]=inicial[i][j];
                    if(inicial[i+1][j]-1==inicial[i][j] && i+1<r) final[i+1][j]=inicial[i][j];
                    if(inicial[i][j-1]-1==inicial[i][j] && j>0) final[i][j-1]=inicial[i][j];
                    if(inicial[i][j+1]-1==inicial[i][j] && j+1<c) final[i][j+1]=inicial[i][j];
                }
            }
        }
        for(i=0;i<r;i++){
            for(j=0;j<c;j++)inicial[i][j]=final[i][j];
        }
    }
    for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                cout << inicial[i][j];
                if(j+1<c)cout << " ";
            }
            cout << endl;
    }
  }
  return 0;
 }
