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
    bool Member(typeinfo);
    bool AddElem(typeinfo);
    bool RmvElem(typeinfo);
    void Print();
    friend bool Sumar(Conjunto, Conjunto, Conjunto &);
};

#endif // CONJUNTO_H