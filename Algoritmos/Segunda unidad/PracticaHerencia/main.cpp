#include <bits/stdc++.h>
#define maxCard 10;
typedef int typeinfo;

using namespace std;

class Nodo
{

private:
    typeinfo dato;
    Nodo *Siguiente;
    Nodo(typeinfo Dato, Nodo *Siguiente) : dato(Dato), Siguiente(Siguiente) {};
};

class Lista
{

private:
    Nodo *inicio;

public:
    bool Member(typeinfo);
    bool Insert(typeinfo); // Se redefinira insert para conjunto
    virtual bool Insert(typeinfo);
    virtual bool Delete(typeinfo);
    Nodo *Buscar(typeinfo);
    bool print();
    ~Lista();
};

int main(void)
{
    cout << "Hello" << endl;
}