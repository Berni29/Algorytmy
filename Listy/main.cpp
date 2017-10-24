#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct elem
{
    int expo;
    int coef;
    elem* nast = NULL;
};

void readAll(elem* poly)
{
    while(poly->nast)
    {
        cout << "expo: " << poly->expo << " coef: " << poly->coef << endl;
        poly = poly->nast;
    }
}

void addStatement(elem* &temp,int coef,int expo)
{
    temp->coef = coef;
    temp->expo = expo;
    temp->nast = new elem;
    temp = temp->nast;
}

elem* polyadd(elem* l1,elem* l2)
{
    elem* solution = new elem;
    elem* temp = solution;
    while(l1->nast||l2->nast)
    {
        if(l1->expo > l2->expo)
        {
            temp->expo = l1->expo;
            temp->coef = l1->coef;
            l1 = l1->nast;
            temp->nast = new elem;
            temp = temp->nast;
            continue;
        }
        else if(l1->expo < l2->expo)
        {
            temp->expo = l2->expo;
            temp->coef = l2->coef;
            l2 = l2->nast;
            temp->nast = new elem;
            temp = temp->nast;
            continue;
        }
        else
        {
            temp->expo = l1->expo;
            temp->coef = l1->coef + l2->coef;
            l1 = l1->nast;
            l2 = l2->nast;
            temp->nast = new elem;
            temp = temp->nast;
            continue;
        }
    }
    return solution;
}

int main()
{
    elem* l1 = new elem;
    elem* l2 = new elem;
    elem* temp = l1;
    addStatement(temp,2,5);
    addStatement(temp,-6,3);
    addStatement(temp,-1,2);
    addStatement(temp,7,1);
    addStatement(temp,4,0);
    cout << "Pierwszy wielomian: \n";
    readAll(l1);
    temp = l2;
    addStatement(temp,2,6);
    addStatement(temp,2,5);
    addStatement(temp,1,4);
    addStatement(temp,1,2);
    addStatement(temp,-3,1);
    addStatement(temp,10,0);
    cout << "Drugi wielomian: \n";
    readAll(l2);
    elem* wynik = polyadd(l1,l2);
    cout << "Wynik dodawania: \n";
    readAll(wynik);
}
