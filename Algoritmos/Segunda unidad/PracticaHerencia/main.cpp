#include <iostream>
#define maxCard 10
typedef int typeinfo;

using namespace std;

// Clase Nodo que representa un nodo en la lista enlazada
class Nodo
{
public:
    typeinfo dato;   // Valor almacenado en el nodo
    Nodo *Siguiente; // Puntero al siguiente nodo

    // Constructor del nodo
    Nodo(typeinfo Dato, Nodo *Siguiente = nullptr) : dato(Dato), Siguiente(Siguiente) {}
};

// Clase Lista que representa una lista enlazada
class Lista
{
protected:
    Nodo *inicio; // Puntero al primer nodo de la lista

public:
    Lista() : inicio(nullptr) {} // Constructor que inicializa el inicio como nullptr

    // Destructor para liberar la memoria ocupada por la lista
    ~Lista()
    {
        cout << "El objeto Lista se irá destruyendo" << endl;
        Nodo *aux = inicio;
        while (aux)
        {
            inicio = inicio->Siguiente;
            delete aux; // Libera la memoria del nodo actual
            aux = inicio;
        }
    }

    bool Member(typeinfo);         // Método para verificar si un elemento está en la lista
    virtual bool Insert(typeinfo); // Método virtual para insertar un elemento en la lista
    virtual bool Delete(typeinfo); // Método virtual para eliminar un elemento de la lista
    Nodo *Buscar(typeinfo);        // Método para buscar un nodo en la lista
    bool print();                  // Método para imprimir los elementos de la lista
};

// Método para verificar si un elemento está en la lista
bool Lista::Member(typeinfo elDato)
{
    Nodo *aux = inicio;
    while (aux)
    {
        if (aux->dato == elDato) // Si encuentra el elemento, retorna true
            return true;
        aux = aux->Siguiente;
    }
    return false; // Si no encuentra el elemento, retorna false
}

// Método para insertar un elemento al inicio de la lista
bool Lista::Insert(typeinfo elDato)
{
    // Crea un nuevo nodo y lo enlaza al inicio de la lista
    Nodo *nuevoNodo = new Nodo(elDato, inicio);
    inicio = nuevoNodo;
    return true;
}

// Método para eliminar un elemento de la lista
bool Lista::Delete(typeinfo elDato)
{
    Nodo *aux = inicio;
    Nodo *anterior = nullptr;

    // Busca el nodo a eliminar
    while (aux && aux->dato != elDato)
    {
        anterior = aux;
        aux = aux->Siguiente;
    }

    // Si no se encuentra el elemento, retorna false
    if (!aux)
        return false;

    // Si el nodo a eliminar es el primer nodo
    if (aux == inicio)
        inicio = inicio->Siguiente;
    else
        anterior->Siguiente = aux->Siguiente;

    delete aux; // Libera la memoria del nodo eliminado
    return true;
}

// Método para buscar un nodo específico en la lista
Nodo *Lista::Buscar(typeinfo elDato)
{
    Nodo *aux = inicio;
    while (aux && aux->dato != elDato) // Recorre la lista hasta encontrar el elemento o llegar al final
    {
        aux = aux->Siguiente;
    }
    return aux; // Retorna el nodo encontrado o nullptr si no existe
}

// Método para imprimir todos los elementos de la lista
bool Lista::print()
{
    if (!inicio) // Si la lista está vacía, retorna false
        return false;

    Nodo *aux = inicio;
    cout << "[ ";
    while (aux)
    {
        // Imprime el dato del nodo actual
        cout << aux->dato << (aux->Siguiente ? ", " : "");
        aux = aux->Siguiente;
    }
    cout << " ]" << endl;
    return true;
}

// Clase Conjunto que hereda de Lista y representa un conjunto (sin elementos duplicados)
class Conjunto : public Lista
{
private:
    int card; // Cardinalidad del conjunto (número de elementos)

public:
    Conjunto() : card(0) {}   // Constructor que inicializa la cardinalidad en 0
    bool Insert(typeinfo);    // Método para insertar un elemento en el conjunto
    bool Delete(typeinfo);    // Método para eliminar un elemento del conjunto
    ~Conjunto() { card = 0; } // Destructor para resetear la cardinalidad
};

// Método para insertar un elemento en el conjunto (sin duplicados)
bool Conjunto::Insert(typeinfo elDato)
{
    // Solo inserta el elemento si no está en el conjunto
    if (!Member(elDato))
    {
        Lista::Insert(elDato); // Llama al método Insert de la clase base Lista
        card++;                // Incrementa la cardinalidad
        return true;
    }
    return false; // Si el elemento ya está, no se inserta
}

// Método para eliminar un elemento del conjunto
bool Conjunto::Delete(typeinfo elDato)
{
    // Solo elimina el elemento si está en el conjunto
    if (Lista::Delete(elDato))
    {
        card--; // Decrementa la cardinalidad
        return true;
    }
    return false; // Si el elemento no estaba, no se elimina
}

// Función principal para pruebas
int main(void)
{
    cout << "Prueba de Lista y Conjunto" << endl;

    Lista lista;
    lista.Insert(5);
    lista.Insert(10);
    lista.Insert(15);
    lista.print(); // Debería imprimir: [ 15, 10, 5 ]

    Conjunto conjunto;
    conjunto.Insert(5);
    conjunto.Insert(10);
    conjunto.Insert(5); // Intento de insertar duplicado
    conjunto.print();   // Debería imprimir: [ 10, 5 ] sin duplicados

    conjunto.Delete(5);
    conjunto.print(); // Debería imprimir: [ 10 ]

    return 0;
}
