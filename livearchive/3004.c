/**************************************************************************************************************************
 * 3004 - Change
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=207&page=show_problem&problem=1005
 *
 * Authors:
 *   Cathy Espinoza <nikkita126@gmail.com>
 *   Javier Rodríguez
 *   Ricardo Vásquez
 *
 * Description:
 *   Se pide proporcionar detalladamente, si es posible, el vuelto que debería darse al gastar 
 * cierta cantidad de dinero y pagar con otra cantidad determinada, estando ambos valores
 * redondeados según el "método Sueco". Un factor a considerar es no leer las cantidades como float,
 * ya que crea problemas de aproximación.
 *
 *                                                      -- Cathy Espinoza
 */

#include <stdio.h>

int main(){
  
  int i;
  int costo1,costo2,pago1,pago2;
  int costo,pago;
  int precios[10]={2000,1000,500,200,100,50,20,10,5,0};
  int cant[10];
  int prenex;
  
  while(1){
    
    scanf("%d.%d %d.%d",&costo1,&costo2,&pago1,&pago2);
    
    costo = costo1*100 + costo2;
    pago = pago1*100 + pago2;
    
    if(costo==0 && pago==0)break;
    
    if(costo%10==1)costo=costo-1;
    else if(costo%10==2)costo=costo-2;
    else if(costo%10==3)costo=costo+2;
    else if(costo%10==4)costo=costo+1;
    else if(costo%10==6)costo=costo-1;
    else if(costo%10==7)costo=costo-2;
    else if(costo%10==8)costo=costo+2;
    else if(costo%10==9)costo=costo+1;
    
    if(pago%10==1)pago=pago-1;
    else if(pago%10==2)pago=pago-2;
    else if(pago%10==3)pago=pago+2;
    else if(pago%10==4)pago=pago+1;
    else if(pago%10==6)pago=pago-1;
    else if(pago%10==7)pago=pago-2;
    else if(pago%10==8)pago=pago+2;
    else if(pago%10==9)pago=pago+1;
    
    if(pago<costo)printf("Not enough money offered.");
    else if(pago==costo){
      printf("Exact amount.");
    }
    
    else{
      pago=pago-costo;
      
      for(i=0;i<9;i++){
        cant[i]=0;
        while(pago-precios[i]>=0){
          cant[i]++;
          pago=pago-precios[i];
        }
      }
      
      prenex=1;
      
      for(i=0;prenex!=0;i++){
        if(i<5){
          if(cant[i]){
            printf("$%d*%d",precios[i]/100,cant[i]);
            prenex=0;
          }
        }
        else{
          if(cant[i]){
            printf("%dc*%d",precios[i],cant[i]);
            prenex=0;
          }
        }
      }

      for(;i<9;i++){
	
        if(i<5){
          if(cant[i])
            printf(" $%d*%d",precios[i]/100,cant[i]);
        }
        else{
          if(cant[i])
            printf(" %dc*%d",precios[i],cant[i]);
        }
      }
    }
    printf("\n");
  }
  return 0;
}
