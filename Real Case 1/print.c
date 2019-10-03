int main()
{
    char* a;
    int i,j = 0;
    printf("enter the string\n");
    scanf("%s",a);
    for(i=0;i<7;i++)
    {
        for(j=i;j<i+4;j++)
        {
            printf("%c", *(a+j));
        }
        printf("\n");
    }
    return 0;
}
