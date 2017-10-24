#include <iostream>

using namespace std;

struct elem
{
    int dane;
    elem* nast;
    elem* poprz;
};

void addItem(int x,int i, elem* &lista)
{
    elem* newElem = new elem;
    newElem->dane = x;
    if(!lista)
    {
        lista=newElem;
    }
    else if(i==1)
    {
        newElem->nast = lista;
        lista = newElem;
    }
    else
    {
        int j=1;
        elem* temp = lista;
        while(temp->nast)
        {
            j++;
            if(i==j)
            {
                newElem->poprz = temp;
                newElem->nast = temp->nast;
                temp->nast = newElem;
                return;
            }
            temp=temp->nast;
        }
        temp->nast = newElem;
        newElem->poprz = temp;
    }
}

void remove(int i,elem* &lista)
{
    elem* temp = lista;
    if(!lista)
        return;
    else if(i==1)
    {
        lista = temp->nast;
        lista->poprz = NULL;
        delete temp;
    }
    else
    {
        int j=1;
        while(temp->nast)
        {
            j++;
            if(i==j)
            {
                temp->poprz->nast = temp->nast;
                temp->nast->poprz = temp->poprz;
                delete temp;
                return;
            }
            temp=temp->nast;
        }
        delete temp;
    }
}

int showItem(int i,elem* lista)
{
    elem* temp = lista;
    for(int j=1;j<i;j++)
    {
        temp=temp->nast;
    }
    return temp->dane;
}

int main()
{
    elem* lista = NULL;
    addItem(1,1,lista);
    addItem(2,2,lista);
    addItem(3,3,lista);
    cout << showItem(1,lista) <<endl;
    cout << showItem(2,lista) <<endl;
    cout << showItem(3,lista) <<endl;
    remove(1,lista);
    cout << showItem(2,lista) <<endl;
    return 0;
}
