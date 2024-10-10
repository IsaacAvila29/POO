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
    friend bool operator&(Conjunto, typeinfo);
    friend bool operator+(Conjunto, typeinfo);
    bool RmvElem(typeinfo);
    void Print();
    bool Union(Conjunto, Conjunto &); // Union
};

#endif // CONJUNTO_H