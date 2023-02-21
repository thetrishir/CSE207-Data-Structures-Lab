#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* link;
    Node(int v){
        data=v;
        link=NULL;
    }
    Node(){}
};
Node* head=NULL;
int sz=0;

void push(int value){
    Node* temp=new Node();
    temp->data = value;
    temp->link=head;
    head = temp;
    sz++;
}

void pop(){
    Node* temp = head;
    if(head==NULL)
        printf("\nStack is empty");
    else{
        head= head->link;
        temp->link = NULL;
        free(temp);
    }
    sz--;
}

void top(){
    if(sz==0)
        cout<<"\nStack is empty";
    else
        printf("\nTop element is %d \n", head->data);
}

void display(){
    Node* temp=head;
    while(temp!=NULL){
        cout << temp->data << "-> ";
        temp=temp->link;
    }
}

int size(){
    return sz;
}

int main(){
    push(5);
    push(1);
    push(2);
    push(3);
    push(4);

    cout<<"\nBefore delete: ";
    display();
    top();

    pop();
    pop();

    cout<<"\nAfter delete: ";
    display();
    top();

    return 0;
}
