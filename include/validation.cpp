#include <iostream>
#include <string>

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

int main()
{
    string data;
    cout << "Ingrese el valor a validar" << endl;

    cin >> data;

    if (isStringARealNumber(data))
    {
        cout << "Es Valido" << endl;
    }
    else
    {
        cout << "Es Invalido" << endl;
    }
    return 0;
}