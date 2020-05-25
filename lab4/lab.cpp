#include <iostream>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <Windows.h>

using namespace std;
void pause();
void divisible();
void parImpar();
void positivoNegativoCero();
void caracteres();
void inicioFinal();
/*
    COLORES
    
    0 = Negro
    1 = Azul
    2 = Verde
    3 = Aguamarina
    4 = Rojo
    5 = Purpura
    6 = Amarillo
    7 = Blanco
    8 = Gris
    9 = Azul claro
*/
int main()
{

    char valor;
    int cancel = false;

    do
    {

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
        cout << "1- NUMEROS DIVISIBLES" << endl;
        cout << "2- PAR O IMPAR" << endl;
        cout << "3- POSITIVO, NEGATIVO O CERO" << endl;
        cout << "4- CANTIDAD DE CARACTERES DE UNA PALABRA" << endl;
        cout << "5- PALABRA, INICIA Y FINALIZA CON LA MISMA LETRA" << endl;
        cout << "6- SALIR" << endl
             << endl;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << "Elegir Opciones(1-6): ";
        cin >> valor;
        cout << "------------------------" << endl;

        switch (valor)
        {
        case '1':
            divisible();
            pause();
            break;
        case '2':
            parImpar();
            pause();
            break;
        case '3':
            positivoNegativoCero();
            pause();
            break;
        case '4':
            caracteres();
            pause();
            break;
        case '5':
            inicioFinal();
            pause();
            break;
        case '6':
            cancel = true;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
            cout << "Hasta la proximaaaa" << endl;
            break;

        default:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
            cout << "Opcion no valida" << endl;
            pause();
            break;
        }

    } while (cancel != true);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    return 0;
}

// Funcion para verificar si un numero es divisible entre otro
void divisible()
{
    int valor[2];
    cout << "NUMEROS DIVISIBLES" << endl;
    cout << "------------------------" << endl
         << endl;

    cout << "Ingrese primer numero: ";
    cin >> valor[0];
    cout << "Ingrese segundo numero: ";
    cin >> valor[1];

    if (valor[0] % valor[1] == 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        cout << valor[0] << " es divisible entre " << valor[1] << endl;
    }
    else
    {

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout << valor[0] << " no es divisible entre " << valor[1] << endl;
    }
}

// Funcion para verificar si un numero es par o impar
void parImpar()
{
    int number;
    cout << "PAR O IMPAR" << endl;
    cout << "------------------------" << endl
         << endl;

    cout << "Ingrese numero: ";
    cin >> number;
    if (number % 2 == 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        cout << number << " es numero par" << endl;
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout << number << " es numero impar" << endl;
    }
}
void positivoNegativoCero()
{
    int number;
    cout << "POSITIVO, NEGATIVO O CERO" << endl;
    cout << "------------------------" << endl
         << endl;
    cout << "Ingrese numero: ";
    cin >> number;
    if (number > 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        cout << number << " es positivo" << endl;
    }
    else if (number < 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout << number << " es negativo" << endl;
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        cout << number << " es cero :)" << endl;
    }
}

void caracteres()
{
    string palabra;
    cout << "CANTIDAD DE CARACTERES DE UNA PALABRA" << endl;
    cout << "------------------------" << endl
         << endl;

    cout << "Ingrese palabra: ";
    cin >> palabra;

    if (palabra.length() > 10)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        cout << palabra << ", tiene mas de 10 caracteres" << endl;
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout << palabra << ", tiene igual o menos de 10 caracteres" << endl;
    }
    if (palabra.length() % 2 == 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        cout << palabra << ", su longitud es par" << endl;
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout << palabra << ", su longitud es impar" << endl;
    }
}

void inicioFinal()
{
    string palabra;
    cout << "PALABRA, INICIA Y FINALIZA CON LA MISMA LETRA" << endl;
    cout << "------------------------" << endl
         << endl;

    cout << "Ingrese palabra: ";
    cin >> palabra;

    if (palabra[0] == palabra[palabra.length() - 1])
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        cout << palabra << ", inicia y finaliza con la misma letra" << endl;
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout << palabra << ", no finaliza con la misma letra" << endl;
    }
}

// Funcion para pausar
void pause()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "------------------------" << endl;
    cout << "Pulsa una tecla para continuar...";
    getwchar();
    getwchar();
}