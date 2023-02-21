#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int v)
    {
        data=v;
        next=NULL;
    }
};
Node* head;

void addToFirst(int val)
{
    Node* temp = new Node(val);
    temp->next=head;
    head = temp;
}

void addToEnd(int val)
{
    if(head==NULL)
    {
        head=new Node(val);
        return;
    }
    else
    {
        Node* curr=head;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr=new Node(val);
        curr->next=NULL;
    }
}

void searchValue(int val)
{
    Node* curr=head;
    while(curr->next!=NULL)
    {
        if(curr->data==val)
        {
            Node* before = new Node(2);
            before->next=curr;
            curr= before;

            Node* after = new Node(3);
            after=curr->next;

        }
        else
        {
            printf("\n Search value does not exist...");
        }
    }
}

/*void addBeforeSearch(int val)
{
    Node* temp = new Node(val);
    temp->next=head;
    head = temp;
}

void addAfterSearch(int val)
{
    Node* temp = new Node(val);
    temp->next=head;
    head = temp;
}*/

void printNode()
{
    Node* curr=head;
    while(curr!=NULL)
    {
        printf("%d \n",curr->data);
        curr=curr->next;
    }
}


int main()
{
    addToEnd(33);
    addToEnd(2);
    addToEnd(3);
    addToEnd(100);
    printNode();
    return 0;
}
