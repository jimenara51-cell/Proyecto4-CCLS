#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Estructura que representa una tarea
struct Tarea {
    string prioridad;
    string descripcion;
    bool completada;
};

// Protoripos
void agregarTarea(vector<Tarea>& tareas);
void mostrarTareas(const vector<Tarea>& tareas);
void completarTarea(vector<Tarea>& tareas);

int main() {
    vector<Tarea> tareas;
    int opcion;

    while (opcion != 4) {
        cout << "\nLISTA DE TAREAS\n\n";
        cout << "1. Agregar tarea\n";
        cout << "2. Mostrar tareas\n";
        cout << "3. Marcar tarea como completada\n";
        cout << "4. Salir\n\n";
        cout << "Seleccione una opción: ";

        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                agregarTarea(tareas);
                break;
            case 2:
                mostrarTareas(tareas);
                break;
            case 3:
                completarTarea(tareas);
                break;
            case 4:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción no válida.\n";
                break;
        }
    }

    return 0;
}

// Agrega una nueva tarea al vector
void agregarTarea(vector<Tarea>& tareas) {
    Tarea nueva;
    // nombre y tipo de variable
    
    cout << "Ingrese la informacion de la tarea: ";
    getline(cin, nueva.descripcion);
    
    if (nueva.descripcion == ""){
        cout << "La tarea no puede estar vacia.";
        return;
    }
    
    cout << "Ingrese la prioridad: ";
    getline(cin, nueva.prioridad);
    
    nueva.completada = false;
    
    tareas.push_back(nueva);
    cout << "Nueva tarea aniadida correctamente." << endl;
}

// Muestra todas las tareas

void mostrarTareas(const vector<Tarea>& tareas) {
    cout << "\nTAREAS\n\n";
    
    for (int i=0; i < tareas.size(); i++){
        // Numero. [Estado] [Prioridad] Descripcion 
        cout << i + 1 << ". ";
        
        if (tareas[i].completada == true){
            cout << "[Completada] ";
        } else {
            cout << "[Pendiente] ";
        }
        cout << "[" << tareas[i].prioridad << "] ";
        cout << tareas[i].descripcion << endl;
        
    }

}


// Marca una tarea como completada
void completarTarea(vector<Tarea>& tareas) {
    // Imprimir tareas
    mostrarTareas(tareas);
    
    // cambiar tarea. completada a true
    // numero tarea completada
    int numeroTarea;
    cout << "Seleccione la tarea completada";
    cin >> numeroTarea;
    
    if (numeroTarea < 1 or numeroTarea > tareas.size()){
        cout << "Tarea invalida" << endl; 
        return;
    }
    
    tareas[numeroTarea - 1].completada = true;
    cout << "Tarea completada correctamente: " << endl;
    
}

