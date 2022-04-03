#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Funcion que recibe dos numeros enteros y retorna un numero aleatorio en ese rango
int valor_aleatorio(int min, int max){
    int retorno;
    srand(time(NULL));
    retorno = min+rand()%(max+1-min);
    return retorno;
}

//Funcion que imprime en orden la cantidad de numeros primos que recibe como parametro
void determinar_primo(int num){
    cout << "Numero \t Primo" <<endl; //Encabezado
    int ultimo_primo = 2, divisores; //Ultimo primo permite tener un registro para no tener que empezar de 0
    bool es_primo;
    for(int i = 1; i <= num; i++) { //Ciclo principal que permite imprimir la cantidad solicitada de numeros primos
        es_primo = false; //Valor por default para entrar al siguiente ciclo
        cout << i << "\t\t";
        while(!es_primo){ //Ciclo que se repite mientras no se encuentre un numero primo
            if(ultimo_primo%2!=0 || ultimo_primo == 2){ //Determina si el numero que se esta evaluando no sea par, ya que solo 2 es par y primo
                divisores = 1; //Valor por default ya que se asume que un numero siempre es divisible por si mismo
                int j = ultimo_primo/2; //Se asume que ningun numero es divisible por numeros mayores a su mitad
                do{
                    if(ultimo_primo%j == 0)//Condicional que determina si j es un divisor del posible primo
                        divisores++;
                    j--;
                }while(j > 0 && divisores <= 2);
                if(divisores <= 2){ //Solo deberia ser divisible entre 1 y el mismo
                    es_primo = true;
                    cout << ultimo_primo << endl;
                }
            }
            ultimo_primo++;
        }
    }
}

//Funcion principal
int main() {
    int minimo,maximo,numeros_primos;
    cout << "-----------------------------------------" << endl;
    cout << "Ejercicio 5 " << endl;
    cout << "Digite el minimo: ";
    cin >> minimo;
    cout << "Digite el maximo: ";
    cin >> maximo;
    cout << "Valor Aleatorio entre los numeros dados: "<< valor_aleatorio(minimo,maximo) <<endl;
    cout << "-----------------------------------------" << endl;
    cout << "Ejercicio 6 " << endl;
    cout << "Digite cantidad de numeros primos a mostrar: ";
    cin >> numeros_primos;
    determinar_primo(numeros_primos);
    return 0;


}
