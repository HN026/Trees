#include<iostream>

using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Node *root = NULL;



struct Queue{
    int size;
    int front;
    int rear;
    struct Node **Q;
};



// We are creating the tree in a circular queue
void create ( struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = new struct Node *[q->size];
}

void enqueue ( struct Queue *q, struct Node *x)
{
   if(q->rear == q->size-1)
   {
    cout<<"Queue is Full"<<endl;
   }
   else
   q->rear++;
   q->Q[q->rear] = x;
}

Node *dequeue ( struct Queue *q)
{
    struct Node *x = NULL;
    if(q->front==q->rear)
    {
        cout<<"Queue is Empty"<<endl;
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}


int isEmpty ( struct Queue q)
{
    return q.front == q.rear;
}

struct Stack
{
    int size;
    int top;
    struct Node **S;
};

void Stackcreate( struct Stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->S= new Node *;
}

void push( struct Stack *st, struct Node *x)
{
    if(st->top == st->size-1)
    {
        cout<<"Stack overflow"<<endl;
    }
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

struct Node *pop(struct Stack *st)
{
    struct Node *x = NULL;
    if (st->top == -1)
    {
        cout<<"Stack Underflow"<<endl;
    }
    else
    {
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

int isEmptyStack(struct Stack st)
{
    if(st.top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFullStack(struct Stack st)
{
    return st.top==st.size-1;
}



// Making a tree
void createtree()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);
    

    cout<<"Enter the root value: "<<endl;
    cin>>x;
    root = new struct Node ;
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue( &q, root);


    while(!isEmpty(q))
{
    p = dequeue(&q);
    cout<<"Enter left child of "<<p->data<<endl;
    cin>>x;
    if (x!=-1)
    {
        t = new struct Node;
        t->data = x;
        t->lchild = t->rchild = NULL;
        p->lchild = t;
        enqueue(&q, t);
    }

    cout<<"Enter right child of "<<p->data<<endl;
    cin>>x;
    if(x!=-1)
    {
        t = new struct Node;
        t->data = x;
        t->lchild = t->rchild = NULL;
        p->rchild = t;
        enqueue(&q, t);
    }

}

}

void preorder(struct Node *p)
{
    if(p!=NULL)
    {
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct Node *p)
{
    if(p!=NULL)
    {
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}

void postorder(struct Node *p)
{
    if(p!=NULL)
    {
        
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<" ";
    }
}

void IPreOrder( struct Node *p)
{
    struct Stack stk;
    Stackcreate(&stk, 100);
    while(p!=NULL || (!isEmptyStack(stk)))
    {
     if(p!=NULL)
     {
        cout<<p->data<<" ";
        push(&stk, p);
        p = p->lchild;
     }
     else
     {
        p = pop(&stk);
        p = p->rchild;
     }
    }
}

void IinOrder( struct Node *p)
{
    struct Stack stk;
    Stackcreate(&stk, 100);
    while(p!=NULL || (!isEmptyStack(stk)))
    {
     if(p!=NULL)
     {
        
        push(&stk, p);
        p = p->lchild;
     }
     else
     {
        p = pop(&stk);
        cout<<p->data<<" ";
        p = p->rchild;
     }
    }
}

void LevelOrder( struct Node *p)
{
    struct Queue q;
    create(&q, 100);

    cout<<p->data<<" ";
    enqueue(&q, p);
    
    while(!isEmpty(q))
    {
        p = dequeue(&q);
        if(p->lchild!=NULL)
        {
            cout<<p->lchild->data<<" ";
            enqueue(&q, p->lchild);
        }
        if(p->rchild!=NULL)
        {
            cout<<p->rchild->data<<" ";
            enqueue(&q, p->rchild);
        }
    }

}

int count( struct Node *p)
{
    int x = 0, y=0;
    if(p!=NULL)
    {
        x = count(p->lchild);
        y = count(p->rchild);
        return x+y + 1;
    }
    else
    {
       return 0;
    }
    
}

int Height( struct Node *p)
{
    int x = 0, y=0;
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        x = Height(p->lchild);
        y = Height(p->rchild);
        if(x>y)
        {
            return x+1;
        }
        else
        {
            return y+1;
        }
    }
}

// counting leaf nodes i.e the nodes that have degree 0

int countleaf( struct Node *p)
{
    int x = 0, y = 0;
    if(p!=NULL)
    {
        x = countleaf(p->lchild);
        y = countleaf(p->rchild);
        if(p->lchild==NULL && p->rchild==NULL)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    else
    {
        return 0;
    }
}


int degreetwonodes (struct Node *p)
{
    int x = 0, y = 0;
    if(p!=NULL)
    {
        x = degreetwonodes(p->lchild);
        y = degreetwonodes(p->rchild);
        if(p->lchild!=NULL && p->rchild!=NULL)
        {
            return x+y+1;
        }
        else
        {
            return x+y;
        }
    }
    else
    {
        return 0;
    }
}

int degreeonenodes (struct Node *p)
{
    int x = 0, y = 0;
    if(p!=NULL)
    {
        x = degreeonenodes(p->lchild);
        y = degreeonenodes(p->rchild);
        if((p->lchild==NULL && p->rchild!=NULL) || (p->lchild!=NULL && p->rchild==NULL))
        {
            return x+y+1;
        }
        else
        {
            return x+y;
        }
    }
    else
    {
        return 0;
    }
}

// degree one nodes using exclusive or
int degreeonenodes2 (struct Node *p)
{
    int x = 0, y = 0;
    if(p!=NULL)
    {
        x = degreeonenodes2(p->lchild);
        y = degreeonenodes2(p->rchild);
        if( p->lchild !=NULL ^ p->rchild!=NULL )
        {
            return x+y+1;
        }
        else
        {
            return x+y;
        }
    }
    else
    {
        return 0;
    }
}


int degreeoneandtwonodes (struct Node *p)
{
    int x = 0, y = 0;
    if(p!=NULL)
    {
        x = degreeoneandtwonodes(p->lchild);
        y = degreeoneandtwonodes(p->rchild);
        if(p->lchild!=NULL || p->rchild!=NULL)
        {
            return x+y+1;
        }
        else
        {
            return x+y;
        }
    }
    else
    {
        return 0;
    }
}






int main()
{
    createtree();
    // cout<<count(root);
    // cout<<endl;
    // The index of height starts from 0
    // cout<<Height(root)-1;
    cout<<degreetwonodes(root);
    return 0;
}