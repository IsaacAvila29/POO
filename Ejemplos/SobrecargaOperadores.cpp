//<tipo> operator<operador binario>(<tipo> <identificador>);

// <tipo> operator <operador> (<argumentos>)
// {
//    <sentencias>;
// }

// Sobrecarga de operadores
// (C) 2009 Con Clase
// Salvador Pozo

#include <iostream>
using namespace std;

struct complejo
{
    float a, b;
};

/* Definición del operador + para complejos */
complejo operator+(complejo com1, complejo com2)
{
    complejo temp = {com1.a + com2.a, com1.b + com2.b};
    return temp;
}

/* Definición del operador ++ prefijo para complejos */
complejo operator++(complejo &c)
{
    c.a++;
    return c;
}

/* Definición del operador ++ sufijo para complejos */

void Mostrar(complejo c)
{
    cout << "(" << c.a << "," << c.b << ")" << endl;
}

/* Prototipo del operador + para complejos */
// complejo operator+(complejo a, complejo b);
// /* Prototipo del operador ++ prefijo para complejos */
// complejo operator++(complejo &a);
// /* Prototipo del operador ++ sufijo para complejos */
// complejo operator++(complejo &a, int);

// void Mostrar(complejo);

int main()
{
    complejo x = {10, 32};
    complejo y = {21, 12};

    complejo z;
    /* Uso del operador sobrecargado + con complejos */
    z = x + y;
    cout << "z = (x + y) = ";
    Mostrar(z);
    cout << "++z = ";
    Mostrar(++z);
    cout << "z = ";
    Mostrar(z);

    return 0;
}
