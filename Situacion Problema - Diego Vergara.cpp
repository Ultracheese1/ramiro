#include <iostream>
#include <string>
#include <vector>
using namespace std;


// definicion de variables de la clase Empleado
class Empleado {
private:
    string nombre;
    double salarioBase;
    double bonos;
    double deducciones;

public:
    Empleado(string nom = "", double salario = 0.0, double bonus = 0.0, double deduc = 0.0);

    string getNombre();
    double getSalarioBase();
    double getBonos();
    double getDeducciones();

    void setNombre(string nom);
    void setSalarioBase(double salario);
    void setBonos(double bonus);
    void setDeducciones(double deduc);

    void muestraInformacion();
};

Empleado::Empleado(string nom, double salario, double bonus, double deduc)
    : nombre(nom), salarioBase(salario), bonos(bonus), deducciones(deduc) {}

string Empleado::getNombre() {
    return nombre;
}

double Empleado::getSalarioBase() {
    return salarioBase;
}

double Empleado::getBonos() {
    return bonos;
}

double Empleado::getDeducciones() {
    return deducciones;
}

void Empleado::setNombre(string nom) {
    nombre = nom;
}

void Empleado::setSalarioBase(double salario) {
    salarioBase = salario;
}

void Empleado::setBonos(double bonus) {
    bonos = bonus;
}

void Empleado::setDeducciones(double deduc) {
    deducciones = deduc;
}

void Empleado::muestraInformacion() {
    cout << "Nombre: " << nombre << endl;
    cout << "Salario Base: " << salarioBase << endl;
    cout << "Bonos: " << bonos << endl;
    cout << "Deducciones: " << deducciones << endl;
}

int main() {
    // Implementa aquí tu sistema de seguridad para ingresar al sistema
    // Puedes utilizar contraseñas, autenticación biométrica, etc.

    int MAX_EMPLEADOS = 0;
    cout << "¿Cuántos empleados desea registrar?" << endl;
    cin >> MAX_EMPLEADOS;

    // vector para incluir empleados
    vector<Empleado> empleados;

	// ingresar datos de todos los empleados
    for (int i = 0; i < MAX_EMPLEADOS; ++i) {
        string nom;
        double salarioBase, bonos, deducciones;

        cout << "Nombre del empleado: ";
        cin >> nom;
        cout << "Salario Base: ";
        cin >> salarioBase;
        cout << "Bonos: ";
        cin >> bonos;
        cout << "Deducciones: ";
        cin >> deducciones;

        Empleado nuevoEmpleado(nom, salarioBase, bonos, deducciones);
        empleados.push_back(nuevoEmpleado);
    }

    char opcion;
    do {
    	cout << "		Menú de opciones \n";
        cout << "  a) Agregar empleado \n  b) Consultar  \n  c) Modificar \n  d) Eliminar \n  e) Salarios \n  f) Salir \n ";
        cout << "Ingrese la acción deseada:";
        cin >> opcion;

        switch (opcion) {
        	
            // agregar un nuevo empleado
            case 'a': {
                string nom;
                double salarioBase, bonos, deducciones;

                cout << "Nombre del empleado: ";
                cin >> nom;
                cout << "Salario Base: ";
                cin >> salarioBase;
                cout << "Bonos: ";
                cin >> bonos;
                cout << "Deducciones: ";
                cin >> deducciones;

                Empleado nuevoEmpleado(nom, salarioBase, bonos, deducciones);
                empleados.push_back(nuevoEmpleado);

                break;
            }

            // consultar informacion
            case 'b': {
                char consulta;
                cout << "a) Consulta individual b) Consulta completa: ";
                cin >> consulta;
				
				// consulta individual
                if (consulta == 'a') {
                    int index;
                    cout << "Ingrese el índice del empleado: ";
                    cin >> index;

                    if (index >= 0 && index < empleados.size()) {
                        empleados[index].muestraInformacion();
                    } else {
                        cout << "Índice de empleado no válido." << endl;
                    }
                
                // consulta completa (mostrar los datos de todos los empleados)
                } else if (consulta == 'b') {
                    for (int i = 0; i < empleados.size(); ++i) {
                        cout << "Empleado " << i << ":" << endl;
                        empleados[i].muestraInformacion();
                    }
                } else {
                    cout << "Opción no válida." << endl;
                }

                break;
            }

            // modificar informacion (solo nombre porque la demas info va en salario)
            case 'c': {
                int index;
                cout << "Ingrese el índice del empleado a modificar: ";
                cin >> index;

                if (index >= 0 && index < empleados.size()) {
                    string nom;

                    cout << "Nuevo nombre del empleado: ";
                    cin >> nom;

                    empleados[index].setNombre(nom);
                } else {
                    cout << "Índice de empleado no válido." << endl;
                }

                break;
            }

            // eliminar empleado
            case 'd': {
                int index;
                cout << "Ingrese el índice del empleado a eliminar: ";
                cin >> index;

                if (index >= 0 && index < empleados.size()) {
                    empleados.erase(empleados.begin() + index);
                    cout << "Empleado eliminado correctamente." << endl;
                } else {
                    cout << "Índice de empleado no válido." << endl;
                }

                break;
            }

            // actualizar salarios (base, bonos, deducciones)
            case 'e': {
                int index;
                cout << "Ingrese el índice del empleado: ";
                cin >> index;

                if (index >= 0 && index < empleados.size()) {
                    double nuevoSalarioBase, bonos, deducciones;

                    cout << "Nuevo salario base: ";
                    cin >> nuevoSalarioBase;
                    cout << "Nuevos bonos: ";
                    cin >> bonos;
                    cout << "Nuevas deducciones: ";
                    cin >> deducciones;

                    empleados[index].setBonos(bonos);
                    empleados[index].setDeducciones(deducciones);
                    empleados[index].setSalarioBase(nuevoSalarioBase);
                } else {
                    cout << "Índice de empleado no válido." << endl;
                }

                break;
            }
        }
    } while (opcion != 'f');

    return 0;
}

