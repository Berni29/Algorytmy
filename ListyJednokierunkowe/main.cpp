#include <iostream>

using namespace std;

struct elem
{
    int dane;
    elem* nast;
};

int size(elem* lista);

void skip(elem* &temp1, elem* &temp2)
{
    temp1=temp2;
    temp2=temp2->nast;
}

void insert(int x, int i, elem* &a)
{
   if(!a)
   {
       a = new elem;
       a->dane = x;
   }
   else
   {
       elem* temp1 = NULL;
       elem* temp2 = NULL;
       temp2 = a;
       for(int j=0;j<(i-1);j++)
       {
           if(!temp2)
                return;
           skip(temp1,temp2);
       }
       if(i==1)
       {
           elem* newOne = new elem;
           newOne->dane = x;
           newOne->nast = a;
           a = newOne;
       }
       else if(!temp2)
       {
           elem* newOne = new elem;
           newOne->dane = x;
           temp1->nast = newOne;
       }
       else
       {
           elem* newOne = new elem;
           newOne->dane = x;
           temp1->nast = newOne;
           newOne->nast = temp2;
       }
   }
}

void remove(int i, elem* &lista)
{
    elem* temp1 = NULL;
    elem* temp2 = NULL;
    temp2 = lista;
    for(int j=0;j<(i-1);j++)
    {
        if(!temp2)
            return;
        skip(temp1,temp2);
    }
    if(!lista)
        cout << "Blad/n";
    else if(!temp1)
    {
        temp1 = lista;
        if(temp2->nast)
        {
            lista = temp2->nast;
            delete temp1;
        }
        else
        {
            delete temp2;
            lista = NULL;
        }
    }
    else
    {
        temp1->nast = temp2->nast;
        delete temp2;
    }
}

int read(int i, elem* lista)
{
    elem* temp = lista;
    for(int j=0;j<(i-1);j++)
    {
        temp=temp->nast;
    }
    return temp->dane;
}

int size(elem* lista)
{
    int x=1;
    if(!lista)
        return 0;
    elem* temp = lista;
    while(temp->nast)
    {
     temp=temp->nast;
     x++;
    }
    return x;

}

void print(elem* lista)
{
    int i = size(lista);
    for(int j=1;j<=i;j++)
        cout << read(j,lista) << endl;
}

void revPrint(elem* lista)
{
    int i = size(lista);
    for(i;i>0;i--)
        cout << read(i,lista) << endl;
}

int search(int x, elem* lista)
{
    if(!lista)
        return 0;
    elem* temp = lista;
    int i=1;
    while(temp->nast)
    {

        i++;
        temp=temp->nast;
        if(temp->dane==x)
            return i;
    }
    return 0;
}

int main()
{
    elem* lista = NULL;
    insert(1,1,lista);
    insert(2,2,lista);
    insert(3,3,lista);
    insert(4,4,lista);
    insert(4,10,lista);
    print(lista);
    cout << "Pozycja elementu gdzie x=3 : " << search(3,lista) << endl;
    cout << "Pozycja elementu gdzie x=6 : " << search(6,lista) << endl;
    cout << "Rozmiar listy: " << size(lista) <<endl;
    cout << "Usuwam 2gi element z listy\n";
    remove(2,lista);
    cout << "Rozmiar listy: " << size(lista) <<endl;
    print(lista);
    cout << "Na odwrot\n";
    revPrint(lista);
    return 0;
}
