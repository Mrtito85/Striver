#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int val) {
        data = val;
        next = NULL;
    }
};

void append(node* &head, int val) {
    node* newNode = new node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node* reverseLinkedListKGroup(node* head, int k) {
    if (head == NULL) return NULL;

    // Check if there are at least k nodes
    node* temp = head;
    int count = 0;
    while (temp != NULL && count < k) {
        temp = temp->next;
        count++;
    }

    if (count < k) return head; // Less than k nodes, do not reverse

    // Reverse k nodes
    node* prev = NULL;
    node* curr = head;
    node* forward = NULL;
    count = 0;

    while (curr != NULL && count < k) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // Recursively reverse the rest and connect
    if (forward != NULL) {
        head->next = reverseLinkedListKGroup(forward, k);
    }

    return prev; // New head after reversing
}

int main() {
    node* head = NULL;

    append(head, 10);
    append(head, 12);
    append(head, 14);
    append(head, 16);
    append(head, 18);

    cout << "Original List: ";
    display(head);

    int k = 2;
    head = reverseLinkedListKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    display(head);

    return 0;
}
