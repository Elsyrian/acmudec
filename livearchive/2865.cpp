#include<iostream>

/*************************************************************************************************************************
 * 2865 - Bikers Trip Odometer
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=166&problem=866
 *
 * Classification: calculos de distancia y velocidad
 *
 * Author:
 *   Mauricio Echavarria  <mechavarria@udec.cl>
 *
 * Description:
 *
 * un odometro es un instrumento usado en rutas que sirve para medir distancia, velocidad, tiempo de viaje,
 * etc. se pide programar un odometro para ser instalado en una bicicleta, donde los datos de entrada son
 * el aro de la rueda en pulgadas, el numero de vueltas que dio la rueda durante el viaje y la duracion de
 * este en segundos. los datos de salida son la distancia recorrida en millas y la veolocidad promedio en
 * millas por hora, ambos datos aproximados en 2 decimales.
 *
 */


using namespace std;

int main(int argc,char *argv[]){
    float p=3.1415927;
    float diametro,vueltas,tiempo,radio,perimetro,distancia,velocidad;
    int counter=1;

    cout.precision(2);

    while(1){
        cin >> diametro;
        cin >> vueltas;
        cin >> tiempo;

        if(vueltas==0) return 0;

        radio = diametro/2;
        perimetro = 2*p*radio;
        distancia = perimetro * vueltas / 63360;
        velocidad = 3600 * distancia / tiempo;

        cout << "Trip #" << counter++ << ": " << fixed << distancia << " " << fixed << velocidad << endl;
    }

    return 0;
}
