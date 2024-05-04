#include"heap.c"

int main()
{
    min_heap h;
    printf("Enter the number of elements in the heap\n");
    int n=0;
    scanf("%d",&n);

    init_min_heap(&h,n);
    printf("\nEnter the elements of the heap\n");
    for(int i=0;i<n;i++)
    {
        int el=0;
        scanf("%d",&el);
        insert_min_heap(&h,el);
    }
    print_heap(h);
    printf("\n");
    heap_sort(&h);
    print_heap(h);
    return 0;
}