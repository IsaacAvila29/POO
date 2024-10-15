#include "Conjunto.h"
#include <iostream>
using namespace std;

inline bool Conjunto::Member(typeinfo dato)
{
    for (int i = 0; i < card; i++)
    {
        if (elementos[i] == dato)
        {
            return true;
        }
    }
    return false;
}

inline bool Conjunto::AddElem(typeinfo dato)
{
    if ((card == maxCard) || Member(dato))
        return false;

    elementos[card] = dato; // Asigna el dato al array
    card++;                 // Incrementa card después de la asignación

    return true; // Retorna true si se añadió el elemento correctamente
}

inline bool Conjunto::RmvElem(typeinfo dato)
{
    for (int i = 0; i < card; i++)
    {
        if (elementos[i] == dato)
        {
            elementos[i] = elementos[card - 1];
            card--; // Decrementa el número de elementos
            return true;
        }
    }
    return false; // Retorna false si no encontró el elemento
}

inline void Conjunto::Print()
{
    cout << "{ ";
    for (int i = 0; i < card; i++)
    {
        cout << elementos[i];
        if (i < card - 1)
            cout << ", ";
    }
    cout << " }" << endl; // Imprime los elementos entre llaves
}

inline bool Conjunto::Union(Conjunto conj2, Conjunto &conj3)
{
    conj3.card = 0; // Reinicia el card de conj3 para asegurarte de que esté vacío

    // Agrega elementos del conjunto actual (this)
    for (int i = 0; i < card; i++)
    {
        conj3.AddElem(elementos[i]);
    }

    // Agrega elementos de conj2
    for (int i = 0; i < conj2.card; i++)
    {

        if (conj3.card == maxCard)
        {
            cout << "Por alguna razon, se alcanzo la maxima card";
            return false;
        }
        else
        {
            conj3.AddElem(conj2.elementos[i]);
        }
    }

    return true; // Retorna true al final
}
