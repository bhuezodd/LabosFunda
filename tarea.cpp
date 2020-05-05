#include <iostream>
#include <math.h>
#include <locale.h>

using namespace std;

int promedio();
bool divisible();
float *cuadratica();
bool parImpar();

int main()
{
    int o = 0;
    cout << "Elegir Programa:" << endl;
    cout << "1. Promedios" << endl;
    cout << "2. Divisibles" << endl;
    cout << "3. Formula Cuadratica" << endl;
    cout << "4. Par o Impar" << endl;

    do
    {
        cin >> o;
        if (o < 1 || o > 4)
        {
            cout << "Por favor elegir un opcion valida" << endl;
        }
    } while (o < 1 || o > 4);

    switch (o)
    {
    case 1:
        cout << "Promedio: " << promedio() << endl;
        break;
    case 2:
        if (divisible())
        {
            cout << "Si son divisible" << endl;
        }
        else
        {
            cout << "No son divisible" << endl;
        }

        break;
    case 3:
        float *p;
        p = cuadratica();

        if (p[0] != p[0])
        {
            cout << "Esta ecuacion no tiene soluciones en los reales." << endl;
        }
        else
        {
            cout << "--------------" << endl;
            cout << "X = " << p[0] << endl;
            cout << "--------------" << endl;
            cout << "X = " << p[1] << endl;
            cout << "--------------" << endl;
        }

        break;
    case 4:
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
    return (total / 3);
}

bool divisible()
{
    cout << "----Divisible----" << endl;
    int datos[2];
    int total = 0;

    cout << "Ingrese numero(entero): 1" << endl;
    cin >> datos[0];
    cout << "Ingrese numero(entero): 2" << endl;
    cin >> datos[1];
    if (datos[0] % datos[1] == 0)
    {
        return true;
    }

    return false;
}

float *cuadratica()
{
    cout << "----Cuadratica----" << endl;
    int datos[3];
    static float total[2];

    cout << "Ingrese A(entero):" << endl;
    cin >> datos[0];
    cout << "Ingrese B(entero):" << endl;
    cin >> datos[1];
    cout << "Ingrese C(entero):" << endl;
    cin >> datos[2];

    total[0] = (-(datos[1]) + sqrtl(pow(datos[1], 2) - (4 * datos[0] * datos[2]))) / 2 * datos[0];
    total[1] = (-(datos[1]) - sqrtl(pow(datos[1], 2) - (4 * datos[0] * datos[2]))) / 2 * datos[0];

    return total;
}

bool parImpar(){
    cout << "----Cuadratica----" << endl;
    int dato;

    cout << "Ingrese numero(entero):" << endl;
    cin >> dato;

    if (dato % 2 == 0){
        return true;
    }

    return false;
}