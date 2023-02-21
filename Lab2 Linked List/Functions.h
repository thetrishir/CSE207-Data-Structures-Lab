#include "Struct.h"
#include <bits/stdc++.h>
using namespace std;

///All problems are worth 10 points
///For today, the time complexity of
///your solution does not matter as long as your program terminates.

/**
    The isEmpty function should return 1
    if the linked list whose first node is
    pointed by the head variable is empty,
    (i.e the head points to NULL), and
    0 otherwise
*/

int isEmpty(Node* head){
    if(head == NULL)
        return 1;
    else
        return 0;
}

/**
    Given a pointer to the start of a linked list,
    specified by Node* head, and an integer value x,
    delete ALL nodes in the linked list with the
    value x. Return head after you have deleted all
    the nodes.
*/

Node* deleteAll(Node* head, int x){
    while(head!=NULL && head->value==x){
        Node*temp=head;
        head=head->next;
        free(temp);
    }
    if(head==NULL)
        return head;

    Node* curr= head;

    while(curr!=NULL)
    {
        if(curr->value==x)
        {
            Node* prev=head;
            while(prev->next!=curr){
                prev=prev->next;
            }
            prev->next=curr->next;
            Node* temp=curr;
            curr=curr->next;
            free(temp);
        }
        else curr=curr->next;
    }
    return head;
}

/**
    Given a pointer to the start of a linked list,
    specified by Node* head, and 2 integers with values
    x and y, replace ALL nodes in the linked list with the
    value x with nodes with value y. Return head after you
    have replaced all the nodes.
*/


Node* replaceAll(Node* head, int x, int y){

    Node* temp = head;
    while(head != NULL){
        if(head->value == x)
            head->value = y;
        else
            head = head->next;
    }
    return temp;
}

/**
    Given a pointer to the start of a linked list,
    specified by Node* head, return the number of distinct
    integers in the linked list.
*/
int countFrequency(Node* head){
    int count = 0;
    while(head!=NULL){
        Node*temp = head->next;
        int a = 0;
        while(temp!=NULL){
            if(temp->value==head->value){
                a = 1;
            }
            temp = temp -> next;
        }
        if(a==0){
            count++;
        }
        head = head -> next;
    }
    return count;
}

/**
    Given a pointer to the start of a linked list,
    specified by Node* head, create another linked list
    in which the values are in the reverse order of how
    they were in the original linked list. Return a pointer
    to the head of the new linked list.
*/

Node* reverseLinkedList(Node* head){
    Node* h;
    h = new Node(head->value);
    Node*curr=head->next;
    while(curr!=NULL){
        Node*temp = new Node(curr->value);
        temp->next=h;
        h=temp;
        curr=curr->next;
    }
    return h;
}


