#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isCharacterANumber(char character)
{
    int asciiValue = (int)character;

    bool aux = asciiValue >= 48 && asciiValue <= 57;

    return aux;
}

bool isStringAPositiveInteger(string number)
{
    int lengthNumber;
    bool isANumber;

    lengthNumber = number.length();
    isANumber = false;

    if(lengthNumber == 0){
        return isANumber;
    }

    for (int i = 0; i < lengthNumber; i++)
    {
        if (!isCharacterANumber(number[i]))
        {
            return isANumber;
        }
    }

    isANumber = true;

    return isANumber;
}

bool isStringAInteger(string number)
{
    bool isANegativeNumber;
    char firstChar;

    firstChar = number[0];
    isANegativeNumber = (int)firstChar == 45;

    // isANegativeNumber == TRUE
    if (isANegativeNumber)
    {
        number = number.substr(1, number.length());
    }

    isANegativeNumber = isStringAPositiveInteger(number);

    return isANegativeNumber;
}

bool isStringARealNumber(string number)
{
    bool isADecimalNumber;
    string firstSubstring;
    string secondSubstring;

    isADecimalNumber = false;
    firstSubstring = "";

    for (int i = 0; i < number.length(); i++)
    {
        // Valor del punto en codigo ASII = 46
        int currentAsciiValue;

        if ((int)number[i] == 46 && i != 0 && i != number.length() - 1)
        {
            firstSubstring = number.substr(0, i);
            secondSubstring = number.substr(i + 1, number.length());
        }
    }

    if (firstSubstring.length() != 0)
    {
        if (!isStringAInteger(firstSubstring))
        {
            return isADecimalNumber;
        }

        if (!isStringAPositiveInteger(secondSubstring))
        {
            return isADecimalNumber;
        }
    }

    if (firstSubstring.length() == 0)
    {
        if (!isStringAInteger(number))
        {
            return isADecimalNumber;
        }
    }

    isADecimalNumber = true;

    return isADecimalNumber;
}










void displayOptions()
{
    string options;

    options = "Ingrese la operacion que desea realizar\n";
    options += "1. Validar numero Entero\n";
    options += "2. Validar numero Real\n";
    options += "3. Redondear numero\n";
    options += "4. Salir\n";

    cout << options << endl;
}

void validateInteger(){
    string input;
    string output;
    bool isInteger;

    cout << "Ingrese el numero a validar: " ;
    cin >> input;

    isInteger = isStringAInteger(input);
    output = isInteger ? "Es un numero valido" : "Es un numero invalido";
    
    cout << output << "\n\n";
}

void validateRealNumber(){
    string input;
    string output;
    bool isInteger;

    cout << "Ingrese el numero a validar: " ;
    cin >> input;

    isInteger = isStringARealNumber(input);
    output = isInteger ? "Es un numero valido" : "Es un numero invalido";
    
    cout << output << "\n\n";
}

void roundNumber(){
    string input;
    string output;
    bool isValid;
    
    cout << "Ingrese el numero a redondear: " ;
    cin >> input;

    isValid = isStringARealNumber(input);
    
    if(isValid){
        int roundedNumber;
        float stringToFloat;

        stringToFloat = atof(input.c_str());
        roundedNumber = round(stringToFloat);
        cout << "El numero redondeado es: " << roundedNumber << endl << endl;
    }

    if(!isValid){
        cout << "Ingrese un numero valido!!!" << "\n\n";
    }

}

void showMenu()
{
    string header;
    string input;
    char option;

    header = "PROGRAMA QUE VERIFICA SI UN NUMERO ES ENTERO O REAL Y REDONDEA UN NUMERO DADO";

    do
    {
        displayOptions();
        cin >> input;

        option = '0';

        if(input.length() == 1){
            option = input[0];
        } 
        
        switch (option)
        {
        case '1':
                validateInteger();
            break;
        case '2':
                validateRealNumber();
            break;
        case '3':
                roundNumber();
            break;
        case '4':
            break;
        default:
            cout << "ERROR: Ingrese una opción válida\n\n";
            break;
        }

    } while (option != '4');
}


int main()
{

    showMenu();

    return 0;
}