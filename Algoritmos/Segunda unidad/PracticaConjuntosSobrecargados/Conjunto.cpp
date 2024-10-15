#include "Conjunto.h"
#include <iostream>
using namespace std;
inline bool operator&(Conjunto Conj, typeinfo dato) // Este antes era member
{
    for (int i = 0; i < Conj.card; i++)
    {
        if (Conj.elementos[i] == dato)
        {
            return true;
        }
    }
    return false;
}

inline bool operator+(Conjunto &Conj, typeinfo dato) // AddElem
{
    if ((Conj.card == maxCard) || (Conj & dato)) // Usar la sobrecarga del operador &
        return false;

    Conj.elementos[Conj.card] = dato; // Asigna el dato al array
    Conj.card++;                      // Incrementa card después de la asignación

    return true; // Asegúrate de devolver true si se añade el elemento
}

inline bool operator-(Conjunto &Conj, typeinfo dato) // Rmv Element
{
    for (int i = 0; i < Conj.card; i++)
    {
        if (Conj.elementos[i] == dato)
        {
            Conj.elementos[i] = Conj.elementos[Conj.card - 1];
            Conj.card--;
            return true;
        }
    }
    return false;
}

inline void Conjunto::Print()
{
    cout << "{ ";

    for (int i = 0; i < card; i++) // Imprime todos los elementos
    {
        cout << elementos[i];
        if (i < card - 1) // Agrega una coma solo si no es el último elemento
            cout << ", ";
    }
    cout << " }" << endl; // Imprime la llave de cierre y el salto de línea
}

// Sobrecarga del operador | para unir dos conjuntos
inline Conjunto operator|(Conjunto &Conj1, Conjunto &Conj2)
{
    Conjunto conj3; // Conjunto resultante de la unión

    // Agregar todos los elementos de Conj1
    for (int i = 0; i < Conj1.card; i++)
    {
        conj3 + Conj1.elementos[i]; // Usamos la sobrecarga del operador +
    }

    // Agregar los elementos de Conj2, evitando duplicados
    for (int i = 0; i < Conj2.card; i++)
    {
        conj3 + Conj2.elementos[i]; // Solo agrega si no están ya en conj3
    }

    return conj3; // Retornamos el conjunto resultante
}
