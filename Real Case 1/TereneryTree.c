#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char data;
    unsigned endofstring: 1;
    struct node *right,*left,*equal;
};

struct node* newnode(char data)
{
    struct node* root = (struct node*) malloc(sizeof(struct node));
    root->data = data;
    root->endofstring = 0;
    root->right = root->left = root->equal = NULL;
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
            insert(&((*root)->equal), word+1);
        else
            (*root)->endofstring = 1;
    }
}

int main()
{
    struct node* root = NULL;
    char* word;
    int i,j;
    printf("Enter The String\n");
    scanf("%c", &word);

    for(i=0;i<7;i++)
    {
        for(j=i;j<i+4;j++)
        {
            //insert(&root, (word+j));
        }
    }
    return 0;
}
