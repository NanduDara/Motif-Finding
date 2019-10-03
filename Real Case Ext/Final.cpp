#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
#define MAX 50
using namespace std;

struct node
{
    char data;
    unsigned endofstring: 1;
    struct node *left, *right, *eq;
};

struct node* newnode(char data)
{
    struct node* root = (struct node*) malloc(sizeof( struct node ));
    root->data = data;
    root->endofstring = 0;
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
            //printf( "%s\n", buffer);
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
        if (*(word+1) == '\0')
            return root->endofstring;

        return searchTST(root->eq, word+1);
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
        insert(&root, ch);
        cout << "\n";
    }

    cout << "Following is traversal of ternary search tree\n" << endl;
    traverseTST(root);
    cout << "\n";

    cout << "Following are search results for ACGT and GACT respectively\n" << endl;
    searchTST(root, "ACGT")? printf("Found\n"): printf("Not Found\n");
    searchTST(root, "GACT")? printf("Found\n"): printf("Not Found\n");
    searchTST(root, "ABCD")? printf("Found\n"): printf("Not Found\n");
    return 0;
}
