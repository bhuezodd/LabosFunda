#include <iostream>
#include <sstream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;
// Funciones del laboratorio
void mcd();
void segDespues();
void yearBisiesto();
void siguienteDia();

// FUNCIONES DE APOYO
void posXY(int, int);
void OpcionMenu(const wchar_t *str, int y)
{
    posXY(0, y);
    cout << "(";
    posXY(2, y);
    cout << ")";
    posXY(4, y);
    WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), str, wcslen(str), NULL, NULL);
}
void myprint(const wchar_t *str)
{
    WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), str, wcslen(str), NULL, NULL);
}
void clear(int);
void resultF(string value, string text)
{
    cout << "------------------------" << endl;
    if (text == "success")
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    }
    else if (text == "error")
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    }
    else if (text == "warning")
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    }
    cout << value << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
bool bisiesto(int a)
{
    bool b = false;
    // Validamos que el año ingresado sea divisble entre 400
    if (a % 400 == 0)
    {
        b = true;
    }
    else
    {
        // Luego validamos que sea divisible entre 4 pero no divisible entre 100
        if (a % 4 == 0 && a % 100 != 0)
        {
            b = true;
        }
    }
    return b;
}
bool valRango(int, int, int);
int validacionDeFecha(int, int, int);
void sumarDias(struct tm *date, int days)
{
    const time_t ONE_DAY = 24 * 60 * 60;

    time_t date_seconds = mktime(date) + (days * ONE_DAY);

    *date = *localtime(&date_seconds);
}
/*
    APLICACIÓN CON MENU CON TECLAS

    Referencias:
    http://www.cplusplus.com/forum/beginner/132595/
*/
// Se usara para la funcion de posicionamiento
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // Nos servira para colocar el puntero
COORD CursorPosition;                             // Cordenadas del puntero

