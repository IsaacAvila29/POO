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
    // bool Copy(Conjunto &);
    // bool Equal(Conjunto);
    void Print();
    // void Intersect(Conjunto, Conjunto &);
    bool Union(Conjunto, Conjunto &);
    // void RmvAll();
};

#endif // CONJUNTO_H