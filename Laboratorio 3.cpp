#include <iostream> 
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>
using namespace std; 

void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

double calcularPotencia(double base, int exponente);

int main() {
    int opc;
    srand(time(NULL));

    do {
        gotoxy(35, 1);
        cout << "MENU" << endl;
        cout << "1- Calculadora." << endl;
        cout << "2- Calcular Potencia" << endl;
        cout << "3- Determinar si un numero es primo o no." << endl;
        cout << "4- Anio Bisiesto" << endl;
        cout << "5- Salir del menu." << endl;
        cout << "Opcion: ";
        cin >> opc;

        switch (opc) {
            case 1: {
                // Código para la calculadora
                system("cls");
                float num1, num2, resultado;
                char operacion;

                cout << "Ingrese el primer numero: ";
                cin >> num1;

                cout << "Ingrese el segundo numero: ";
                cin >> num2;

                cout << "Seleccione la operacion (+, -, *, /): ";
                cin >> operacion;

                switch (operacion) {
                    case '+':
                        resultado = num1 + num2;
                        break;
                    case '-':
                        resultado = num1 - num2;
                        break;
                    case '*':
                        resultado = num1 * num2;
                        break;
                    case '/':
                        if (num2 != 0) {
                            resultado = num1 / num2;
                        } else {
                            cout << "No se puede dividir por cero." << endl;
                            return 1;
                        }
                        break;
                    default:
                        cout << "Operacion no valida." << endl;
                        return 1;
                }

                cout << "El resultado es: " << resultado << endl;
                system("pause");
                cout << endl;
                break;
            }
            case 2: {
                //Código para calcular una potencia
                system("cls");

                float base;
                int exponente;

                cout << "Ingrese la base: ";
                cin >> base;

                cout << "Ingrese el exponente: ";
                cin >> exponente;

                double resultado = calcularPotencia(base, exponente);

                cout << "Resultado: " << resultado << endl;
                system("pause");
                cout << endl;
                break;
            }
            case 3: {
                // Código para determinar si un número es primo o no
                system("cls");
                cout << "\t\t\tIdentificador de numeros primos" << endl;
                int numero;
                cout << "Ingrese un numero para saber si es primo o no" << endl;
                cin >> numero;
                if (numero <= 1) {
                    cout << "El numero no es primo" << endl;
                } else {
                    float limite = sqrt(numero);
                    bool esPrimo = true;

                    for (int divisor = 2; divisor <= limite; divisor++) {
                        if (numero % divisor == 0) {
                            esPrimo = false;
                            break;
                        }
                    }
                    if (esPrimo) {
                        cout << " El numero es primo" << endl;
                    } else {
                        cout << "El numero no es primo" << endl;
                    }
                    system("pause");
                    cout << endl;
                    break;
                }
            }
            case 4: {
                // Código para determinar si un año es bisiesto o no
                system("cls");

                int anio;
                cout << "Ingrese un anio: ";
                cin >> anio;

                if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
                    cout << anio << " es un anio bisiesto." << endl;
                } else {
                    cout << anio << " no es un anio bisiesto." << endl;
                }
                system("pause");
                cout << endl;
                break;
            }
        }

        system("cls");

    } while (opc != 5);

    cout << "Fuera del programa";

    return 0;
}


double calcularPotencia(double base, int exponente) {
    if (exponente == 0) {
        return 1.0;
    } else if (exponente < 0) {
        return 1.0 / pow(base, -exponente);
    } else {
        return pow(base, exponente);
    }
}

