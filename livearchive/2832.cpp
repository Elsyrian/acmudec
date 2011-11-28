#include<iostream>
using namespace std;

/*************************************************************************************************************************
 * 2832 - A Contesting Decision
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=833
 *
 * Classification: analisis de datos
 *
 * Author:
 *   Mauricio Echavarria  <mechavarria@udec.cl>
 *
 * Description:
 *
 * la idea es programar un sistema que determine cual es el equipo ganador de una competencia acm en base a
 * los datos de entrada, los cuales son el nombre del equipo, la cantidad de intentos por problema y el
 * tiempo en el que fue resuelto (0 si no fue resuelto)
 * se asume una competencia de solo 4 problemas
 *
 * comentario: en la descripcion del problema no salia especificado el largo del nombre del equipo, por lo
 * que le puse al ojo un espacio de 200 caracteres y fue aceptado
 */


typedef struct{
    char nombre[200];
    int envios[4];
    int tiempo[4];
    int problemas;
    int tiempo_total;
}team;

int main(int argc,char *argv[]){
    int n_equipos;
    int ganador;
    int mejor_tiempo=0;
    int mejor_problemas=0;

    //leer cantidad de equipos
    cin >> n_equipos;
    team equipos[n_equipos];

    //guardar equipos
    for(int i=0;i<n_equipos;i++){
        cin >> equipos[i].nombre;
        equipos[i].tiempo_total=0;
        equipos[i].problemas=0;
        for(int j=0;j<4;j++){
            cin >> equipos[i].envios[j];
            cin >> equipos[i].tiempo[j];
            if (equipos[i].tiempo[j]==0) continue;
            else{
                equipos[i].tiempo_total+=equipos[i].tiempo[j] + 20*(equipos[i].envios[j] - 1);
                equipos[i].problemas++;
            }
        }
        if(equipos[i].problemas>mejor_problemas) mejor_problemas++;
    }

    //encontrar al ganador
    for (int i=0;i<n_equipos;i++){
        if(equipos[i].problemas!=mejor_problemas) continue;
        else{
            if(mejor_tiempo==0){
                mejor_tiempo=equipos[i].tiempo_total;
                ganador=i;
            }
            else{
                if(equipos[i].tiempo_total<mejor_tiempo){
                    mejor_tiempo=equipos[i].tiempo_total;
                    ganador=i;
                }
            }
        }

    }

    //imprimir el equipo ganador
    cout << equipos[ganador].nombre << " " << equipos[ganador].problemas << " " << equipos[ganador].tiempo_total << endl;

    return 0;
}
