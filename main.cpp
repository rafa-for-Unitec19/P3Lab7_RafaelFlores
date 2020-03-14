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

int menuOperaciones()
{
    int op;
    cout << "Ingrese la opcion que mas desee:"
         << "\n\t1. Suma"
         << "\n\t2. Multiplicacion\n";
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
    if (!den){
        cout << "No puede haber un denominador en 0, cambiando a 1" << endl;;
        den = 1;
    }
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
    cout << "Ingrese la componente de la cordenada X" << endl;
    temp.setCordX(agregarComplejo());
    cout << "Ingrese la componente de la cordenada Y" << endl;
    temp.setCordY(agregarComplejo());
    cout << "Ingrese la componente de la cordenada Z" << endl;
    temp.setCordZ(agregarComplejo());
    complejos.push_back(temp);
}

void agregarVectorRacional()
{
    Vector<Racional> temp;
    cout << "Ingrese la componente de la cordenada X" << endl;
    temp.setCordX(agregarRacional());
    cout << "Ingrese la componente de la cordenada Y" << endl;
    temp.setCordY(agregarRacional());
    cout << "Ingrese la componente de la cordenada Z" << endl;
    temp.setCordZ(agregarRacional());
    racionales.push_back(temp);
}

void listarRacionales()
{
    for (size_t i = 0; i < racionales.size(); i++)
    {
        cout << "| " << i << " -> ";
        racionales[i].toStrings();
        cout << "\n";
    }
}

void listarComplejos()
{
    for (size_t i = 0; i < complejos.size(); i++)
    {
        cout << "| " << i << " -> ";
        complejos[i].toStrings();
        cout << "\n";
    }
}

void impresionRacional(int p, int s, bool t){
    if (t)
    {
        racionales[p].toStrings();
        cout << " + "; 
        racionales[s].toStrings(); 
        cout << " = "; 
        racionales[racionales.size()-1].toStrings();
        cout << "\n";
    }else{
        racionales[p].toStrings();
        cout << " * "; 
        racionales[s].toStrings(); 
        cout << " = ";
        racionales[racionales.size()-1].toStrings();
        cout << "\n";
    }
}

void impresionComplejo(int p, int s, bool t){
    if (t)
    {
        complejos[p].toStrings();
        cout << " + "; 
        complejos[s].toStrings(); 
        cout << " = "; 
        complejos[racionales.size()-1].toStrings();
        cout << "\n";
    }else{
        complejos[p].toStrings();
        cout << " * "; 
        complejos[s].toStrings(); 
        cout << " = ";
        complejos[racionales.size()-1].toStrings();
        cout << "\n";
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
                if(!racionales.empty()){
                    listarRacionales();
                }else{
                    cout << "No hay sufiecientes vectores para mostrar" << endl;
                }
            }
            else
            {
                if(!complejos.empty()){
                    listarComplejos();
                }else{
                    cout << "No hay sufiecientes vectores para mostrar" << endl;
                }
            }
            break;
        case 3:{
            int primer, segundo;
            if (menuTipos() == 1)
            {
                if(racionales.size() > 0){
                    cout << "Seleccione los Racionales a operar:" << endl;
                    listarRacionales();
                    cout << "Escoja el primer racional" << endl;
                    cin >> primer;
                    cout << "Escoja el segundo racional" << endl;
                    cin >> segundo;
                    if (menuOperaciones() == 1){
                        Vector<Racional> temp = racionales[primer] + racionales[segundo];
                        racionales.push_back(temp);
                        impresionRacional(primer, segundo, true);
                    }else{
                        Vector<Racional> temp = racionales[primer] * racionales[segundo];
                        racionales.push_back(temp);
                        impresionRacional(primer, segundo, false);
                    }
                }else{
                    cout << "No hay sufiecientes vectores para operar" << endl;
                }
            }
            else
            {
                if(complejos.size() > 0){
                    cout << "Seleccione los Complejos a operar:" << endl;
                    listarComplejos();
                    cout << "Escoja el primer Complejo" << endl;
                    cin >> primer;
                    cout << "Escoja el segundo Complejo" << endl;
                    cin >> segundo;
                    if (menuOperaciones() == 1){
                        Vector<Complejo> temp = complejos[primer] + complejos[segundo];
                        complejos.push_back(temp);
                        impresionComplejo(primer, segundo, true);
                    }else{
                        Vector<Complejo> temp = complejos[primer] * complejos[segundo];
                        complejos.push_back(temp);
                        impresionComplejo(primer, segundo, false);
                    }
                }else{
                    cout << "No hay sufiecientes vectores para operar" << endl;
                }
            }
            break;
            }
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