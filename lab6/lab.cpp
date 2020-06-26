#include "../lib/general.h"
#include <vector>

using namespace std;
/*
    NUMERO DE COLORES PARA COLOREAR LA CONSOLA:
    INCLUIR:  #include <windows.h>
    COMANDO:  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), #);

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
// Vistas
void view1();
void view2();

void pause();

//Nucle
int main()
{
    string hola = "adios";
    // Validacion de si es lunux o Windows
#ifdef _WIN32
    system("cls");
#endif
#ifdef linux
    system("clear");
#endif
    string opciones[] = {"Numeros impares", "Numero repetido", "Salir"};

    int test = 0;
    while (test != 2)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        positionXY(3, 2);
        printC(L"BIENVENIDOS AL LABORATORIO 6");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        // Posicion en X, Posicion en Y, Arreglo con opciones del menu, Numero de opciones
        test = menuC(0, 4, opciones, 3);
        if (test != 2)
        {
            system("cls");
            switch (test)
            {
            case 0:
                view1();
                break;
            case 1:
                view2();
                break;
            }
            system("cls");
        }
    }
    positionXY(0, 8);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << "HASTA LA PROXIMA";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    positionXY(0, 9);
    return 0;
}

// Vista 1
void view1()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
    positionXY(3, 2);
    printC(L"NUMEROS IMPARES");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    int num = 1, d = 6;
    int data[100];
    positionXY(0, 4);
    cout << "Ingresar numero entero(Para este lab colocar 1):" << endl;
    cout << "=> ";
    cin >> num;
    data[0] = num;
    for (int i = 1; i < 100; i++)
    {
        num++;
        if (num % 2 == 0)
        {
            data[i] = num + 1;
            num++;
        }
        else
        {
            data[i] = num;
        }
    }
    for (int i = 99; i > 49; i--)
    {
        d++;
        positionXY(0, d);
        cout << "(" << i + 1 << ") " << data[i];
    }
    d = 6;
    for (int i = 49; i > -1; i--)
    {
        d++;
        positionXY(15, d);
        cout << "|   "
             << "(" << i + 1 << ") " << data[i];
    }
    positionXY(0, d + 2);
    pause();
}

// Vista 2
void view2()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
    positionXY(3, 2);
    printC(L"NUMEROS REPETIDOS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    string data, line;
    vector<int> arr;
    int num, con = 0;

    positionXY(0, 4);
    cout << "Ingresar lista de numero (separar por coma ',')" << endl;
    cout << "=>";
    getline(cin, line);
    stringstream ss(line);
    try
    {
        while (getline(ss, data, ','))
        {
            arr.push_back(stoi(data));
        }
        if (arr.size() > 0)
        {
            cout << "Ingresar numero a buscar:" << endl;
            cout << "=>";
            cin >> num;

            for (int i = 0; i < arr.size(); i++)
            {
                if (num == arr[i])
                {
                    con++;
                }
            }
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << endl;
            cout << "Dato vacio" << endl;
        }
    }
    catch (const std::exception &e)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout << "Ingraste un valor no numerico";
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << "El numero " << num << " aparece: " << con << " veces" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    pause();
}

// Funcion para pausar
void pause()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "------------------------------" << endl;
    cout << "Pulsa ENTER para continuar...";
    getwchar();
    getwchar();
}
