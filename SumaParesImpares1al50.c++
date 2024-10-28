//4.Se desea calcular independientemente la suma de los números pares e impares comprendidos entre 1 y 50.//
#include<iostream>
using namespace std;
int main(){
    int i, sumaPares=0, sumaImpares=0;
    for(i=1;i<=50;i++){
        if(i%2==0){
            sumaPares=sumaPares+i;
            }
            else{
                sumaImpares=sumaImpares+i;
                }
                }
                cout<<"La suma de los numeros pares es: "<<sumaPares<<endl;
                cout<<"La suma de los numeros impares es: "<<sumaImpares<<endl;
    return 0;
}