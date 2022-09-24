#include <iostream>
using namespace std;


int main()
{
    string data1 = "19/09/2022";
    string day = data1.substr(0, 2);
    string month = data1.substr(3, 2);
    string year = data1.substr(6,4);
    cout << "Day: " << day << endl;
    cout << "Month: " << month << endl;
    cout << "Year:  " << year << endl;

    // string data1 = "15.36";
    // string integer = data1.substr(0, 2);
    // string point = data1.substr(2, 1);
    // string decimal = data1.substr(4);
    // cout << "Entero " << integer << endl;
    // cout << "Punto " << point << endl;
    // cout << "Decimal " << decimal << endl;
}