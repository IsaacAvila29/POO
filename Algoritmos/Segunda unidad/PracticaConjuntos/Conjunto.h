#ifndef CONJUNTO_H
#define CONJUNTO_H
#define maxCard 10
typedef int typeinfo;

class Conjunto
{
private:
    typeinfo elementos[maxCard];
    unsigned short int card;

public:
    Conjunto() { card = 0; };
    friend bool operator&(Conjunto, typeinfo);   // Member
    friend bool operator+(Conjunto &, typeinfo); // Añadir
    friend bool operator-(Conjunto &, typeinfo); // Remover
    void Print();
    friend Conjunto operator|(Conjunto &, Conjunto &); // Operador para realizar la unión de conjuntos
};

#endif // CONJUNTO_H