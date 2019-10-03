#include<stdio.h>
#include<stdlib.h>
#include<string.h>


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
    char* word;
    int i,j = 0;
    printf("Enter The String\n");
    scanf("%s",word);

    for(i=0;i<7;i++)
    {
        char* a;
        for(j=i;j<i+4;j++)
        {
            *(a + j - i) = *(word + j);
        }
        printf("%s",a);
        //insert(root, a, 0);
    }
    /*insert(root,"bana",0);
    insert(root,"appl",0);*/

    return 0;
}
