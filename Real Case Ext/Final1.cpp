#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
#define MAX 50
using namespace std;

int maxi = 0;
char ans[4];
struct node
{
    char data;
    unsigned endofstring: 1;
    int Count;
    struct node *left, *right, *eq;
};

struct node* newnode(char data)
{
    struct node* root = (struct node*) malloc(sizeof( struct node ));
    root->data = data;
    root->endofstring = 0;
    root->Count = 0;
    root->left = root->right = root->eq = NULL;
    return root;
};

void insert(struct node** root, char* word)
{
    if(!(*root))
        *root = newnode(*word);
    if((*root)->data > (*word))
        insert(&((*root)->left), word);
    else if((*root)->data < (*word))
        insert(&((*root)->right), word);
    else
    {
        if(*(word+1))
            insert(&((*root)->eq), word+1);
        else
            (*root)->endofstring = 1;
    }
}

void traverseTSTUtil(struct node* root, char* buffer, int depth)
{
    if (root)
    {
        traverseTSTUtil(root->left, buffer, depth);

        buffer[depth] = root->data;
        if (root->endofstring)
        {
            buffer[depth+1] = '\0';
            cout << buffer << endl;
        }

        traverseTSTUtil(root->eq, buffer, depth + 1);

        traverseTSTUtil(root->right, buffer, depth);
    }
}

void traverseTST(struct node* root)
{
    char buffer[MAX];
    traverseTSTUtil(root, buffer, 0);
}

void MtraverseTSTUtil(struct node* root, char* buffer, int depth)
{
    if (root)
    {
        MtraverseTSTUtil(root->left, buffer, depth);

        buffer[depth] = root->data;
        if(root->Count > ::maxi)
        {
            ::maxi = root->Count;
            buffer[depth+1] = '\0';
            for(int h=0;h<4;h++)
            {
                ::ans[h] = *(buffer+h);
            }
        }

        MtraverseTSTUtil(root->eq, buffer, depth + 1);

        MtraverseTSTUtil(root->right, buffer, depth);
    }
}

void MtraverseTST(struct node* root)
{
    char buffer[MAX];
    MtraverseTSTUtil(root, buffer, 0);
}

int searchTST(struct node *root, char *word)
{
    if (!root)
        return 0;

    if (*word < (root)->data)
        return searchTST(root->left, word);

    else if (*word > (root)->data)
        return searchTST(root->right, word);

    else
    {
        while(*(word+1) == '\0')
        {
            root->Count = root->Count + 1;
            return root->endofstring;
        }

        return searchTST(root->eq, word+1);
    }
}

int main()
{
    struct node* root = NULL;
    string word[4];
    int i,j,k = 0;
    cout << "Enter all Strings\n";
    for(i=0;i<4;i++)
        cin >> word[i];
    for(i=0;i<7;i++)
    {
        string a;
        a = word[0].substr(i,4);

        cout << a << "\n";
        char* ch;
        ch = (char *)malloc(sizeof(char)*4);
        for(j=0;j<4;j++)
        {
            *(ch+j) = a[j];
            cout << *(ch+j) << "\t";
        }
        insert(&root, ch);
        cout << "\n";
    }

    cout << "\nTotal Lmers In a Tree" << endl;
    traverseTST(root);
    cout << "\n";

    for(i=1;i<4;i++)
    {
        for(j=0;j<7;j++)
        {
            string b;
            b = word[i].substr(j,4);

            cout << b << "\n";
            char* ch1;
            ch1 = (char *)malloc(sizeof(char)*4);
            for(k=0;k<4;k++)
            {
                *(ch1+k) = b[k];
                cout << *(ch1+k) << "\t";
            }
            cout << "\n";
            searchTST(root, ch1)? printf("Found\n"): printf("Not Found\n");
        }
        cout << "\n\n";
    }
    cout << "\n\n";
    cout << "The Lmer with maximum count\n";
    cout << "Our Motif---------";
    MtraverseTST(root);
    cout << ::ans << endl;
    cout << "Count value of Motif---";
    cout << ::maxi+1 << endl;
    return 0;
}

