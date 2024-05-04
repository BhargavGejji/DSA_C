#include"tree.h"
#include<limits.h>
void tinit(tree* t,int h)
{
    t->size=(int)(pow(2,h)-1);
    
    t->arr=(int*)malloc(sizeof(int)*t->size);
    for(int i=0;i<t->size;i++)
    {
        t->arr[i]=INT_MIN;
    }
}


void insert(tree* t,int val){

    if(t->arr[0]==INT_MIN){
        t->arr[0]=val;
        
        return;
    }
    int current_index=0;
    while(current_index<t->size)
    {

    
        if(val>t->arr[current_index])
        {
            int right_child_index = 2*current_index+2;
            if(right_child_index<t->size && t->arr[right_child_index]==INT_MIN)
            {
                t->arr[right_child_index]=val;
                return;
            }
            else
            {
                current_index=right_child_index;
            }

        }
        else if(val<t->arr[current_index])
        {
            int left_child_index=2*current_index+1;
            if(left_child_index<t->size && t->arr[left_child_index]==INT_MIN)
            {
                t->arr[left_child_index]=val;
                return;
            }
            else
            {
                current_index=left_child_index;
            }
        }
        else
        {
            return;
        }
    }
}