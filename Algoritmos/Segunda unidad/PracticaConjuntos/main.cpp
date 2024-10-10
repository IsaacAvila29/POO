#include <bits/stdc++.h>
// #include "PracticaConjuntos\Conjunto.cpp"
#include "Conjunto.cpp"

using namespace std;
typedef int typeinfo;
unsigned short int cantidad;

int main()
{
    Conjunto conj1, conj2, conj3;
    typeinfo elDato;
    if (conj1 & 100)
    {
        cout << "Encontrado;";
    }
    else
    {
        cout << "No encontrado";
    }
    cout << "Teclea la cantidad de datos que va a tener el conjunto";
    cin >> cantidad;
    for (int i = 0; i < 13; i++)
    {

        cout << "Teclea un valor: ";
        cin >> elDato;

        if (conj1 + elDato)
            cout << "Dato insertado" << endl;
        else
            cout << "Error" << endl;
    }
    cout << "Hello Wordl";

    // if (conj1.Member(elDato))
    //     cout << "Existe";

    // else
    //     cout << "No exit¿ste";

    if (conj1.RmvElem(elDato))
        cout << "Removido";
    return 0;
    conj1.Print();
}
// Comentario
//  Implementar un menu de opciones con las siguientes opciones
/*
1.Insertar
2.Remover
4:Revisar
5.Salir

Con un sibmenu
1.Conj1
2.Conj2
3.Regresar al menu anterior
*/