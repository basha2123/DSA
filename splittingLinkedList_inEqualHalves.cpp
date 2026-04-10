#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void splitList(Node* head, Node*& head1, Node*& head2) {
    if (head == NULL) {
        head1 = head2 = NULL;
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast->next->next == head) {
        fast = fast->next;
    }

    head1 = head;
    if (head->next != head)
        head2 = slow->next;

    slow->next = head1;
    fast->next = head2;
}

void printCircular(Node* head) {
    if (head == NULL) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = head;

    Node* head1 = NULL;
    Node* head2 = NULL;

    splitList(head, head1, head2);

    cout << "First half: ";
    printCircular(head1);

    cout << "Second half: ";
    printCircular(head2);

    return 0;
}
