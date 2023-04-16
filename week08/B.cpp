#include <iostream>

struct Node
{
    int value;
    Node *next = nullptr;
};

using std::cout;

int find_middle(const Node *head) {
    if (head == nullptr) {
        return 0;
    }
    if (head->next == nullptr) {
        return head->value;
    }
    if (head->next->next == nullptr) {
        return head->next->value;
    }
    Node *big   = head->next->next;
    Node *small = head->next;
    while (big->next != nullptr and big->next->next != nullptr) {
        small = small->next;
        big   = big->next->next;
    }
    if (big->next == nullptr) {
        return small->value;
    } else {
        small = small->next;
        return small->value;
    }
}

int main() {
    Node *head = new Node;
    Node *cur  = head;
    cur->value = 1;

    cur->next        = new Node;
    cur->next->value = 2;

    cur->next->next        = new Node;
    cur->next->next->value = 3;

    cur->next->next->next        = new Node;
    cur->next->next->next->value = 4;

    cout << find_middle(head);
    return 0;
}