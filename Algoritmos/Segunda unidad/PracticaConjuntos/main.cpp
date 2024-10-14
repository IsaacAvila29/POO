#include "Conjunto.cpp"
#include <bits/stdc++.h>

using namespace std;

Conjunto conj1, conj2, conj3; // Declaración de tres conjuntos

void Menu();
int SubMenu();
int main()
{
    setlocale(LC_ALL, "");

    typeinfo elDato;             // Variable para almacenar datos
    unsigned short int cantidad; // Cantidad de datos a ingresar

    // Inserción de elementos en el primer conjunto
    cout << "Teclea la cantidad de datos que va a tener el conjunto 1: ";
    cin >> cantidad;

    for (int i = 0; i < cantidad; i++)
    {
        cout << "Teclea un valor: ";
        cin >> elDato;

        if (conj1 + elDato)
            cout << "Dato insertado en conjunto 1." << endl;
        else
            cout << "Error: Dato no se pudo insertar en conjunto 1." << endl;
    }

    // Inserción de elementos en el segundo conjunto
    cout << "Teclea la cantidad de datos que va a tener el conjunto 2: ";
    cin >> cantidad;

    for (int i = 0; i < cantidad; i++)
    {
        cout << "Teclea un valor: ";
        cin >> elDato;

        if (conj2 + elDato)
            cout << "Dato insertado en conjunto 2." << endl;
        else
            cout << "Error: Dato no se pudo insertar en conjunto 2." << endl;
    }

    // Imprimir los conjuntos
    cout << "Conjunto 1: ";
    conj1.Print();
    cout << "Conjunto 2: ";
    conj2.Print();

    conj3 = conj1 | conj2;

    // Imprimir el conjunto resultante de la unión
    cout << "Conjunto union: ";
    conj3.Print();
    Menu();

    // Prueba de eliminación de un elemento del conjunto 1
    // cout << "Teclea un valor a eliminar de conjunto 1: ";
    // cin >> elDato;

    // if (conj1 - elDato)
    // {
    //     cout << "Dato " << elDato << " eliminado de conjunto 1." << endl;
    // }
    // else
    // {
    //     cout << "Error: Dato no encontrado en conjunto 1." << endl;
    // }

    // // Imprimir el conjunto actualizado
    // cout << "Conjunto 1 actualizado: ";
    // conj1.Print();
    return 0;
}

