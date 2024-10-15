// Practica de conjuntos
// Isaac Avila Saenz (238925)
// Ashley Paulina Dominguez Ruiz 225751
#include "Conjunto.cpp"
#include <iostream>
using namespace std;

void mostrarMenu();

int main()
{
    Conjunto conj1, conj2, conj3; // Declaración de conjuntos
    unsigned short int cantidad;
    typeinfo elDato;
    int opcion, conjuntoSeleccionado;

    do
    {
        mostrarMenu(); // Muestra el menú de opciones
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1: // Agregar elementos a un conjunto
            cout << "Seleccione el conjunto (1 o 2): ";
            cin >> conjuntoSeleccionado;

            if (conjuntoSeleccionado == 1 || conjuntoSeleccionado == 2)
            {
                cout << "¿Cuántos elementos desea agregar?: ";
                cin >> cantidad;

                for (int i = 0; i < cantidad; i++)
                {
                    cout << "Teclea un valor: ";
                    cin >> elDato;

                    if ((conjuntoSeleccionado == 1 ? conj1 : conj2).AddElem(elDato))
                        cout << "Dato insertado correctamente." << endl;
                    else
                        cout << "Error: No se pudo insertar el dato." << endl;
                }
            }
            else
            {
                cout << "Selección inválida." << endl;
            }
            break;

        case 2: // Eliminar un elemento de un conjunto
            cout << "Seleccione el conjunto (1 o 2): ";
            cin >> conjuntoSeleccionado;

            if (conjuntoSeleccionado == 1 || conjuntoSeleccionado == 2)
            {
                cout << "Teclea el valor a eliminar: ";
                cin >> elDato;

                if ((conjuntoSeleccionado == 1 ? conj1 : conj2).RmvElem(elDato))
                    cout << "Dato eliminado correctamente." << endl;
                else
                    cout << "Error: El dato no se encontró en el conjunto." << endl;
            }
            else
            {
                cout << "Selección inválida." << endl;
            }
            break;

        case 3: // Realizar la unión de los dos conjuntos
            if (conj1.Union(conj2, conj3))
                cout << "Unión realizada con éxito." << endl;
            else
                cout << "Error: No se pudo realizar la unión." << endl;

            cout << "Conjunto resultante de la unión: ";
            conj3.Print();
            break;

        case 4: // Imprimir los conjuntos
            cout << "Conjunto 1: ";
            conj1.Print();
            cout << "Conjunto 2: ";
            conj2.Print();
            break;

        case 0: // Salir
            cout << "Saliendo del programa." << endl;
            break;

        default:
            cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while (opcion != 0); // El menú se repite hasta que se elija la opción 0

    return 0;
}

void mostrarMenu()
{
    cout << "\n--- MENÚ DE OPCIONES ---" << endl;
    cout << "1. Agregar elementos a un conjunto" << endl;
    cout << "2. Eliminar un elemento de un conjunto" << endl;
    cout << "3. Realizar la unión de los conjuntos 1 y 2" << endl;
    cout << "4. Imprimir los conjuntos" << endl;
    cout << "0. Salir" << endl;
}
