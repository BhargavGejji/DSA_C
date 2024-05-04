#include"tree.h"

void init(tree* t)
{
    *t=NULL;
    return;
}

node* new_node(int val)
{
    node* nn=(node*)malloc(sizeof(node));
    if(nn)
    {
        nn->data=val;
        nn->right=NULL;
        nn->left=NULL;

    }
    else 
    {
        return NULL;
    }
    return nn;
}

void insert_bst(tree* t,int val)
{
    if(*t==NULL)
    {
        *t=new_node(val);
        return;
    }
    node* p=*t;
    node* q;
    while(p)
    {
        q=p;
        if(val>p->data)
        {
            p=p->right;
        }
        else if(val<p->data)
        {
            p=p->left;

        }
        else
        {
            return;
        }
    }
    if(val>q->data)
    {
        q->right=new_node(val);
        return;
    }
    else
    {
        q->left=new_node(val);
        return;
    }

}//end of insert function

int count(tree t)
{
    if(t==NULL)
    {
        return 0;
    }

    return 1+count(t->left)+count(t->right);
}

int height(tree t)
{
    if(t==NULL)
    {
        return 0;
    }
    int l1=height(t->left);
    int l2=height(t->right);
    int ml=(l1>l2)? l1:l2;
    return 1+ml;
}

int search(tree t,int key)
{
    if(t==NULL)
    {
        return 0;
    }
    node* p=t;
    while(p)
    {
        if(p->data==key)
        {
            return 1;
        }
        else if(p->data>key)
        {
            p=p->left;
        }
        else
        {
            p=p->right;
        }
    }//end of while loop
    return 0;
}

void print_inorder(tree t)
{
    if(t==NULL)
    {
        return;
    }

    print_inorder(t->left);
    printf(" %d ",t->data);
    print_inorder(t->right);
}

void print_postorder(tree t)
{
    if(t==NULL)
    {
        return;
    }

    print_postorder(t->left);
    print_postorder(t->right);
    printf(" %d ",t->data);
}

void print_preorder(tree t)
{
    if(t==NULL)
    {
        return;
    }

    printf(" %d ",t->data);
    print_preorder(t->left);
    print_preorder(t->right);
}

void print_inorder_nonrecursive(tree t)
{
    if(t==NULL)
        return;
    
    stack s;
    init_stack(&s);
    int flag=1;
    node* p=NULL;
    p=t;
    while(flag)
    {
        if(p)
        {
            push(&s,p);
            p=p->left;
        }
        else
        {
            if(!isEmptyStack(s))
            {
                p=pop(&s);
                printf("%d ",p->data);
                p=p->right;
            }
            else
            {
                flag=0;
            }
            
        }

    }//end of while loop

}

void print_postorder_nonrecursive(tree t)
{
    if(t==NULL)
    {
        return;
    }
    stack s1,s2;
    init_stack(&s1);
    init_stack(&s2);
    push(&s1,t);
    node* p=t;
    while(!isEmptyStack(s1))
    {
        p=pop(&s1);
        push(&s2,p);
        if(p->left)
            push(&s1,p->left);
        if(p->right)
            push(&s1,p->right);
    }

    while(!isEmptyStack(s2))
    {
        printf("%d ",(pop(&s2))->data);
    }
    
}

void print_preorder_nonrecursive(tree t)
{
        if(t==NULL)
            return;
        
        stack s;
        init_stack(&s);
        node* p=t;
        int flag=1;
        while(flag)
        {
            if(p)
            {
                printf("%d ",p->data);
                push(&s,p);
                p=p->left;
            }
            else
            {
                if(!isEmptyStack(s))
                {
                    p=pop(&s);
                    p=p->right;
                }
                else
                {
                    flag=0;
                }
            }
        }//end of while loop

}

node* inorder_predecessor(node* root)
{
    root=root->left;
    while(root->right)
    {
        root=root->right;
    }
    return root;
}

node* delete(node* t,int val)
{
    if(t==NULL)
        return NULL;
    if(t->left==NULL && t->right==NULL)
    {
        free(t);
        return NULL;
    }

    if(val<t->data)
    {
        t->left=delete(t->left,val);
    }
    else if(val>t->data)
    {
        t->right=delete(t->right,val);
    }
    else
    {
        node* temp=inorder_predecessor(t);
        t->data=temp->data;
        t->left=delete(t->left,temp->data);
    }
    return t;
}
