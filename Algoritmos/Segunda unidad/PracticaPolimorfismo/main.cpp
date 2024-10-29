// Practica de pilimorfismo
// Isaac Avila Saenz (238925)
// Ashley Paulina Dominguez Ruiz 225751
#include "Conjunto.cpp"
#include <iostream>
using namespace std;

void mostrarMenu();
bool print(int arreglo[], int tam, char *);
bool print(char *arreglo);
bool Llenar(int arreglo[], unsigned int &tam);                                   //
bool Sumar(int *array1, int tam1, int *array2, int tam2, int *array3, int tam3); //
char *Sumar(char *cad1, char *cad2);

int main()
{
    Conjunto Conj1, Conj2, Conj3;
    typeinfo elDato;
    unsigned int cantidad, cantidad2, cantidad3;
    cout << "# datos Conj1: ";
    cin >> cantidad;
    for (int i = 0; i < cantidad; i++)
    {
        cout << "Teclee un valor entero: ";
        cin >> elDato;
        if (Conj1.AddElem(elDato))
            cout << "Dato insertado!" << endl;
        else
            cout << "Error!" << endl;
    }
    Conj1.Print();
    // -----------------------------
    cout << "# datos Conj2: ";
    cin >> cantidad;
    for (int i = 0; i < cantidad; i++)
    {
        cout << "Teclee un valor entero: ";
        cin >> elDato;
        if (Conj2.AddElem(elDato))
            cout << "Dato insertado!" << endl;
        else
            cout << "Error!" << endl;
    }
    Conj2.Print();

    // la funcion sumar no repite datos
    if (Sumar(Conj1, Conj2, Conj3))
    {
        cout << "***Conjunto 1***" << endl;
        Conj1.Print();
        cout << "***Conjunto 2***" << endl;
        Conj2.Print();
        cout << "***Conjunto 3***" << endl;
        Conj3.Print();
    }
    else
        cout << ", error en union!!" << endl;

    ///////////////////////////////////

    cout << "Numero de datos del arreglo 1 ";

    int array1[maxCard], array2[maxCard], array3[maxCard];

    if (Llenar(array1, cantidad))
        cout << "Datos capturados " << endl;
    else
        cout << "Excedidio el limite de datos" << endl;

    if (Llenar(array2, cantidad2))
        cout << "Datos capturados " << endl;
    else
        cout << "Excedidio el limite de datos" << endl;
    cout << "Hello world!" << endl;

    if (Sumar(array1, cantidad, array2, cantidad2, array3, cantidad3))
    {
        cout << "Total de datos generados: " << cantidad2 << endl;

        if (print(array1, cantidad, "Arreglo1"))
        {
            if (print(array2, cantidad2, "Arreglo2"))
            {
                if (print(array3, cantidad3, "Arreglo3"))
                {
                }
            }
        }

        else
            cout << "Error de impresion" << endl;
    }

    return 0;
}

// Main con menu

// int main()
// {
//     Conjunto conj1, conj2, conj3; // Declaración de conjuntos
//     unsigned short int cantidad;
//     typeinfo elDato;
//     int opcion, conjuntoSeleccionado;

//     do
//     {
//         mostrarMenu(); // Muestra el menú de opciones
//         cout << "Seleccione una opción: ";
//         cin >> opcion;

//         switch (opcion)
//         {
//         case 1: // Agregar elementos a un conjunto
//             cout << "Seleccione el conjunto (1 o 2): ";
//             cin >> conjuntoSeleccionado;

//             if (conjuntoSeleccionado == 1 || conjuntoSeleccionado == 2)
//             {
//                 cout << "¿Cuántos elementos desea agregar?: ";
//                 cin >> cantidad;

//                 for (int i = 0; i < cantidad; i++)
//                 {
//                     cout << "Teclea un valor: ";
//                     cin >> elDato;

//                     if ((conjuntoSeleccionado == 1 ? conj1 : conj2).AddElem(elDato))
//                         cout << "Dato insertado correctamente." << endl;
//                     else
//                         cout << "Error: No se pudo insertar el dato." << endl;
//                 }
//             }
//             else
//             {
//                 cout << "Selección inválida." << endl;
//             }
//             break;

