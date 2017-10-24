#include <iostream>

using namespace std;

struct elem
{
    int dane;
    elem* nast;
};

int main()
{
    elem* element = new elem;
    element->dane = 10;
    cout << element->dane << " " << element->nast;
    return 0;
}