/*
    NUMERO DE COLORES PARA COLOREAR LA CONSOLA:
    INCLUIR:  #include <Windows.h>
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

int main()
{
    //Linmpiamos la consola (Comando solo funcional en Windows)
    system("cls");

    int opcion = 1, x = 8;
    bool salir = false;

    posXY(4, 4);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << "LABORATORIO 5";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    //Puntero a mover
    posXY(1, 8);
    cout << "x";

    while (!salir)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        OpcionMenu(L"Minimo comun multiplo", 8);
        OpcionMenu(L"Un segundo despues", 9);
        OpcionMenu(L"Año bisiesto", 10);
        OpcionMenu(L"Siguiente día", 11);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        OpcionMenu(L"Salir", 12);

        // Evitamos que se imprima algun mensaje
        system("pause>nul");

        //Programamos flecha hacia abajo
        if (GetAsyncKeyState(VK_DOWN) && x != 12 && !GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_RETURN))
        {
            posXY(1, x);
            cout << " ";
            x++;
            posXY(1, x);
            cout << "x";
            opcion++;
            continue;
        }
        // Programamos flecha hacia arriba
        // Por bugs que pasan evitamos que se active si estas precionando la tecla de abajo y el enter
        // NOTA: Esto en mi pc
        if (GetAsyncKeyState(VK_UP) && x != 8 && !GetAsyncKeyState(VK_DOWN) && !GetAsyncKeyState(VK_RETURN))
        {
            posXY(1, x);
            cout << " ";
            x--;
            posXY(1, x);
            cout << "x";
            opcion--;
            continue;
        }
        // Programamos boton de enter, para seleccionar opcion
        // Se valida que no se este presionando las mismas teclas de navegacion, por temas de bugs
        // NOTA: Esto en mi pc
        if (GetAsyncKeyState(VK_RETURN) && !GetAsyncKeyState(VK_DOWN) && !GetAsyncKeyState(VK_UP))
        {
            posXY(0, 14);
            cout << "-------------------------------" << endl;
            switch (opcion)
            {
            case 1:
                posXY(6, 15);
                cout << "Minimo comun multiplo" << endl;
                posXY(0, 16);
                cout << "-------------------------------" << endl;
                mcd();
                clear(opcion);
                break;
            case 2:
                posXY(6, 15);
                cout << "Un segundo despues" << endl;
                posXY(0, 16);
                cout << "-------------------------------" << endl;
                segDespues();
                clear(opcion);
                break;
            case 3:
                posXY(6, 15);
                myprint(L"Año bisiesto");
                posXY(0, 16);
                cout << "-------------------------------" << endl;
                yearBisiesto();
                clear(opcion);
                break;
            case 4:
                posXY(6, 15);
                myprint(L"Siguiente día");
                posXY(0, 16);
                cout << "-------------------------------" << endl;
                siguienteDia();
                clear(opcion);
                break;
            case 5:
                posXY(6, 15);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                cout << "Hasta la proxima" << endl;
                posXY(0, 16);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                cout << "-------------------------------" << endl;
                salir = true;
                break;
            }
        }
    }

    posXY(18, 22);
    return 0;
}

// Funcion de posicionamiento
void posXY(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}
void clear(int opcion)
{

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "------------------------" << endl
         << endl;
    cout << "Pulsa ENTER para continuar...";
    getwchar();
    getwchar();
    system("cls");
    posXY(4, 4);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << "LABORATORIO 5";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    //Puntero a mover
    posXY(1, 7 + opcion);
    cout << "x";
}

// Funciones del LABORATORIO 5
void mcd()
{
    string an, bn;
    int a, b, c, r;
    cout << "Escribir dividendo: ";
    cin >> an;
    cout << "Escribir divisor: ";
    cin >> bn;

    try
    {
        a = stoi(an);
        b = stoi(bn);
        r = a % b;
        while (r != 0)
        {
            a = b;
            b = r;
            r = a % b;
        }
        string mess = "MCD es: " + std::to_string(b);
        resultF(mess, "success");
    }
    catch (const std::exception &e)
    {
        resultF("Formato no correcto", "error");
    }
}
void segDespues()
{
    string tiempo, data;
    bool error = false;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << "Formato 24 horas, ejemplo: 23:59:59 " << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "Ingresar hora (hh:mm:ss): ";
    cin >> tiempo;
    if (tiempo.length() == 8 && tiempo.find_last_of(":") == 5 && tiempo.find_first_of(":") == 2)
    {
        int time[3], e = 0;
        for (int i = 0; i < tiempo.length(); i++)
        {
            if (tiempo[i] != ':')
            {
                data += tiempo[i];
            }
            else
            {
                try
                {
                    time[e] = stoi(data);
                }
                catch (const std::exception &e)
                {
                    error = true;
                    break;
                }

                data = "";
                e++;
            }
        }
        try
        {
            time[e] = stoi(data);
        }
        catch (const std::exception &e)
        {
            error = true;
        }
        if (!error)
        {
            time[2] += 1;
            if (time[2] >= 60)
            {
                time[2] = 0;
                time[1] += 1;
            }
            if (time[1] >= 60)
            {
                time[1] = 0;
                time[0] += 1;
            }
            if (time[0] >= 24)
            {
                time[0] = 0;
            }
            tiempo = std::to_string(time[0]).length() > 1 ? std::to_string(time[0]) : '0' + std::to_string(time[0]);
            tiempo += ':';
            tiempo += std::to_string(time[1]).length() > 1 ? std::to_string(time[1]) : '0' + std::to_string(time[1]);
            tiempo += ':';
            tiempo += std::to_string(time[2]).length() > 1 ? std::to_string(time[2]) : '0' + std::to_string(time[2]);

            resultF("Hora un segundo despues: " + tiempo, "success");
        }
        else
        {
            resultF("Formato no correcto", "error");
        }
    }
    else
    {
        resultF("Formato no correcto", "error");
    }
}
void yearBisiesto()
{

    int a;
    string an;
    myprint(L"Ingrese año: ");
    cin >> an;
    try
    {
        a = stoi(an);

        if (bisiesto(a))
        {
            resultF("Es bisiesto", "success");
        }
        else
        {
            resultF("No es bisiesto", "success");
        }
    }
    catch (const std::exception &e)
    {
        resultF("Formato no correcto", "error");
    }
}
void siguienteDia()
{
    struct tm date = {0, 0, 12};

    string ano, mes, dia, tiempo;
    int year, month, day;

    myprint(L"Ingrese dia (dd): ");
    cin >> dia;
    myprint(L"Ingrese mes (mm): ");
    cin >> mes;
    myprint(L"Ingrese año (aaaa): ");
    cin >> ano;
    if (dia.length() == 2 && mes.length() == 2 & ano.length() == 4)
    {
        try
        {
            year = stoi(ano);
            month = stoi(mes);
            day = stoi(dia);
            switch (validacionDeFecha(day, month, year))
            {
            case 0:
                date.tm_year = year - 1900;
                date.tm_mon = month - 1;
                date.tm_mday = day;

                sumarDias(&date, +1);

                tiempo = std::to_string(date.tm_mday).length() > 1 ? std::to_string(date.tm_mday) : '0' + std::to_string(date.tm_mday);
                tiempo += '-';
                tiempo += std::to_string(date.tm_mon).length() > 1 ? std::to_string(date.tm_mon + 1) : '0' + std::to_string(date.tm_mon + 1);
                tiempo += '-';
                tiempo += std::to_string(date.tm_year + 1900);

                resultF("Fecha un dia despues: " + tiempo, "success");
                break;
            case 1:
                resultF("Solo existen 12 meses", "error");
                break;
            case 2:
                resultF("El mes ingresado tiene (01-29)", "error");
                break;
            case 3:
                resultF("El mes ingresado tiene (01-28)", "error");
                break;
            case 4:
                resultF("El mes ingresado tiene (01-30)", "error");
                break;
            case 5:
                resultF("El mes ingresado tiene (01-31)", "error");
                break;
            }
        }
        catch (const std::exception &e)
        {
            resultF("Formato no correcto", "error");
        }
    }
    else
    {
        resultF("Formato no correcto", "error");
    }
}

int validacionDeFecha(int d, int m, int a)
{
    int state = 0;
    if (valRango(m, 0, 13))
    {
        if (m == 2)
        {
            if (bisiesto(a))
            {
                if (!valRango(d, 0, 30))
                {
                    state = 2;
                }
            }
            else
            {
                if (!valRango(d, 0, 29))
                {
                    state = 3;
                }
            }
        }
        else if (m == 4 && m == 6 && m == 9 & m == 11)
        {
            if (!valRango(d, 0, 31))
            {
                state = 4;
            }
        }
        else
        {
            if (!valRango(d, 0, 32))
            {
                state = 5;
            }
        }
    }
    else
    {
        state = 1;
    }
    return state;
}
bool valRango(int a, int x, int y)
{
    bool state = false;
    if (a > x && a < y)
    {
        state = true;
    }
    return state;
}