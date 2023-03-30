#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Node
{
    int key;
    Node *next;
};

Node *read_list(Node *head) {
    if (head == nullptr) {
        return nullptr;
    }

    int x         = -1;
    Node *current = head;
    while (x != 0) {
        cin >> x;
        current->key  = x;
        current->next = new Node;
        current       = current->next;
    }
    delete current;
    return head;
}

void print_list(Node *head_ref) {
    if (head_ref == nullptr) {
        cout << endl;
        return;
    }
    Node *current = head_ref;
    if (current->next == nullptr) {
        cout << current->key << endl;
        return;
    }
    while (current->next != nullptr) {
        cout << current->key << ' ';
        current = current->next;
    }
    cout << current->key << endl;
    return;
}

void destroy_list(Node *&head_ref) {
    if (head_ref == nullptr) {
        return;
    }
    while (head_ref->next != nullptr) {
        Node *current = head_ref->next->next;
        delete head_ref->next;
        head_ref->next = current;
    }
    delete head_ref->next;
    head_ref = nullptr;
}

Node *reverse(Node *head);

int main() {
    Node *head = nullptr;
    head       = read_list(head);
    head       = reverse(head);
    print_list(head);
    destroy_list(head);
    return 0;
}