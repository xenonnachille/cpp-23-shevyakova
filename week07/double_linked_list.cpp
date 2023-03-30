#include <iostream>

using std::cout;
using std::endl;

struct Node
{
    int key    = 0;
    Node *next = nullptr;
    Node *prev = nullptr;
};

struct List
{
    Node *HEAD  = nullptr;
    Node *TAIL  = nullptr;
    size_t size = 0;
    Node *NIL   = nullptr;
};

List *create_empty_list() {
    List *list = new List;
    list->NIL  = new Node;
    list->HEAD = list->NIL;
    list->TAIL = list->NIL;
    return list;
}

List *push_front(List *list_ptr, int new_key) {
    if (list_ptr == nullptr) {
        return nullptr;
    }
    if (list_ptr->HEAD == list_ptr->NIL) {
        list_ptr->HEAD       = new Node;
        list_ptr->HEAD->key  = new_key;
        list_ptr->HEAD->prev = list_ptr->NIL;
        list_ptr->HEAD->next = list_ptr->NIL;
        list_ptr->TAIL       = list_ptr->HEAD;
        list_ptr->size++;
        return list_ptr;
    }
    if (list_ptr->HEAD->next == list_ptr->NIL) {
        list_ptr->HEAD       = new Node;
        list_ptr->HEAD->key  = new_key;
        list_ptr->HEAD->prev = list_ptr->NIL;
        list_ptr->HEAD->next = list_ptr->TAIL;
        list_ptr->TAIL->prev = list_ptr->HEAD;
        list_ptr->size++;
        return list_ptr;
    }
    Node *current        = list_ptr->HEAD;
    list_ptr->HEAD       = new Node;
    list_ptr->HEAD->key  = new_key;
    list_ptr->HEAD->prev = list_ptr->NIL;
    list_ptr->HEAD->next = current;
    current->prev        = list_ptr->HEAD;
    list_ptr->size++;
    return list_ptr;
}

List *push_back(List *list_ptr, int new_key) {
    if (list_ptr == nullptr) {
        return nullptr;
    }
    if (list_ptr->TAIL == list_ptr->NIL) {
        list_ptr->TAIL       = new Node;
        list_ptr->TAIL->key  = new_key;
        list_ptr->TAIL->prev = list_ptr->NIL;
        list_ptr->TAIL->next = list_ptr->NIL;
        list_ptr->HEAD       = list_ptr->TAIL;
        list_ptr->size++;
        return list_ptr;
    }
    if (list_ptr->TAIL->prev == list_ptr->NIL) {
        list_ptr->TAIL       = new Node;
        list_ptr->TAIL->key  = new_key;
        list_ptr->TAIL->next = list_ptr->NIL;
        list_ptr->TAIL->prev = list_ptr->HEAD;
        list_ptr->HEAD->next = list_ptr->TAIL;
        list_ptr->size++;
        return list_ptr;
    }
    Node *current        = list_ptr->TAIL;
    list_ptr->TAIL       = new Node;
    list_ptr->TAIL->key  = new_key;
    list_ptr->TAIL->next = list_ptr->NIL;
    list_ptr->TAIL->prev = current;
    current->next        = list_ptr->TAIL;
    list_ptr->size++;
    return list_ptr;
}

List *insert_after(List *list_ptr, Node *prev_ptr, int new_key) {
    if ((list_ptr == nullptr) or (prev_ptr == nullptr)) {
        return nullptr;
    }
    if (prev_ptr == list_ptr->NIL) {
        return list_ptr;
    }

    Node *node = new Node;
    if (prev_ptr == list_ptr->TAIL) {
        list_ptr->TAIL = node;
    }
    node->key      = new_key;
    node->next     = prev_ptr->next;
    prev_ptr->next = node;
    list_ptr->size++;
    return list_ptr;
}

void print_list(const List *list_ptr) {
    if (list_ptr == nullptr || list_ptr->HEAD == list_ptr->NIL) {
        std::cout << std::endl;
        return;
    }
    Node *current = list_ptr->HEAD;
    while (current->next != list_ptr->NIL) {
        std::cout << current->key << ' ';
        current = current->next;
    }
    std::cout << current->key << std::endl;
    return;
}

void clear_list(List *list_ptr) {
    if (list_ptr == nullptr) {
        return;
    }

    Node *current = list_ptr->HEAD;
    for (size_t i = 0; i < list_ptr->size; ++i) {
        Node *oldNode;
        if (current->next != list_ptr->NIL) {
            oldNode = current;
            current = current->next;
            delete oldNode;
        } else {
            delete current;
        }
    }
    list_ptr->HEAD = list_ptr->NIL;
    list_ptr->TAIL = list_ptr->NIL;
    list_ptr->size = 0;
    return;
}

void destroy_list(List *list_ptr) {
    if (list_ptr == nullptr) {
        return;
    }

    Node *current = list_ptr->HEAD;
    for (size_t i = 0; i < list_ptr->size; ++i) {
        Node *oldNode;
        if (current->next != list_ptr->NIL) {
            oldNode = current;
            current = current->next;
            delete oldNode;
        } else {
            delete current;
        }
    }
    delete list_ptr->NIL;
    delete list_ptr;
    return;
}

Node *find_key(List *list_ptr, int key) {
    if (list_ptr->HEAD == nullptr) {
        return list_ptr->NIL;
    }
    if (list_ptr->HEAD->key == key) {
        return list_ptr->HEAD;
    }
    Node *current = list_ptr->HEAD;
    while (current->next != list_ptr->NIL) {
        if (current->next->key == key) {
            return current->next;
        }
        current = current->next;
    }
    return list_ptr->NIL;
}

void remove_key(List *list_ptr, int key) {
    if (list_ptr == nullptr) {
        return;
    }
    if (list_ptr->HEAD == list_ptr->NIL) {
        return;
    }
    if (list_ptr->HEAD->key == key) {
        if (list_ptr->HEAD->next == list_ptr->NIL) {
            delete list_ptr->HEAD;
            list_ptr->HEAD = list_ptr->NIL;
            list_ptr->TAIL = list_ptr->NIL;
            return;
        } else if (list_ptr->HEAD != list_ptr->NIL) {
            Node *help_me              = list_ptr->HEAD->next;
            list_ptr->HEAD->next->prev = list_ptr->NIL;
            delete list_ptr->HEAD;
            list_ptr->HEAD = help_me;
        }
        return;
    }

    Node *current = list_ptr->HEAD;
    while (current->next != list_ptr->NIL) {
        if (current->next->key == key) {
            if (current->next->next != list_ptr->NIL) {
                Node *help_me_please      = current->next->next;
                current->next->next->prev = current;
                delete current->next;
                current->next = help_me_please;
                return;
            } else {
                delete current->next;
                current->next  = list_ptr->NIL;
                list_ptr->TAIL = current;
                return;
            }
        }
        current = current->next;
    }
    return;
}

int main() {
    List *list = create_empty_list();
    push_back(list, 0);
    print_list(list);
    remove_key(list, 0);
    print_list(list);
    if (list->TAIL->key == 0) {
        cout << "OK" << endl;
    }
    return 0;
}
