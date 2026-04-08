#include<iostream>
using namespace std;

struct Linkedlist{
    struct Node{
        int value;
        Node *next;
    };
    
    Node *head = NULL;
    
    void insertAtEnd(int val){
        Node *n = new Node;
        n->value = val;
        n->next = NULL;
        
        if(head == NULL){
            head = n;
        }
        else{
            Node *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = n;
        }
    }
    
    void display(){
        Node *temp = head;
        while(temp != NULL){
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

Linkedlist mergeLists(Linkedlist l1, Linkedlist l2){
    Linkedlist l3;
    
    Linkedlist::Node *temp1 = l1.head;
    Linkedlist::Node *temp2 = l2.head;
    
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->value < temp2->value){
            l3.insertAtEnd(temp1->value);
            temp1 = temp1->next;
        }
        else{
            l3.insertAtEnd(temp2->value);
            temp2 = temp2->next;
        }
    }
    
    while(temp1 != NULL){
        l3.insertAtEnd(temp1->value);
        temp1 = temp1->next;
    }
    
    while(temp2 != NULL){
        l3.insertAtEnd(temp2->value);
        temp2 = temp2->next;
    }
    
    return l3;
}

int main(){
    Linkedlist l1, l2, l3;
    
    l1.insertAtEnd(1);
    l1.insertAtEnd(3);
    l1.insertAtEnd(5);
    
    l2.insertAtEnd(2);
    l2.insertAtEnd(4);
    l2.insertAtEnd(6);
    
    cout << "List 1: ";
    l1.display();
    
    cout << "List 2: ";
    l2.display();
    
    l3 = mergeLists(l1, l2);
    
    cout << "Merged List: ";
    l3.display();
    
    return 0;
}
