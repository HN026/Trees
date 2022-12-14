#include<iostream>

using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Node *root;

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

int main()
{

    createtree();
    inorder(root);
    return 0;
}