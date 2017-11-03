#include <iostream>

using namespace std;

struct node
{
    char data;
    node * left=NULL;
    node * right=NULL;
};

node * createBinTree()
{
    node * root = new node;
    node * temp = root;
    temp->data = 'A';
    temp->left = new node;
    temp->right = new node;
    temp->left->data = 'B';
    temp->right->data = 'C';
    temp->left->left = new node;
    temp->left->left->data = 'D';
    temp->left->right = new node;
    temp->left->right->data = 'E';
    temp->right->left = new node;
    temp->right->left->data = 'F';
    temp->right->right = new node;
    temp->right->right->data = 'G';
    temp->right->left->left = new node;
    temp->right->left->left->data = 'H';
    temp->right->left->right = new node;
    temp->right->left->right->data = 'J';
    return root;
}

void printTree(node * root, int dp)
{
    for(int i=0;i<dp;i++)
        cout << ' ';
    cout << root->data << endl;
    dp++;
    if(root->left)
    {
        printTree(root->left,dp);
    }
    else
    {
        return;
    }
    if(root->right)
    {
        printTree(root->right,dp);
    }
    else
    {
        return;
    }
}

int main()
{
    node * root = createBinTree();
    printTree(root,0); // Procedura wymaga podania glebokosci poczatkowej wezla
    return 0;
}
