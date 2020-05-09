#include <iostream>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <Windows.h>

using namespace std;

int promedio();
void areaPerimetro();
bool divisible();
float *cuadratica();
void gastosDinero();
bool parImpar();

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
    int o = 0;
    int con = 0;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << "---Ejercicios quitados de GUIA---" << endl;
    cout << "5. Divisibles" << endl;
    cout << "6. Par o Impar" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
    cout << "---Guia de ejercicios nuevos---" << endl;
    cout << "1. Promedios" << endl;
    cout << "2. Area y Perimetro" << endl;
    cout << "3. Formula Cuadratica" << endl;
    cout << "4. Gasto de dinero" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    cout << "Cerrar (ctrl + c)..." << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "Elegir Programa: " << endl;

    do
    {
        cin >> o;
        if (o < 1 || o > 6)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
            cout << "Por favor elegir un opcion valida" << endl;
        }
        if (con > 3)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "Revise las opciones antes de ingresar algo" << endl;
            break;
        }
        con++;
    } while (o < 1 || o > 6);

    switch (o)
    {
    case 1:
        cout << "Promedio: " << promedio() << endl;
        break;
    case 2:
        areaPerimetro();
        break;
    case 3:
        float *p;
        p = cuadratica();

        if (p[0] != p[0])
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "Esta ecuacion no tiene soluciones en los reales." << endl;
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            cout << "--------------" << endl;
            cout << "X = " << p[0] << endl;
            cout << "--------------" << endl;
            cout << "X = " << p[1] << endl;
            cout << "--------------" << endl;
        }

        break;
    case 4:
        gastosDinero();
        break;
    case 5:
        if (divisible())
        {
            cout << "Si son divisible" << endl;
        }
        else
        {
            cout << "No son divisible" << endl;
        }

        break;
    case 6:
        if (parImpar())
        {
            cout << "El numero es par" << endl;
        }
        else
        {
            cout << "El numero es impar" << endl;
        }
        break;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    return 0;
}

int promedio()
{
    cout << "----Promedio----" << endl;
    int datos;
    int total = 0;

    for (int i = 0; i < 3; i++)
    {
        cout << "Ingrese numero(entero): " << (i + 1) << endl;
        cin >> datos;
        total += datos;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    return (total / 3);
}

void areaPerimetro()
{
    cout << "----Area y Perimetro----" << endl;
    double datos;
    double perimetro = 0;
    double area = 0;

    cout << "Ingrese radio: " << endl;
    cin >> datos;

    area = 3.1416 * pow(datos, 2);
    perimetro = 2 * 3.1416 * datos;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout << "Area: " << area << endl;
    cout << "Perimetro: " << perimetro << endl;
}

bool divisible()
{
    cout << "----Divisible----" << endl;
    int datos[2];
    int total = 0;

    cout << "Ingrese primer numero(entero):" << endl;
    cin >> datos[0];
    cout << "Ingrese segundo numero(entero):" << endl;
    cin >> datos[1];
    if (datos[0] % datos[1] == 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        return true;
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    return false;
}

float *cuadratica()
{
    cout << "----Cuadratica----" << endl;
    int datos[3];
    static float total[2];

    cout << "Ingrese A(enteros):" << endl;
    cin >> datos[0];
    cout << "Ingrese B(enteros):" << endl;
    cin >> datos[1];
    cout << "Ingrese C(enteros):" << endl;
    cin >> datos[2];

    total[0] = (-(datos[1]) + sqrt(pow(datos[1], 2) - (4 * datos[0] * datos[2]))) / 2 * datos[0];
    total[1] = (-(datos[1]) - sqrt(pow(datos[1], 2) - (4 * datos[0] * datos[2]))) / 2 * datos[0];

    return total;
}

void gastosDinero()
{
    cout << "----Gasto de dinero----" << endl;
    string name;
    double precio;
    int cantidad;

    double total = 0;

    cout << "Ingrese nombre del producto: " << endl;
    cin >> name;
    cout << "Ingrese precio del producto: " << endl;
    cin >> precio;
    cout << "Ingrese cantidad comprada: " << endl;
    cin >> cantidad;

    total = precio * cantidad;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);

    cout << "Se ha gastado $" << total << " en la compra de: " + name << endl;
}

bool parImpar()
{
    cout << "----Par o Impar----" << endl;
    int dato;

    cout << "Ingrese numero(entero):" << endl;
    cin >> dato;

    if (dato % 2 == 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        return true;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

    return false;
}