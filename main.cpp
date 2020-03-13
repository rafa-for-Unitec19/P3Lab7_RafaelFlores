#include <iostream>
#include <vector>
#include "vector.hpp"
#include "racional.hpp"
#include "complejo.hpp"

using namespace std;
vector<Vector<Racional>> racionales;
vector<Vector<Complejo>> complejos;
int const vectorTam = 3;

int menu()
{
    int op;
    cout << "Ingrese la opcion que mas desee:"
         << "\n\t1. Agregar Vector"
         << "\n\t2. Listar Vectores"
         << "\n\t3. Operar Vectores"
         << "\n\t4. Salida\n";
    cin >> op;
    return op;
}

int menuTipos()
{
    int op;
    cout << "Ingrese la opcion que mas desee:"
         << "\n\t1. Racional"
         << "\n\t2. Complejo\n";
    cin >> op;
    if (op < 3 && op > 0)
    {
        return op;
    }
    else
    {
        cout << "Debe ingresar la opcion correcta" << endl;
    }
    return op;
}

Racional agregarRacional()
{
    cout << "Ingrese el Numerador" << endl;
    int num;
    cin >> num;
    cout << "Ingrese el denominador" << endl;
    int den;
    cin >> den;
    Racional temp(num, den);
    return temp;
}

Complejo agregarComplejo()
{
    cout << "Ingrese la parte Real" << endl;
    int real;
    cin >> real;
    cout << "Ingrese la parte Imaginaria" << endl;
    int img;
    cin >> img;
    Complejo temp(real, img);
    return temp;
}

void agregarVectorComplejo()
{
    Vector<Complejo> temp;
    temp.setCordX(agregarComplejo());
    temp.setCordY(agregarComplejo());
    temp.setCordZ(agregarComplejo());
    complejos.push_back(temp);
}

void agregarVectorRacional()
{
    Vector<Racional> temp;
    temp.setCordX(agregarRacional());
    temp.setCordY(agregarRacional());
    temp.setCordZ(agregarRacional());
    racionales.push_back(temp);
}

void listarRacionales()
{
    for (size_t i = 0; i < racionales.size(); i++)
    {
        cout << "| " << i << " -> ";
        racionales[i].toStrings();
    }
}

void listarComplejos()
{
    for (size_t i = 0; i < complejos.size(); i++)
    {
        cout << "| " << i << " -> ";
        complejos[i].toStrings();
    }
}

void selector()
{
    bool flag = false;
    while (!flag)
    {
        switch (menu())
        {
        case 1:
            if (menuTipos() == 1)
            {
                agregarVectorRacional();
            }
            else
            {
                agregarVectorComplejo();
            }
            break;
        case 2:
            if (menuTipos() == 1)
            {
                listarRacionales();
            }
            else
            {
                listarComplejos();
            }
            break;
        case 3:
            if (menuTipos() == 1)
            {
                
            }
            else
            {
            }
            break;
        case 4:
            flag = true;
            break;
        default:
            cout << "La opcion es incorrecta" << endl;
            break;
        }
    }
}

int main()
{
    selector();
    return 0;
}