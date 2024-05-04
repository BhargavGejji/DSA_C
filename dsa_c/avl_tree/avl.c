#include"avl.h"

void init_avl(avl* a)
{
    *a=NULL;
}

int maxDepth(node* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
 
        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}
void ll(avl* h,node* n)
{
    node* temp=n->left;
    n->left=temp->right;
    if(n->left)
    {
        n->left->parent=n;
    }
    temp->right=n;
    temp->parent=n->parent;
    n->parent=temp;
    if(temp->parent)
    {

        if(temp->parent->left==n)
        {
            temp->parent->left=temp;
        }
        else
        {
            temp->parent->right=temp;
        }
    }
    else
    {
        *h=temp;
    }
    adjust_bf(&n);
    adjust_bf(&temp);

}

void rr(avl* h,node* n)
{
    node* temp=n->right;
    n->right=temp->left;
    if(n->right)
    {
        n->right->parent=n;
    }
    temp->left=n;
    temp->parent=n->parent;
    n->parent=temp;

}

void lr(avl* h,node* n)
{
    ll(h,n->right);
    rr(h,n);
}

void rl(avl* h,node* n)
{
    rr(h,n->left);
    ll(h,n);
}



void adjust_bf(avl* h)
{
    node* n=*h;
    while(n)
    {
        n->balance_factor=maxDepth(n->left)-maxDepth(n->right);
        n=n->parent;
    }
}

void adjust_imbalance(avl* h,node* n)
{
    while(n)
    {
        n->balance_factor=maxDepth(n->left)-maxDepth(n->right);
        if(n->balance_factor<-1)
        {
            if(n->right->balance_factor<=0)
            {
                rr(h,n);
            }
            else
            {
                lr(h,n);
            }
        }
        else if(n->balance_factor>1)
        {
            if(n->left->balance_factor>=0)
            {
                ll(h,n);
            }
            else
            {
                rl(h,n);
            }
        }
        n=n->parent;
    }
}
void insert_avl(avl* h,int val)
{
    node* nn=(node*)malloc(sizeof(node));
    if(nn)
    {
        nn->data=val;
        nn->balance_factor=0;
        nn->left=NULL;
        nn->right=NULL;
        nn->parent=NULL;
    }
    else
    {
        return;
    }

    if(*h==NULL)
    {
        *h=nn;
        
        return;
    }

    node* p=*h;
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
        q->right=nn;
    }
    else{
        q->left=nn;
    }
    nn->parent=q;
    adjust_bf(&nn);
    adjust_imbalance(h,nn->parent);
}

node* inorder_predecessor(node* h)
{
    h=h->left;
    
    while(h->right)
    {
        h=h->right;
    }
    return h;
}


node* delete_avl(avl* h,node* root,int val)
{
    node* predecessor;
    
        if(root==NULL)
        {
            return NULL;
        }
        else if(root->left==NULL && root->right==NULL)
        {
            node* temp=root;
            temp=root->parent;
            if(temp)
            {
                if(temp->left==root)
                {
                    temp->left=NULL;
                    free(root);
                    return NULL;
                }
                else
                {
                    temp->right=NULL;
                    free(root);
                    return NULL;
                }
            }
            else
            {
                node* temp=*h;
                *h=NULL;
                free(temp);
                return NULL;
            }
        }
        if(root->data>val)
        {
            root->left=delete_avl(h,root->left,val);
        }
        else if(root->data<val)
        {
            root->right=delete_avl(h,root->right,val);
        }
        else if(root->data==val)
        {
            predecessor=inorder_predecessor(root);
            root->data=predecessor->data;
            root->left=delete_avl(h,root->left,predecessor->data);
            adjust_bf(&root);
            adjust_imbalance(h,root);
        }
    return root;   
}

void inorder_print(avl h)
{
    if(h==NULL)
    {
        return;
    }

    inorder_print(h->left);
    printf(" %d ",h->data);
    inorder_print(h->right);
}