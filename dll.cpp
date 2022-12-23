#include<iostream>
using namespace std;
struct node
{
    node* prev;
    int data;
    node * next;
};
class dll
{
    node *root=NULL;
    public:
        void create(int arr[],int n);
        void show();
        void dele();
};
void dll::dele()
{
    node *t=root->next;
    node *p=root->next->next;
    root->next=p;
    p->prev=root;
    t->prev=NULL;
    t->next=NULL;
    node *temp=root;
    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next=t;
    t->prev=temp;
}
void dll::show()
{
    node *p=root;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    return;
}
void dll::create(int arr[],int n)
{
    root=new node;
    root->data=arr[0];
    root->prev=NULL;
    root->next=NULL;
    node *last=root;
    for(int i=1;i<n;i++)
    {
        node *t=new node;
        t->data=arr[i];
        last->next=t;
        t->prev=last;
        t->next=NULL;
        last=t;
    }
}
int main()
{
    int arr[]={1,2,3,4,5,8,5,0};
    dll l;
    l.create(arr,8);
    cout<<"Before Deleting\n";
    l.show();
    l.dele();
    cout<<"\nAfter Deleting\n";
    l.show();
    return 0;
}