
#include <iostream>

struct Node
{
    int data    = 0;
    Node *next = nullptr;
};

void push_front(Node *&head_ref, int new_data) {
    if (head_ref == nullptr) {
        head_ref      = new Node;
        head_ref->data = new_data;
        return;
    }
    Node *ans = new Node;
    ans->data  = new_data;
    ans->next = head_ref;
    head_ref       = ans;
}

void push_back(Node *&head_ref, int new_data) {
    if (head_ref == nullptr) {
        head_ref      = new Node;
        head_ref->data = new_data;
        return;
    }
    Node *current = head_ref;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next      = new Node;
    current->next->data = new_data;
}

void insert_after(Node *&prev_ref, int new_data) {
    if (prev_ref == nullptr) {
        return;
    }
    Node *new_node = new Node;
    new_node->data  = new_data;
    new_node->next = prev_ref->next;
    prev_ref->next = new_node;
}

void destroy_list(Node *&head_ref) {
    while (head_ref != nullptr) {
        Node *current = head_ref;
        head_ref      = head_ref->next;
        delete current;
    }
}

void print_list(Node *head_ref) {
    if (head_ref == nullptr) {
        std::cout << std::endl;
        return;
    }
    std::cout << head_ref->data;
    Node *current = head_ref;
    while (current->next != nullptr) {
        std::cout << " " << current->next->data;
        current = current->next;
    }
    std::cout << std::endl;
}

Node *find(Node *head_ref, int data) {
    Node *current = head_ref;
    while (current != nullptr) {
        if (current->data == data) break;
        current = current->next;
    }
    return current;
}

void remove_data(Node *&head_ref, int data) {
    if (head_ref == nullptr) return;
    if (head_ref->data == data) {
        Node *ans = head_ref->next;
        delete head_ref;
        head_ref = ans;
        return;
    }
    Node *current = head_ref;
    while (current->next != nullptr) {
        if (current->next->data == data) {
            Node *new_node = current->next->next;
            delete current->next;
            current->next = new_node;
            return;
        }
        current = current->next;
    }
}

Node *read_list(Node *head) {
    int new_data;
    std::cin >> new_data;
    if (new_data == 0) return head;
    head      = new Node;
    head->data = new_data;
    std::cin >> new_data;
    Node *current = head;
    while (new_data != 0) {
        current->next      = new Node;
        current->next->data = new_data;
        current            = current->next;
        std::cin >> new_data;
    }
    return head;
}

Node *reverse(Node *head) {
    if (head == nullptr) return nullptr;
    Node *current      = head;
    Node *current_next = head->next;
    head->next         = nullptr;
    while (current_next != nullptr) {
        Node *new_current_next = current_next->next;
        current_next->next     = current;
        current                = current_next;
        current_next           = new_current_next;
    }
    return current;
}

int find_middle(const Node *head) {
    int k              = 1;
    int middle         = 0;
    Node *current_next = head->next;
    while (current_next != nullptr) {
        if (k % 2 == 0) middle++;
        current_next = current_next->next;
        k += 1;
    }
    if (k % 2 == 0) middle++;
    return middle;
}

Node *doesnt_matter(Node *first, Node *second) {
    if (first == nullptr) {
        return second;
    }

    if (second == nullptr) {
        return first;
    }
    if (first->data <= second->data) {
        return first;
    }

    return second;
}

Node *mergeTwoLists(Node *list1, Node *list2) {
    if (list1 == nullptr) {
        return list2;
    }

    if (list2 == nullptr) {
        return list1;
    }

    Node *cur1 = list1;
    Node *cur2 = list2;
    Node *ans = doesnt_matter(cur1, cur2);

    if (ans == cur1) {
        cur1 = cur1->next;
    } else {
        cur2 = cur2->next;
    }

    Node *current = ans;
    while ((cur1 != nullptr) or (cur2 != nullptr)) {
        Node *helpme = doesnt_matter(cur1, cur2);
        current->next  = helpme;

        if (helpme == cur1) {
            cur1 = cur1->next;
        } else {
            cur2 = cur2->next;
        }
        current = current->next;
    }

    return ans;
}

int main() {
    Node *head1 = nullptr;
    Node *head2 = nullptr;
    head1       = read_list(head1);
    head2       = read_list(head2);
    print_list(mergeTwoLists(head1, head2));
    return 0;
}
