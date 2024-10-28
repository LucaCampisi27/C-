#include<iostream>
using namespace std;
int main (){
int segundos , minutos ,horas , ST;

cout <<"digite los segundos:";
cin >> segundos;
cout <<"digite los minutos:";
cin >> minutos;
cout <<"digite las horas:";
cin >> horas;
minutos =  60 * minutos;
horas =  3600 * horas;
ST = minutos + horas + segundos;
cout<<"los segundos totales son:"<<ST;
    return 0;
}