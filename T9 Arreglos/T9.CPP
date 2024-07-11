#include <iostream>
using namespace std; 
#include <string>
#include <iomanip>
void saludo(int n);
int menu(); 
void lectura_calificaciones (float notas[]);
void buscar_calificaciones(float &buscar, float notas[]);
void insertar_cal(float &insert, float notas[], int &pos);
const int max_calificaciones = 50;

int main (){
    cout << "Bienvenido al programa ejercicio de  arreglos" << endl;
    cout << "Autores: Anahi Pillajo, Eduardo Castro" << endl;
    cout << "Menu de ejercicios realizados" << endl;
    cout << "Escoja que ejercicio desea visualizar" << endl;
    int opcion; 
    float notas[max_calificaciones];
    float x;
    opcion= menu();
    while (opcion !=0 ){
        switch(opcion){
            case 1:{
                saludo(opcion); 
                cout << "Para dejar de ingresar notas ingrese \' -1 \': \n";
                lectura_calificaciones(notas);
                cout << "Que desea hacer: \n 1.-Buscar calificación:";
                cout << "2.-Eliminar nota: \n";
                cout << "3.-Editar nota: \n";
                cout << "4.- Ver lista de notas \n";
                cout << "0. Salir \n";
                switch (opcion){
                case 1:
                buscar_calificaciones(x,notas);
                    break;
                
                default:
                    break;
                }
                buscar_calificaciones(x, notas);
                break;
            }
            case 2:{
                saludo(opcion); 
                break;
            }
            case 3:{
                saludo(opcion); 

                break; 

            }
            case 4:{
                saludo(opcion); 

                break;
            }
           default:
            cout << "Opción no válida." << endl;
            break; 
        }      
        opcion= menu();

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

void lectura_calificaciones (float notas[]){
    for(int i = 0; i < max_calificaciones; i++){
        cout << "Ingresa las calificaciones \n";
        cin >> notas[i];
        if (notas[i] == -1){
        break;
        }
    } 
}

void ordenar_calificaciones (float notas[]){
    
    float aux;
    for (int i = 0; i < max_calificaciones-1; i ++){
        for (int j = 0; j < max_calificaciones-1 ; j++ ){
            if (notas[j] < notas [j+1])
            notas[j] = notas[j +1];
            aux = notas[i];
            notas [j+1] = aux;
        }
    }
}

void buscar_calificaciones(float &buscar, float notas[]){
    
    cout << "Ingrese la nota que desea buscar: \n";
    cin >> buscar;
    for (int i = 0 ; i < max_calificaciones ; i++){
        if (buscar == notas[i])
            cout << "Calificacion encontrada en la posición: " << i + 1 << endl;
    }
}

void insertar_cal(float &insert, float notas[], int &pos){
    cout << "Ingrese la posicion de la nota que desea modificar: \n";
    cin >> pos;
    cout << "Ingrese la nueva nota: \n";
    cin >> insert;
    insert = notas [pos + 1 ] 
}