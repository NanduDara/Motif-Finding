#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    char data;
    unsigned endofstring: 1;
    struct node *left, *right, *eq;
};

struct node* newnode(char* data, int p)
{
    if(p == 4)
        return NULL;
    struct node* root = (struct node*) malloc(sizeof( struct node ));
    root->data = *(data + p);
    if(p != 3)
        root->endofstring = 0;
    else
        root->endofstring = 1;
    root->left = root->right = NULL;
    root->eq = newnode(data, p + 1);
    return root;
};

void insert(struct node* root, char *word, int p)
{
    if(p == 4)
        return;
    if(!root)
        root = newnode(word, p);

    if(root->data > *(word+p))
        insert(root->left, word, p);
    else if(root->data < *(word+p))
        insert(root->right, word, p);

    else
    {
        insert(root->eq, word, p+1);
    }
}

int main()
{
    struct node* root = NULL;
    string word;
    int i,j = 0;
    cout << "Enter the String\n";
    cin >> word;
    for(i=0;i<7;i++)
    {
        string a;
        a = word.substr(i,4);

        cout << a << "\n";
        char* ch;
        ch = (char *)malloc(sizeof(char)*4);
        for(j=0;j<4;j++)
        {
            *(ch+j) = a[j];
            cout << *(ch+j) << "\t";
        }
        insert(root, ch, 0);
        cout << "\n";
    }
    return 0;
}