void Menu()
{
    setlocale(LC_ALL, "");

    cout << endl
         << "*************************************************" << endl
         << "Bienvenido al menú, seleccione que desea hacer" << endl;
    cout << "Presione 1 para agregar un elemento a un conjunto" << endl;
    cout << "Presione 2 para eliminar un elemento a un conjunto " << endl;
    cout << "Presione 3 para unir los conjunots 1 y 2 " << endl;
    cout << "Presione 4 para verificar si un numero esta dentro de un conjunto " << endl;
    cout << "*************************************************";
    cout << endl
         << "Seleccione su respuesta:    " << endl;

    unsigned int seleccion1, seleccion2;
    cin >> seleccion1;

    switch (seleccion1)
    {
    case 1:
        cout << "Ha seleccionado agregar un elemento " << endl;

        cout << "Seleccione el conjunto que desea modificar ";
        cin >> seleccion2;

        while (seleccion2 == 1 || seleccion2 == 2)
        {
            if (seleccion2 == 1)
            {
                typeinfo elDato;
                // Inserción de elementos en el primer conjunto

                cout << "Teclea un valor para el conjunto 1: ";
                cin >> elDato;

                if (conj1 + elDato)
                    cout << "Dato insertado en conjunto 1." << endl;
                else
                    cout << "Error: Dato no se pudo insertar en conjunto 1." << endl;

                cout << "El conjunto 1 ";
                conj1.Print();

                cout << endl
                     << "¿Que desea hacer? " << endl
                     << "Presione 1 para modificar el primer conjunto" << endl
                     << "Presione 2 para modificar el segundo conjunto, o presione 0 para salir  ";

                cin >> seleccion2;
            }

            if (seleccion2 == 2)
            {
                typeinfo elDato;

                cout << "Teclea un valor para el conjunto 2: ";

                cin >> elDato;

                if (conj2 + elDato)
                    cout << "Dato insertado en conjunto 2." << endl;
                else
                    cout << "Error: Dato no se pudo insertar en conjunto 1." << endl;

                cout << "El conjunto 2 ";
                conj2.Print();

                cout << endl
                     << "¿Que desea hacer? " << endl
                     << "Presione 1 para modificar el primer conjunto" << endl
                     << "Presione 2 para modificar el segundo conjunto, o presione 0 para salir  ";

                cin >> seleccion2;
            }
        }
        Menu();
        break;
    case 2: // Esto es para eliminar elementos
        cout << "Ha seleccionado remover un elemento " << endl;

        cout << "Seleccione el conjunto que desea modificar ";
        cin >> seleccion2;

        while (seleccion2 == 1 || seleccion2 == 2)
        {
            if (seleccion2 == 1)
            {
                typeinfo elDato;
                cout << "Estos son los elementos del conjunto 1 ";
                conj1.Print();

                cout << endl
                     << "Teclea un valor para el conjunto 1: ";
                cin >> elDato;

                if (conj1 - elDato)
                    cout << "Dato eliminado en conjunto 1." << endl;
                else
                    cout << "Error: Dato no se pudo eliminar en conjunto 1." << endl;

                cout << "El conjunto 1 ";
                conj1.Print();

                cout << endl
                     << "¿Que desea hacer? " << endl
                     << "Presione 1 para modificar el primer conjunto" << endl
                     << "Presione 2 para modificar el segundo conjunto, o presione 0 para salir  ";

                cin >> seleccion2;
            }

            if (seleccion2 == 2)
            {
                typeinfo elDato;
                cout << "Estos son los elementos del conjunto 2 ";
                conj2.Print();

                cout << "Teclea un valor para el conjunto 2: ";

                cin >> elDato;

                if (conj2 - elDato)
                    cout << "Dato eliminado en conjunto 2." << endl;
                else
                    cout << "Error: Dato no se pudo insertar en conjunto 1." << endl;

                cout << "El conjunto 2 ";
                conj2.Print();

                cout << endl
                     << "¿Que desea hacer? " << endl
                     << "Presione 1 para modificar el primer conjunto" << endl
                     << "Presione 2 para modificar el segundo conjunto, o presione 0 para salir  ";

                cin >> seleccion2;
            }
        }
        Menu();
        break;

    case 3: // Este es para unir los conjuntos 1 y 2
        cout << "Ha seleccionado, unir los conjuntos 1 y 2 " << endl;

        conj3 = conj1 | conj2;

        // Imprimir el conjunto resultante de la unión
        cout << "Conjunto union: ";
        conj3.Print();
        Menu();
        break;

    case 4: // Este es para ver si un elemento existe dentro de algun conjunto

        cout << "Ha seleccionado verificar si un elemento esta dentro de un conjunto " << endl;
        cout << "Seleccione el conjunto que desea comprobar: ";
        cin >> seleccion2;
        while (seleccion2 == 1 || seleccion2 == 2)
        {
            if (seleccion2 == 1)
            {
                cout << "Ha seleccionado conjunto 1 " << endl
                     << "escriba cual numero desea comprobar: ";

                typeinfo elDato;
                cin >> elDato;
                if (conj1 & elDato)

                    cout << endl
                         << "El numero " << elDato << " SI esta en el conjunto 1" << endl;

                else

                    cout << endl
                         << "El numero " << elDato << " NO esta en el conjunto 1" << endl;

                cout << endl
                     << "¿Que desea hacer? " << endl
                     << "Presione 1 para verificar el primer conjunto" << endl
                     << "Presione 2 para verificar el segundo conjunto, o presione 0 para salir  ";

                cin >> seleccion2;
            }

            if (seleccion2 == 2)
            {
                cout << "Ha seleccionado conjunto 1 " << endl
                     << "escriba cual numero desea comprobar: ";

                typeinfo elDato;
                cin >> elDato;

                if (conj2 & elDato)

                    cout << "El numero " << elDato << " SI esta en el conjunto 2";

                else

                    cout << "El numero " << elDato << " NO esta en el conjunto 2";

                cout << endl
                     << "¿Que desea hacer? " << endl
                     << "Presione 1 para verificar el primer conjunto" << endl
                     << "Presione 2 para verificar el segundo conjunto, o presione 0 para salir  ";

                cin >> seleccion2;
            }
        }

        Menu();
        break;
    default:
        break;
    }
}
