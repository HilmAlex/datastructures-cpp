#include <iostream>

int round(double number){
    int numberRounded;

    number = number / 10;

    // Obtenemos el digito de la decena
    numberRounded = int(number);

    // Aumentamos en 1 el digito de la decena
    numberRounded = numberRounded +1;

    // Multiplicamos por 10 para obtener la decena superior
    numberRounded = numberRounded * 10;

    return numberRounded;
}
    
int main(){

    double number;

    std::cout << round(14) << std::endl;

    return 0;
}