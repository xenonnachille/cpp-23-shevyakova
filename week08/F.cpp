#include <iostream>

using std::cout; 
using std::cin; 
using std::endl; 
using std::string;


struct Node 
{
    string name;
    Node *next = nullptr;
    Node *prev = nullptr;
};

struct Pair
{
    Node *start;
    string dead_inside;
};

Node* push_front_but_not_changing_head(Node *head_ref, string new_name) {
    Node *new_node = new Node;
    new_node->name = new_name;

    if (head_ref == nullptr) {
        new_node->next = new_node;
        new_node->prev = new_node;
        head_ref = new_node;
    } else {
        new_node->next = head_ref;
        Node *prehead = head_ref->prev;
        new_node->prev = prehead;
        head_ref->prev = new_node;
        prehead->next = new_node;   
    }

    return head_ref;
}

Pair remove_next(Node *start, int turn){
    Pair res;

    if (start == nullptr) {
        res.dead_inside = "";
        res.start = nullptr;
        return res;
    }

    Node* current = start;
    for (int i = 1; i < turn; ++i){
        current = current->next;
    }
    res.dead_inside = current->name;

    if (current->next == current){   
        res.start     = nullptr;
        delete current;
        return res;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    res.start = current->next;
    delete current;
    return res;
}

int main() {
    int N, k, ans = 1;
    Node* head = nullptr;
    string name;
    cin >> N;

    for (int i = 0; i < N; ++i){
        string new_name;
        cin >> new_name;
        head = push_front_but_not_changing_head(head, new_name);
    }

    cin >> k >> name;
    Pair res_pair = remove_next(head, k);

    while (res_pair.dead_inside != name) {
        res_pair = remove_next(res_pair.start, k);
        ++ans;
    }

    cout << ans;
    return 0;
}