#include<iostream>


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
    int *Q;
}