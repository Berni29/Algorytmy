#include <iostream>

using namespace std;

struct elem
{
    int dane;
    elem * nast;
};

void add(elem* &pocz_kolejki, elem* &kon_kolejki, int x)
{
    if(!pocz_kolejki)
    {
        pocz_kolejki = new elem;
        pocz_kolejki->dane = x;
        kon_kolejki = pocz_kolejki;
    }
    else
    {
        kon_kolejki->nast = new elem;
        kon_kolejki->nast->dane = x;
        kon_kolejki = kon_kolejki->nast;
    }
}
int next(elem* &pocz_kolejki, elem* &kon_kolejki)
{
    int x;
    if(!pocz_kolejki)
    {
        cout << "Kolejka jest pusta!\n";
        return 0;
    }
    else
    {
        if(!(pocz_kolejki->nast))
        {
            x = pocz_kolejki->dane;
            delete pocz_kolejki;
            pocz_kolejki = NULL;
            return x;
        }
        else
        {
            elem* temp;
            x = pocz_kolejki->dane;
            temp = pocz_kolejki;
            pocz_kolejki = pocz_kolejki->nast;
            delete temp;
            return x;
        }
    }
}
int firstEl(elem* pocz_kolejki)
{
    if(!pocz_kolejki)
    {
        cout << "Kolejka jest pusta!\n";
        return 0;
    }
    else
    return pocz_kolejki->dane;
}
bool isEmpty(elem* pocz_kolejki)
{
    return !pocz_kolejki;
}

int main()
{
    elem * pocz_kolejki = NULL;
    elem * kon_kolejki = NULL;
    cout << "Czy kolejka jest pusta? >> " << isEmpty(pocz_kolejki) << endl;
    cout << "Wprowadzam do kolejki kolejno liczby:\n";
    cout << "1\n";
    add(pocz_kolejki, kon_kolejki, 1);
    cout << "2\n";
    add(pocz_kolejki, kon_kolejki, 2);
    cout << "3\n";
    add(pocz_kolejki, kon_kolejki, 3);
    cout << "4\n";
    add(pocz_kolejki, kon_kolejki, 4);
    cout << "5\n";
    add(pocz_kolejki, kon_kolejki, 5);
    cout << "Czy kolejka jest pusta? >> " << isEmpty(pocz_kolejki) << endl;
    cout << "Co jest na poczatku? >> " << firstEl(pocz_kolejki) << endl;
    cout << "Wprowadzam z kolejki kolejno liczby:\n";
    cout << next(pocz_kolejki, kon_kolejki) << endl;
    cout << next(pocz_kolejki, kon_kolejki) << endl;
    cout << next(pocz_kolejki, kon_kolejki) << endl;
    cout << next(pocz_kolejki, kon_kolejki) << endl;
    cout << next(pocz_kolejki, kon_kolejki) << endl;
    cout << firstEl(pocz_kolejki) << endl;
    cout << next(pocz_kolejki, kon_kolejki) << endl;
    cout << "Czy kolejka jest pusta? >> " << isEmpty(pocz_kolejki) << endl;
    return 0;
}
