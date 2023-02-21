#include<bits/stdc++.h>
using namespace std;

struct Stack{
    int data;
    Stack* link;
};

Stack* head = NULL;

void push(int data){
    Stack* temp=new Stack();
    temp->data= data;
    temp->link=head;
    head = temp;
}

void pop(){
    Stack* temp = head;
    if(head==NULL)
        printf("\nStack is empty");
    else{
    head=head->link;
    temp->link=NULL;
    free(temp);
    }
}

int top(){
    return head->data;
}

void display(){
    Stack* temp = head;
    if(head==NULL)
        printf("\nStack is empty");
    else
        while(temp!=NULL)
        {
            printf("-> %d",temp->data);
            temp=temp->link;
        }
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








