#include <iostream>
#include <string>
#include <iomanip>
using namespace std; 

void saludo(int n);
int menu(); 

//FUNCIONES PROTOTIPOS
void lectura_calificaciones(float notas[], int &n_notas);
void buscar_calificaciones(float &buscar, float notas[], int n_notas);
void insertar_cal(float &insert, float notas[], int &pos);
void ver_notas(float notas[], int n_notas);
void eliminar_nota(float notas[], int &n_notas, int pos);

const int max_calificaciones = 50;

int main() {
    cout << "Bienvenido al programa ejercicio de arreglos" << endl;
    cout << "Autores: Anahi Pillajo, Eduardo Castro" << endl;
    cout << "Menu de ejercicios realizados" << endl;
    cout << "Escoja qué ejercicio desea visualizar" << endl;
    
    int opcion, n_notas = 0, op, pos; 
    float notas[max_calificaciones];
    float x;
    
    opcion = menu();
    
    while (opcion != 0) {
        switch(opcion) {
            case 1:
                saludo(opcion); 
                cout << "Para dejar de ingresar notas ingrese '-1': \n";
                lectura_calificaciones(notas, n_notas);
                do {
                    cout << "Que desea hacer: \n 1.-Buscar calificación\n";
                    cout << "2.-Eliminar nota\n";
                    cout << "3.-Editar nota\n";
                    cout << "4.-Ver lista de notas\n";
                    cout << "0.-Salir\n";
                    cin >> op;
                    switch (op) {
                        case 1:
                            buscar_calificaciones(x, notas, n_notas);
                            break;
                        case 2:
                            cout << "Ingrese la posición de la nota que desea eliminar: ";
                            cin >> pos;
                            eliminar_nota(notas, n_notas, pos);
                            break;
                        case 3:
                            cout << "Ingrese la posición de la nota que desea modificar: ";
                            cin >> pos;
                            cout << "Ingrese la nueva nota: ";
                            cin >> x;
                            insertar_cal(x, notas, pos);
                            break;
                        case 4:
                            ver_notas(notas, n_notas);
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opción no válida." << endl;
                            break;
                    }
                } while (op != 0);
                break;
            case 2:
                saludo(opcion); 
                break;
            case 3:
                saludo(opcion); 
                break;
            case 4:
                saludo(opcion); 
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }      
        opcion = menu();
    }
}

int menu() {
    int op = -1;
    while (op < 0 || op > 4) {
        cout << "*** Menú de opciones ***" << endl;
        cout << "1.- Ejercicio 1" << endl;
        cout << "2.- Ejercicio 2" << endl;
        cout << "3.- Ejercicio 3" << endl;
        cout << "4.- Ejercicio 4" << endl;
        cout << "0.- Salir" << endl;
        cout << "Ingrese qué ejercicio desea ver: ";
        cin >> op;
        if (op < 0 || op > 4) {
            cout << "Opción no válida, ingrese una opción válida." << endl;
        }
    }
    return op;
}

void saludo(int n) {
    cout << "Bienvenido al ejercicio " << n << endl;
    cout << "Autores: Anahi Pillajo, Eduardo Castro" << endl;
}

void lectura_calificaciones(float notas[], int &n_notas) {
    for (int i = 0; i < max_calificaciones; i++) {
        cout << "Ingresa la calificación: ";
        cin >> notas[i];
        if (notas[i] == -1) {
            break;
        }
        n_notas++;
    }
}

void buscar_calificaciones(float &buscar, float notas[], int n_notas) {
    cout << "Ingrese la nota que desea buscar: ";
    cin >> buscar;
    for (int i = 0; i < n_notas; i++) {
        if (buscar == notas[i]) {
            cout << "Calificación encontrada en la posición: " << i + 1 << endl;
            return;
        }
    }
    cout << "Calificación no encontrada." << endl;
}

void insertar_cal(float &insert, float notas[], int &pos) {
    if (pos >= 0 && pos < max_calificaciones) {
        notas[pos] = insert;
    } else {
        cout << "Posición no válida." << endl;
    }
}

void eliminar_nota(float notas[], int &n_notas, int pos) {
    if (pos >= 0 && pos < n_notas) {
        for (int i = pos; i < n_notas - 1; i++) {
            notas[i] = notas[i + 1];
        }
        n_notas--;
    } else {
        cout << "Posición no válida." << endl;
    }
}

void ver_notas(float notas[], int n_notas) {
    for (int i = 0; i < n_notas; i++) {
        cout << "[" << notas[i] << "]";
        if (i < n_notas - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}