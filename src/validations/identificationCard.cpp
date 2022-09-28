#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool checkLength(string data, int length)
{
    bool isLengthEquals;

    isLengthEquals = data.length() == length ? true : false;

    return isLengthEquals;
}

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

    if (lengthNumber == 0)
    {
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

bool isPair(int number)
{
    bool isNumberPair;

    isNumberPair = number % 2 == 0 ? true : false;

    return isNumberPair;
}

int getTopTen(double number)
{

    int numberRounded;

    number = number / 10;
    numberRounded = int(number);
    numberRounded = numberRounded + 1;
    numberRounded = numberRounded * 10;

    return numberRounded;
}

int addPairs(string number)
{
    int i;
    int counter = 0;
    for (i = 0; i <= 8; i++)
    {
        char currentNumber = number[i];

        int integer = currentNumber - '0';

        if (i % 2 == 0)
        {
            counter += integer * 2;

            counter -= integer * 2 >= 10 ? 9 : 0;
        }
        else
        {
            counter += integer;
        }
    }

    return counter;
}

bool compareLastDigit(int counter, int lastDigit)
{
    bool isEqual = false;
    int result = getTopTen(counter) - counter;

    if (result == lastDigit || (result == 10 && lastDigit == 0))
    {
        return true;
    }

    return isEqual;
}

int getLastDigit(string number)
{
    int lastDigit;
    int lastPosition;

    lastPosition = number.length() - 1;
    lastDigit = int(number[lastPosition]) - '0';

    return lastDigit;
}

bool isIdentificationCardValid(string number)
{
    int sumNumbers;
    int lastDigit;
    bool lastDigitValid;

    sumNumbers = addPairs(number);
    lastDigit = getLastDigit(number);
    lastDigitValid = compareLastDigit(sumNumbers, lastDigit);

    if (lastDigitValid)
    {
        return true;
    }

    return false;
}

void printIDInvalid()
{
    cout << "La cédula ingresada es inválida" << endl;
}

void printIDValid()
{
    cout << "La cédula ingresada es válida" << endl;
}


void show()
{
    string number;
    bool isIDValid;

    cout << "Ingrese su cedula:\n";

    cin >> number;

    if (!checkLength(number, 10) || !isStringAPositiveInteger(number))
    {
        printIDInvalid();
        return;
    }

    isIDValid = isIdentificationCardValid(number);

    if (isIDValid)
    {
        printIDValid();
        return;
    }

    printIDInvalid();
}

int main()
{
    show();
    return 0;
}