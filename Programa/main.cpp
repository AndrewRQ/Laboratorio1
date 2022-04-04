#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Funcion que calcula la tension generada en un cuerda cuando tiene 1 objeto en cada extremo
float ejercicio1(float masa1, float masa2) {
    const float g = 9.8; // Valor de G
    return ((2 * masa1 * masa2) / (masa1 + masa2)) * g;
}

//Funcion que calcula e impreme en pantalla el redimiento de un automovil en mi/gal y en l/100km
void ejercicio2(float millasRecorridas, float galonesConsumidos) {
    float rendimiento = millasRecorridas / galonesConsumidos;
    float conversion = 235.215 / rendimiento; // Pasa el redimiento de mi/gal a l/100km
    printf("La eficiencia del carro es: %.1f mi/gal (equivalente a %.2fl /100km).", rendimiento, conversion);
}

//Funcion que recibe una altura en pies y pulgadas y imprime en pantalla la altura en a metros
void ejercicio3(int pies, int pulgadas) {
    float metros = (pies * 0.3048) + (pulgadas * 0.0254); // Pasa la altura de pies y pulgadas a metros
    printf("Altura: %d pies %d pulgadas.\nLa altura de la persona es: %.2f m", pies, pulgadas, metros);
}

//Recibe un monto de dinero en libras, chelines y peniques, los pasa al nuevo sistema monetario y lo imprime en pantalla
void ejercicio4(int libras, int chelines, int peniques) {
    float valor = libras + (float(peniques) / 100); // Se realiza la conversion
    printf("libras: %d\nchelines: %d\npeniques: %d\nEl valor en el sistema actual es: %f gbp", libras, chelines, peniques, valor);
}

//Funcion que recibe dos numeros enteros y retorna un numero aleatorio en ese rango
int valor_aleatorio(int min, int max){
    int retorno;
    srand(time(NULL));
    retorno = min+rand()%(max+1-min);
    return retorno;
}

//Funcion que imprime en orden la cantidad de numeros primos que recibe como parametro
void determinar_primo(int num){
    cout << "Numero \t\t Primo" <<endl; //Encabezado
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
    int minimo,maximo,numeros_primos, pies, pulgadas, libras, chelines, peniques;
    float masa1, masa2, millas, galones;
    cout << "Ejercicio 1 " << endl;
    cout << "Digite la masa del primer objeto: ";
    cin >> masa1;
    cout << "Digite la masa del segundo objeto: ";
    cin >> masa2;
    cout << "La tension es igual a " << ejercicio1(masa1, masa2) << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Ejercicio 2 " << endl;
    cout << "Digite la cantidad de millas recorridas: ";
    cin >> millas;
    cout << "Digite los galones de combustible consumidos: ";
    cin >> galones;
    ejercicio2(millas, galones);
    cout << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Ejercicio 3 " << endl;
    cout << "Digite la cantidad de pies: ";
    cin >> pies;
    cout << "Digite la cantidad de pulgadas: ";
    cin >> pulgadas;
    ejercicio3(pies, pulgadas);
    cout << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Ejercicio 4 " << endl;
    cout << "Digite la cantidad de libras: ";
    cin >> libras;
    cout << "Digite la cantidad de chelines: ";
    cin >> chelines;
    cout << "Digite la cantidad de peniques: ";
    cin >> peniques;
    ejercicio4(libras, chelines, peniques);
    cout << endl;
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
