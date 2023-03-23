#include <iostream>

struct Node
{
    int key    = 0;
    Node *next = nullptr;
};

using std::cout;
using std::endl;

void push_front(Node *&head_ref, int new_key) {
    if (head_ref == nullptr) {
        head_ref      = new Node;
        head_ref->key = new_key;
        return;
    }
    Node *new_node = new Node;
    new_node->key  = new_key;
    new_node->next = head_ref;
    head_ref       = new_node;
    return;
}

void push_back(Node *&head_ref, int new_key) {
    if (head_ref == nullptr) {
        head_ref      = new Node;
        head_ref->key = new_key;
        return;
    }
    Node *current = head_ref;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next      = new Node;
    current->next->key = new_key;
    return;
}

void insert_after(Node *&prev_ref, int new_key) {
    if (prev_ref == nullptr) {
        return;
    }
    Node *current        = prev_ref->next;
    prev_ref->next       = new Node;
    prev_ref->next->key  = new_key;
    prev_ref->next->next = current;
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

Node *find(Node *head_ref, int key) {
    if (head_ref == nullptr) {
        return nullptr;
    }
    Node *current = head_ref;
    while (current != nullptr) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return current;
}

void remove_key(Node *&head_ref, int key) {
    if (head_ref == nullptr) {
        return;
    }

    if (head_ref->key == key) {
        Node *heeelp = head_ref->next;
        delete head_ref;
        head_ref = heeelp;
        return;
    }

    Node *current = head_ref;

    while (current->next != nullptr) {
        if (current->next->key == key) {
            break;
        }
        current = current->next;
    }

    if (current->next == nullptr) {
        return;
    }

    Node *help_me_please = current->next->next;
    delete current->next;
    current->next = help_me_please;
    return;
}

int main() {
    // тест для каждой функции свой, поэтому тут ничего нет
    return 0;
}