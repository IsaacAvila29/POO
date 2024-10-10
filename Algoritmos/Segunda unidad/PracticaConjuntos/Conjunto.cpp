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

inline bool operator+(Conjunto Conj, typeinfo dato)
{
    if ((Conj.card == maxCard) || (Conj & dato))
        return false;

    Conj.elementos[Conj.card] = dato; // Asigna el dato al array
    // card++;                           // Incrementa card después de la asignación

    return true; // Asegúrate de devolver true si se añade el elemento
}

inline bool Conjunto::RmvElem(typeinfo dato)
{
    for (int i = 0; i < card; i++)
    {
        if (elementos[i] == dato)
        {
            elementos[i] = elementos[card - 1];
            card--;
            return true;
        }
    }
    return false;
}

inline void Conjunto::Print()
{
    cout << "{  ";

    for (int i = 0; i < card - 1; i++)
    {
        std::cout << elementos[i] << ", ";

        if (!card)
            cout << "} ";
        else
            cout << elementos[card] << "} ";
    }
}

inline bool Conjunto::Union(Conjunto conj2, Conjunto &conj3)
{
    conj3.card = 0;
    for (int i = 0; i < card; i++) // se deja que es el objeto implicito
        conj3.AddElem(elementos[i]);

    for (int i = 0; i < conj2.card; i++)
    {
        if (conj3.card == maxCard)
            return false;
        else
            conj3.AddElem(conj2.elementos[i]);
    }
}
