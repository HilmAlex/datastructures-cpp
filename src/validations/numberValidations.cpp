#include <iostream>
#include <string>
#include <conio.h>

// No permita el ingreso de caracteres que no sean numeros
// Usar asccii para las restricciones
//	Funciones
//		1. Lea lo que ingresa el usuario y retorna lo que se ingreso
//		2. Que devuelva verdadero si es un numero o falso si no es

// Permita el ingreso de numeros reales
//	 Funciones
//		1. Que determine si un caracter es un punto (ASCII 46)

// Funcion que redondee
// Que ingrese hasta que el numero sea correcto
// Funciones

using namespace std;

// Retorna un valor booleano, verdadero si el caracter ingresado es un numero y falso si no lo es
bool isNumber(char character)
{
    int asciiValue = (int)character;

    bool aux = asciiValue >= 48 && asciiValue <= 57;

    return aux;
}

// Retorna un valor booleano, verdadero si el caracter ingresado es un punto y falso si no lo es
bool isAPoint(char character)
{
    int asciiValue = int(character);

    bool aux = asciiValue == 46;

    return aux;
}

// Retorna un valor booleano, verdadero si el string ingresado es un numero real y falso si no lo es
bool isRealNumber(string data)
{
    int leftPointer = 0;
    int rightPointer = data.length() - 1;

    while (leftPointer < data.length() - 1 || rightPointer > 0)
    {
        char currentLeftChar = data[leftPointer];
        char currentRightChar = data[rightPointer];

        // ANALISIS POR LA IZQUIERDA
        // Si no es numero y no es un punto, el puntero de la izquierda pasa a su ultimo valor posible
        if (!isNumber(currentLeftChar) && !isAPoint(currentLeftChar))
        {
            leftPointer = data.length() - 1;
        }

        if (isNumber(currentLeftChar))
        {
            leftPointer = leftPointer + 1;
        }

        // ANALISIS POR LA DERECHA
        if (!isNumber(currentRightChar) && !isAPoint(currentRightChar))
        {
            rightPointer = 0;
        }

        if (isNumber(currentRightChar))
        {
            rightPointer = rightPointer - 1;
        }

        if(isAPoint(currentLeftChar) && isAPoint(currentRightChar)){
            break;
        }
    }

    bool isInvalid = leftPointer != rightPointer || leftPointer == 0 || rightPointer == data.length() - 1;

    return !isInvalid;
}

void showMenu(){
    string menu;
    int option;

    menu = "Ingrese la operacion que desea realizar\n";
    menu += "1. Validar numero Entero\n";
    menu += "2. Validar numero Real\n";
    menu += "3. Redondear numero\n";
    menu += "4. Salir\n";

    option = 0;

    do{
        cout << menu << endl;
        
        cin >> option;
        
        string data;

        switch (option)
        {
        case 1:
            break;
        case 2:
            cout << "Ingrese el numero a validar" << endl;
            cin >> data;

            if(isRealNumber(data)){
                cout << "Numero Real Valido" << endl;
            } else{
                cout << "Numero Real Invalido" << endl;
            }
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
        }

    } while (option != 4);
}

int main()
{

    string data;

    showMenu();
    

    //cout << isRealNumber(data) << endl; 

    return 0;
}