#include"avl.c"

int main()
{
    avl h;
    init_avl(&h);
    printf("\n Enter the number of nodes in the tree \n");
    int n=0;
    scanf("%d", &n);
    printf("Enter the elements of the tree \n");
    for(int i=0;i<n;i++)
    {
        int el=0;
        scanf("%d", &el);
        insert_avl(&h,el);
    }
    printf("\n");
    inorder_print(h);
    printf("\n");
    printf("Enter the value to be deleted");
    int e=0;
    scanf("%d", &e);
    h=delete_avl(&h,h,e);
    inorder_print(h);
    return 0;
}