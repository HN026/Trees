#include<iostream>

using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;

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
    q->front = q->rear = 0;
    q->Q = new struct Node *;
}

void enqueue ( struct Queue *q, struct Node *x)
{
   if((q->rear+1)%q->size==q->front)
   {
    cout<<"Queue is Full"<<endl;
   }
   else
   q->rear = (q->rear+1)%q->size;
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
        q->front = (q->front+1)%q->size;
        x = q->Q[q->front];
    }
    return x;
}


int isEmpty ( struct Queue q)
{
    return q.front ==q.rear;
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
    root = new struct Node;
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







int main()
{

    createtree();
    IinOrder(root);
    return 0;
}