#include <iostream>
using namespace std;

int mayor(int a, int b);
char mayor(char a, char b);
double mayor(double a, double b);

int main()
{
    cout << mayor('a', 'f') << endl;
    cout << mayor(15, 35) << endl;
    cout << mayor(10.254, 12.452) << endl;

    return 0;
}

int mayor(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

char mayor(char a, char b)
{
    if (a > b)
        return a;
    else
        return b;
}

double mayor(double a, double b)
{
    if (a > b)
        return a;
    else
        return b;
}