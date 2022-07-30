#include<iostream>

using namespace std;

class Node
{
    public: 
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue
{
    private: 
    int front;
    int rear;
    int size;
    Node **Q;
    public: 
    Queue()
    {
        front = rear = -1;
        Q = new Node *;
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new Node *[this->size];
    }
    void enqueue(Node *x);
    Node *dequeue();
    void Display();
    int isEmpty();

};

void Queue :: enqueue(Node *x)
{
    if(rear==size-1)
    {
        cout<<"Queue is full"<<endl;
    }
    else
    {
        rear++;
        Q[rear]=x;
    }
}

Node *Queue :: dequeue() {
   Node *x = NULL;
   if(front==rear)
   {
    cout<<"Queue is empty"<<endl;
   }
   else
   {
    x = Q[++front];
    
   }

   return x;
}

int Queue :: isEmpty(){
   return front==rear;
}



void Queue :: Display()
{
    for ( int i=front+1; i<=rear; i++)
    {
        cout<<Q[i]<<" ";
    }
    cout<<endl;
}

class Tree
{
    
    public:
    Node *root;
    Tree()
    {
        root = NULL;
    }
    void CreateTree();
    void PreOrder(Node *p);
    // If we want to make the root node as private then we will have to make the syntax as a dummy one e.g
    // void PreOrder()
    // {
    //     PreOrder(root);
    // }
    void InOrder(Node *p);
    void PostOrder(Node *p);
    void LevelOrder(Node *root);
    int Height(Node *root);

};

void Tree :: CreateTree(){
    Node *p, *t;
    int x;
    Queue q(100);

    cout<<"Enter the root value:"<<endl;
    cin>>x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);
    
    while(!q.isEmpty())
    {
        p = q.dequeue();
        cout<<"Enter left child of "<<p->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }

        cout<<"Enter right child of "<<p->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree :: PreOrder(Node *p)
{
    if(p!=NULL)
    {
        cout<<p->data<<" ";
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

void Tree :: InOrder( Node *p)
{
    if(p!=NULL)
    {
        InOrder(p->lchild);
        cout<<p->data<<" ";
        InOrder(p->rchild);
    }
}

void Tree :: PostOrder( Node *p)
{
    if(p!=NULL)
    {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        cout<<p->data<<" ";
    }
}

void Tree :: LevelOrder(Node *root){
  Queue q(100);
  cout<<root->data<<" ";
  q.enqueue(root);
  while(!q.isEmpty())
  {
    root = q.dequeue();
    if(root->lchild)
    {
        cout<<root->lchild->data<<" ";
        q.enqueue(root->lchild);
    }
    if(root->rchild)
    {
        cout<<root->rchild->data<<" ";
        q.enqueue(root->rchild);
    }
  }
}

int Tree :: Height (Node *root)
{
    int x = 0, y = 0;
    if(root==0)
    {
        return 0;
    }
    else
    {
        x = Height(root->lchild);
        y = Height(root->rchild);
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

int main()
{
    Tree t;
    t.CreateTree();
    t.PreOrder(t.root);
    cout<<endl;
    t.InOrder(t.root);
    cout<<endl;
    t.PostOrder(t.root);
    cout<<endl;
    t.LevelOrder(t.root);
    cout<<endl;
    cout<<t.Height(t.root);
    cout<<endl;
    return 0;
}