#include "Conjunto.cpp"
#include <bits/stdc++.h>

using namespace std;

Conjunto conj1, conj2, conj3; // Declaración de tres conjuntos

void Menu();
void MensajeGenerico(int codigo);
string errorGenerico(int codigo);

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
    cout << "Presione 5 salir del programa " << endl;
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
        if (seleccion2 > 2 || seleccion2 == 0)
        {
            cout << errorGenerico(1);
        }

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

                MensajeGenerico(0);

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

                MensajeGenerico(0);

                cin >> seleccion2;
            }
        }
        Menu();
        break;
    case 2: // Esto es para eliminar elementos
        cout << "Ha seleccionado remover un elemento " << endl;

        cout << "Seleccione el conjunto que desea modificar ";
        cin >> seleccion2;
        if (seleccion2 > 2 || seleccion2 == 0)
        {
            cout << errorGenerico(1);
        }
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

                MensajeGenerico(0);

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

                MensajeGenerico(0);

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
        if (seleccion2 > 3 || seleccion2 == 0)
        {
            cout << errorGenerico(1);
        }
        while (seleccion2 == 1 || seleccion2 == 2 || seleccion2 == 3)
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

                MensajeGenerico(1);

                cin >> seleccion2;
            }

            if (seleccion2 == 2)
            {
                cout << "Ha seleccionado conjunto 2 " << endl
                     << "escriba cual numero desea comprobar: ";

                typeinfo elDato;
                cin >> elDato;

                if (conj2 & elDato)
                    cout << "El numero " << elDato << " SI esta en el conjunto 2";

                else
                    cout << "El numero " << elDato << " NO esta en el conjunto 2";

                MensajeGenerico(1);
                cin >> seleccion2;
            }
            if (seleccion2 == 3)
            {
                cout << "Ha seleccionado conjunto 3 " << endl
                     << "escriba cual numero desea comprobar: ";

                typeinfo elDato;
                cin >> elDato;

                if (conj3 & elDato)
                    cout << "El numero " << elDato << " SI esta en el conjunto union";

                else
                    cout << "El numero " << elDato << " NO esta en el conjunto union";

                MensajeGenerico(1);
                cin >> seleccion2;
            }
        }
        Menu();
        break;
    case 5:
        cout << "HASTA LUEGO";
        break;
    default:
        cout << errorGenerico(2);
        Menu();
        break;
    }
}

void MensajeGenerico(int codigo)
{
    if (codigo == 0)
    {
        cout << endl
             << "¿Que desea hacer? " << endl
             << "Presione 1 para trabajar el primer conjunto" << endl
             << "Presione 2 para trabajar el segundo conjunto, o presione cualquier tecla para volver al menu ";
    }
    else if (codigo == 1)
    {
        cout << endl
             << "¿Que desea hacer? " << endl
             << "Presione 1 para trabajar el primer conjunto" << endl
             << "Presione 2 para trabajar el segundo conjunto" << endl
             << "Presione 3 para trabajar con el conjunto union o presione cualquier tecla para volver al menu ";
    }
}

string errorGenerico(int codigo)
{
    switch (codigo)
    {
    case 1:
        return "ERROR, EL CONJUNTO SELECCIONADO NO ES UN CONJUNTO VALIDO, VOLVIENDO AL MENU";
        break;
    case 2:
        return "ERROR, ESA NO ES UNA SELECCION VALIDA";
        break;
    default:
        break;
    }
}