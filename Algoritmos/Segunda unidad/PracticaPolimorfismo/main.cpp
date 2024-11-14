// Practica de polimorfismo
// Isaac Avila Saenz (238925)
// Ashley Paulina Dominguez Ruiz 225751

#include "Conjunto.cpp"
#include <iostream>

using namespace std;

void mostrarMenu();
bool print(int arreglo[], int tam, const char *cadena);
bool print(const char *arreglo);
bool Llenar(int *arreglo, unsigned int &tam);
bool Sumar(int *array1, int tam1, int *array2, int tam2, int *array3, unsigned int &tam3);
char *Sumar(char *cad1, char *cad2);
unsigned int menu();

int main()
{
    Conjunto Conj1, Conj2, Conj3;
    typeinfo elDato;
    unsigned int cantidad = 0, cantidad2 = 0, cantidad3 = 0, opcion;

    do
    {
        opcion = menu();
        switch (opcion)
        {
        case 1:
            // Operación de unión de conjuntos
            cout << "# de datos para Conj1: ";
            cin >> cantidad;
            for (unsigned int i = 0; i < cantidad; i++)
            {
                cout << "Teclee un valor entero: ";
                cin >> elDato;
                if (Conj1.AddElem(elDato))
                    cout << "Dato insertado!" << endl;
                else
                    cout << "Error!" << endl;
            }
            Conj1.Print();

            cout << "# de datos para Conj2: ";
            cin >> cantidad;
            for (unsigned int i = 0; i < cantidad; i++)
            {
                cout << "Teclee un valor entero: ";
                cin >> elDato;
                if (Conj2.AddElem(elDato))
                    cout << "Dato insertado!" << endl;
                else
                    cout << "Error!" << endl;
            }
            Conj2.Print();

            if (Sumar(Conj1, Conj2, Conj3))
            {
                cout << "*** Conjunto 1 ***" << endl;
                Conj1.Print();
                cout << "*** Conjunto 2 ***" << endl;
                Conj2.Print();
                cout << "*** Conjunto 3 (Unión) ***" << endl;
                Conj3.Print();
            }
            else
            {
                cout << "Error en la unión de conjuntos!" << endl;
            }
            break;

        case 2:
            // Suma de arreglos
            int array1[maxCard], array2[maxCard], array3[maxCard];
            cout << "Captura de datos para el arreglo 1." << endl;
            if (Llenar(array1, cantidad))
            {
                cout << "Datos capturados." << endl;
            }
            else
            {
                cout << "Excedido el límite de datos." << endl;
            }

            cout << "Captura de datos para el arreglo 2." << endl;
            if (Llenar(array2, cantidad2))
            {
                cout << "Datos capturados." << endl;
            }
            else
            {
                cout << "Excedido el límite de datos." << endl;
            }

            if (Sumar(array1, cantidad, array2, cantidad2, array3, cantidad3))
            {
                cout << "Total de datos generados en el arreglo 3: " << cantidad3 << endl;
                print(array1, cantidad, "Arreglo 1");
                print(array2, cantidad2, "Arreglo 2");
                print(array3, cantidad3, "Arreglo 3");
            }
            else
            {
                cout << "Error en la suma de arreglos!" << endl;
            }
            break;

        case 3:
            // Suma de cadenas (concatenación)
            char cad1[maxCard], cad2[maxCard];
            cout << "Teclee la primera cadena: ";
            cin >> cad1;
            cout << "Teclee la segunda cadena: ";
            cin >> cad2;
            if (Sumar(cad1, cad2) != NULL)
            {
                cout << "Cadena resultante: " << cad1 << endl;
            }
            else
            {
                cout << "Error en la concatenación!" << endl;
            }
            break;

        case 4:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opción no válida!" << endl;
            break;
        }
    } while (opcion != 4);

    return 0;
}

bool Llenar(int *arreglo, unsigned int &tam)
{
    cout << "¿Cuántos elementos desea agregar?: ";
    int elementos = 0;
    cin >> elementos;

    if (tam + elementos > maxCard)
        return false;

    for (int i = 0; i < elementos; i++)
    {
        cout << "Teclea un valor: ";
        cin >> *arreglo;
        tam++;
        arreglo++;
    }
    return true;
}

bool print(int arreglo[], int tam, const char *cadena)
{
    if (tam == 0)
        return false;

    cout << cadena << ": { ";
    for (int i = 0; i < tam; i++)
    {
        cout << arreglo[i] << " ";
    }
    cout << "}" << endl;

    return true;
}

bool print(const char *arreglo)
{
    if (!arreglo)
        return false;

    for (int i = 0; *(arreglo + i) != '\0'; i++)
        cout << *(arreglo + i);

    cout << endl;
    return true;
}

bool Sumar(int *array1, int tam1, int *array2, int tam2, int *array3, unsigned int &tam3)
{
    if (tam1 + tam2 > maxCard)
        return false;

    tam3 = 0;
    for (int i = 0; i < tam1; i++)
    {
        array3[tam3++] = array1[i];
    }

    for (int i = 0; i < tam2; i++)
    {
        bool exists = false;
        for (int j = 0; j < tam3; j++)
        {
            if (array2[i] == array3[j])
            {
                exists = true;
                break;
            }
        }
        if (!exists)
        {
            array3[tam3++] = array2[i];
        }
    }

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

unsigned int menu()
{
    unsigned int opcion;
    do
    {
        cout << "\nPolimorfismo: Sobrecarga de funciones" << endl;
        cout << "1) Suma de conjuntos (unión)" << endl;
        cout << "2) Suma de arreglos" << endl;
        cout << "3) Suma de cadenas (concatenación)" << endl;
        cout << "4) Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
    } while (opcion < 1 || opcion > 4);

    return opcion;
}
