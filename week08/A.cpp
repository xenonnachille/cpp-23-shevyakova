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
        head = new Node;
    }

    int x         = -1;
    Node *current = head;
    while (true) {
        cin >> x;
        current->key = x;
        if (x == 0) {
            current->next = nullptr;
            break;
        }
        current->next = new Node;
        current       = current->next;
    }
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

Node *reverse(Node *head) {
    int size      = 0;
    Node *current = head;
    while (current != nullptr) {
        size++;
        current = current->next;
    }
    current   = head;
    int *keys = new int[size];
    for (int i = 0; i < size; i++) {
        keys[i] = current->key;
        current = current->next;
    }
    current = head;
    for (int i = 0; i < size; i++) {
        current->key = keys[size - 1 - i];
        current      = current->next;
    }
    delete[] keys;
    return head;
}

int main() {
    Node *head = nullptr;
    head       = read_list(head);
    print_list(head);
    head = reverse(head);
    print_list(head);
    destroy_list(head);
    return 0;
}