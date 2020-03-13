#include <iostream>
using namespace std;

int menu(){
    int op;
    cout << "Ingrese la opcion que mas desee:"
        << "\n\t1. Agregar Vector"
        << "\n\t2. Listar Vectores"
        << "\n\t3. Operar Vectores";
    cin >> op;
    return op;
}

int menuTipos(){
    int op;
    cout << "Ingrese la opcion que mas desee:"
        << "\n\t1. Agregar Vector"
        << "\n\t2. Listar Vectores";
    cin >> op;
    if (op < 3 && op > 0){
        return op;
    }else{
        cout << "Debe ingresar la opcion correcta" << endl;
    }
    return op;
}

void selector(){}

int main(){
    selector();
    return 0;
}