//         case 2: // Eliminar un elemento de un conjunto
//             cout << "Seleccione el conjunto (1 o 2): ";
//             cin >> conjuntoSeleccionado;

//             if (conjuntoSeleccionado == 1 || conjuntoSeleccionado == 2)
//             {
//                 cout << "Teclea el valor a eliminar: ";
//                 cin >> elDato;

//                 if ((conjuntoSeleccionado == 1 ? conj1 : conj2).RmvElem(elDato))
//                     cout << "Dato eliminado correctamente." << endl;
//                 else
//                     cout << "Error: El dato no se encontró en el conjunto." << endl;
//             }
//             else
//             {
//                 cout << "Selección inválida." << endl;
//             }
//             break;

//         case 3: // Realizar la unión de los dos conjuntos
//             if (Sumar(conj1, conj2, conj3))
//                 cout << "Unión realizada con éxito." << endl;
//             else
//                 cout << "Error: No se pudo realizar la unión." << endl;

//             cout << "Conjunto resultante de la unión: ";
//             conj3.Print();
//             break;

//         case 4: // Imprimir los conjuntos
//             cout << "Conjunto 1: ";
//             conj1.Print();
//             cout << "Conjunto 2: ";
//             conj2.Print();
//             break;

//         case 0: // Salir
//             cout << "Saliendo del programa." << endl;
//             break;

//         default:
//             cout << "Opción inválida. Intente de nuevo." << endl;
//         }
//     } while (opcion != 0); // El menú se repite hasta que se elija la opción 0

//     return 0;
// }

void mostrarMenu()
{
    cout << "\n--- MENÚ DE OPCIONES ---" << endl;
    cout << "1. Agregar elementos a un conjunto" << endl;
    cout << "2. Eliminar un elemento de un conjunto" << endl;
    cout << "3. Realizar la unión de los conjuntos 1 y 2" << endl;
    cout << "4. Imprimir los conjuntos" << endl;
    cout << "0. Salir" << endl;
}

bool Llenar(int arreglo[], int &tam)
{

    cout << "¿Cuántos elementos desea agregar?: ";
    int cantidad = 0, dato;
    cin >> cantidad;

    if (tam + cantidad > maxCard)
        return false;

    for (int i = 0; i < cantidad; i++)
    {
        cout << "Teclea un valor: ";
        cin >> arreglo[tam++];
        cout << "OK " << endl;
    }
    return true;
}

bool print(int arreglo[], int tam, char *cadena)

{
    cout << "{ ";
    if (!tam)
        return false;

    cout << cadena;
    for (int i = 0; i < tam; i++)
    {
        cout << arreglo[i] << " ";
    }
    cout << " }" << endl; // Imprime los elementos entre llaves

    return true;
}

bool print(char *arreglo)
{
    if (!arreglo)
        return false; // Si el puntero vale nulo

    for (int i = 0; *(arreglo + i) != '\0'; i++)
        cout << *(arreglo + i);

    return true;
}

bool Sumar(int *array1, int tam1, int *array2, int tam2, int *array3, int &tam3)
{

    if (tam1 + tam2 > maxCard)
        return false;

    tam3 = 0;
    for (int i = 0; i < tam1; i++)
    {
        *(array3 + i) = array1[i];
        tam3++;
    }

    for (int i = 0; i < tam2; i++)
    {
        array3[tam3] = *(array1 + i);
        tam3++;
    }

    cout << "elementos del arreglo 3" << tam3 << endl;
    return true;
}

char *Sumar(char *cad1, char *cad2)
{
    int i;
    for (i = 0; *(cad1 + i) != '\0'; i++)
        ;

    for (int j = 0; *(cad2 + j) != '\0'; j++)
    {
        if (i == maxCard)
            return NULL;
        *(cad1 + i) = *(cad2 + j);
        i++;
    }
    *(cad1 + i) = '\0';

    return cad1;
}
