#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node* nxt;
    node* prv;
};

class Deque{
public:
    node*head;
    node*tail;
    int sz;

    Deque()
    {
        head=NULL;
        tail=NULL;
        sz=0;
    }
    node*CreatNewNode(int value)
    {
        node * newnode= new node;
        newnode->data = value;
        newnode->nxt  =NULL;
        newnode->prv  =NULL;
        return newnode;
    }
    void push_back(int value)
    {
        node*newnode = CreatNewNode(value);
        if(sz==0)
        {
            head=newnode;
            tail=newnode;
            sz++;
            return;
        }
        tail->nxt = newnode;
        newnode->prv = tail;
        tail = newnode;
        sz++;
    }
    void push_front(int value)
    {
        node * newnode = CreatNewNode(value);
        if(sz==0)
        {
            head=newnode;
            tail=newnode;
            sz++;
            return;
        }
        head->prv = newnode;
        newnode->nxt= head;
        head = newnode;
        sz++;
    }
    void pop_back()
    {
        if(sz==0)
        {
            cout<<"Deque Is Empty \n";
        }
        if(sz==1)
        {
            delete tail;
            head=NULL;
            tail=NULL;
            return;
        }
        node*a=tail;
        tail=tail->prv;
        delete a;
        tail->nxt=NULL;
        sz--;
    }
    void pop_front()
    {
        if(sz==0)
        {
            cout<<"Deque Is Empty \n";
        }
        if(sz==1)
        {
            delete tail;
            head=NULL;
            tail=NULL;
            return;
        }
        node*a=head;
        head=head->nxt;
        delete a;
        head->prv = NULL;
        sz--;
    }
    int front()
    {
        if(sz==0)
        {
            cout<<"Deque Is Empty\n";
            return-1;
        }
        return head->data;
    }
};
int main()
{
    Deque d;
    d.push_back(2);
    d.push_back(8);
    d.pop_front();
    cout<<d.front();
    d.pop_back();
    cout<<d.front();
    return 0;
}


