#include <iostream>
#include <string>

using namespace std;

void displayOptions()
{
    string menu;

    menu = "Ingrese la operacion que desea realizar\n";
    menu += "1. Validar numero Entero\n";
    menu += "2. Validar numero Real\n";
    menu += "3. Redondear numero\n";
    menu += "4. Salir\n";

    cout << menu << endl;
}

void validateNaturalNumber(){

}

void validateInteger(){

}

void validateRealNumber(){

}

void roundNumber(){

}

int main()
{
    string input;
    char option;

    option = '0';
    input = "";
    do{
        displayOptions();
        cin >> option;

        switch (option)
        {
        case '1':
            validateNaturalNumber();
            break;
        case '2':
            validateInteger();
            break;
        case '3':
            validateRealNumber();
            break;
        case '4':
            break;
        default:
            cerr << "ERROR: Ingrese un opcion valida" << "\n\n";
            break;
        }
    } while (option != '4');
    
    return 0;
}