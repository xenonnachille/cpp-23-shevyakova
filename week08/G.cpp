#include <iostream>

using std::cout; 
using std::cin; 
using std::endl; 

struct Node
{
    int number;
    Node *next;
};

void do_operation(Node *head, char operation) {
    Node* cur = head->next;
    if (operation == '+') {
        head->number += head->next->number;
    } else {
        head->number *= head->next->number;
    }
    head->next = cur->next;
    delete cur;
}

void push_front(Node *&head_ref, int new_key) {
    if (head_ref == nullptr) {
        head_ref      = new Node;
        head_ref->number = new_key;
        return;
    }
    Node *new_node = new Node;
    new_node->number  = new_key;
    new_node->next = head_ref;
    head_ref       = new_node;
    return;
}

int main() {
    Node* head = new Node;
    char x = ' ';
    x = std::getchar(); 
    
    return 0;
}