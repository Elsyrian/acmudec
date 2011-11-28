/*
4065 - Rock, Paper, or Scissors?
http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=2066

Classification: Ad hoc (?)

Author:
       Ricardo Vásquez <ricardovasquez@udec.cl>

Description:
       Dos personas juegan al "piedra, papel o tijeras", dada una serie de juegos, 
       hay que determinar el ganador o el empate si se da el caso.
*/

#include <stdio.h>

int main(){
    
    int t;
    int v;
    char p1,p2;
    int s1,s2;
    
    scanf("%d",&t);
    while(t){
             
       scanf("%d",&v);
       
       s1=0;
       s2=0;
       
       while(v){
       
          scanf(" %c %c",&p1,&p2);
          
          if(p1==p2){
             v--;
             continue;
          }
          else if(p1=='R'&&p2=='P')s2++;
          else if(p1=='R'&&p2=='S')s1++;
          else if(p1=='P'&&p2=='R')s1++;
          else if(p1=='P'&&p2=='S')s2++;
          else if(p1=='S'&&p2=='P')s1++;
          else if(p1=='S'&&p2=='R')s2++;
          
       
       v--;
       }
       
       if(s1>s2)printf("Player 1\n");
       else if(s2>s1)printf("Player 2\n");
       else printf("TIE\n");
    
    t--;         
    }
    
    return 0;
}
