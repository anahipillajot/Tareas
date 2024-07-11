#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <random>
using namespace std; 

//FUNCIONES PROTOTIPOS
void saludo(int n);
int menu(); 
void lectura_calificaciones(float notas[], int &n_notas);
void buscar_calificaciones(float &buscar, float notas[], int n_notas);
void insertar_cal(float &insert, float notas[], int &pos);
void ver_notas(float notas[], int n_notas);
void eliminar_nota(float notas[], int &n_notas, int pos);
bool palindromo(char palabra[], int longitud);
void duplicados(float numeros[], int &n);
void simularTiros(int frecuencias[], int num_tiros);
//CONSTANTES GLOBALES
const int max_calificaciones = 50, max_3=20 ,num_tiros = 36000, min_suma = 2, max_suma = 12;

int main() {
    cout << "Bienvenido al programa ejercicio de arreglos" << endl;
    cout << "Autores: Anahi Pillajo, Eduardo Castro" << endl;
    cout << "Menu de ejercicios realizados" << endl;
    cout << "Escoja qué ejercicio desea visualizar" << endl;
    //VARIABLES USADAS
    int opcion, n_notas = 0, op, pos; 
    int frecuencias[max_suma + 1];
    float notas[max_calificaciones], numeros[max_3];
    char palabra[max_calificaciones];
    float x;
    
    opcion = menu();
    //MENU GENERAL
    while (opcion != 0) {
        switch(opcion) {
            case 1:
                saludo(opcion); 
                cout << "Para dejar de ingresar notas ingrese '-1': \n";
                lectura_calificaciones(notas, n_notas);
                //SUBMENU 1
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
            case 2:{
                saludo(opcion); 
                cout << "Ingrese una palabra para verificar si es un palíndromo: ";
                cin >> palabra;
                int longitud = 0;
                  while (palabra[longitud] != '\0' && longitud < max_calificaciones) {
                    longitud++; }
                 if (palindromo(palabra, longitud)) {
                    cout << "La palabra es un palíndromo." << endl;
                } else {
                    cout << "La palabra no es un palíndromo." << endl;
                }
                break;}
            case 3:{
                saludo(opcion);
                duplicados(numeros, n_notas);
                break;}
            case 4:{
                saludo(opcion); 
                simularTiros(frecuencias, num_tiros);
                    cout << "Suma\tFrecuencia" << endl;
                    for (int i = min_suma; i <= max_suma; i++) {
                        cout << i << "\t" << frecuencias[i] << endl;
                    }

                    // Determinar si los totales son razonables
                    cout << "\nVerificación de totales razonables:" << endl;
                    cout << "Frecuencia esperada para 7: aproximadamente " << num_tiros / 6 << endl;
                    cout << "Frecuencia real para 7: " << frecuencias[7] << endl;

                break;}
            default:
                cout << "Opción no válida." << endl;
                break;
        }      
        opcion = menu();
    }
}
//MENU Y SALUDO
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
// EJERCICIO 1 
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

//EJERCICIO 2.

bool palindromo(char palabra[], int longitud){
   char palabra_n[max_calificaciones];
    int long_palabra = 0;

    // Copiar y convertir a minúsculas
    for (int i = 0; i < longitud; i++) {
        if (palabra[i] != ' ') {
            palabra_n[long_palabra++] = tolower(palabra[i]);
        }
    }
   // Comprobación de palíndromo
    for (int i = 0, j = long_palabra - 1; i < j; i++, j--) {
        if (palabra_n[i] != palabra_n[j]) {
            return false;
        }
    }

    return true;
}

// EJERCICIO 3.

void duplicados(float numeros[], int &n) {
    float n1;
    n1 = 0;

    for (int i = 0; i < max_3; i++) {
        bool esDuplicado = false;
        cout << "Ingrese un numero entre 10 y 100: ";
        cin >> n1;

        // Validar que el número esté en el rango
        if (n1 < 10 || n1 > 100 || n == ' ') {
            cout << "Numero fuera de rango. Intente de nuevo." << endl;
            i--; // Volver a pedir el número
            continue;
        }

        // Verificar si el número es un duplicado
        for (int j = 0; j < n; j++) {
            if (numeros[j] == n1) {
                esDuplicado = true;
                cout << "Numero duplicado. Intente de nuevo." << endl;
                i--;
                break;
            }
        }

        // Si no es un duplicado, agregarlo al arreglo
        if (!esDuplicado) {
            numeros[n] = n1;
            n++;
        }
    }

    // Mostrar los números únicos ingresados
    cout << "Numeros unicos ingresados: ";
    for (int i = 0; i < n; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

}

//EJERCICIO 4
void simularTiros(int frecuencias[], int num_tiros) {
    // biblioteca random
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribucion(1, 6);

    // Arreglo
    for (int i = 0; i <= max_suma; i++) {
        frecuencias[i] = 0;
    }

    // Simular los tiros de los dados
    for (int i = 0; i < num_tiros; i++) {
        int dado1 = distribucion(gen);
        int dado2 = distribucion(gen);
        int suma = dado1 + dado2;
        frecuencias[suma]++;
    }
}
