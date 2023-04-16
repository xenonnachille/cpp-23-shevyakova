#include <iostream> 
 
using std::cout; 
using std::cin; 
using std::endl; 
 
struct Node 
{ 
    char key   = ' '; 
    int type   = 0; 
    Node *next = nullptr; 
    Node *prev = nullptr; 
}; 
 
struct List 
{     
    Node* NIL  = new Node; 
    Node* HEAD = NIL; 
    Node* TAIL = NIL;
    size_t size = 0; 
}; 
 
List *push_back(List *list_ptr, char new_key) { 
    if (list_ptr == nullptr) { 
        return list_ptr; 
    } 
    Node *new_tail      = new Node; 
    new_tail->next      = list_ptr->NIL; 
    list_ptr->NIL->prev = new_tail; 
    if ((list_ptr->HEAD == list_ptr->NIL) and (list_ptr->TAIL == list_ptr->NIL)) { 
        new_tail->prev      = list_ptr->NIL; 
        list_ptr->NIL->next = new_tail; 
        list_ptr->HEAD      = new_tail; 
        list_ptr->HEAD->key = new_key; 
    } else { 
        new_tail->prev       = list_ptr->TAIL; 
        list_ptr->TAIL->next = new_tail; 
    } 
    list_ptr->TAIL      = new_tail; 
    list_ptr->TAIL->key = new_key; 
    list_ptr->size++; 
    return list_ptr; 
} 
 
void is_expression_correct(List* listptr) {
        if (listptr->HEAD == nullptr) { 
        cout << "YES" << endl; 
        return; 
    } 
    if (listptr->HEAD->type == 1 || listptr->TAIL->type == 0) { 
        cout << "NO" << endl; 
        return; 
    } 

    Node *current = listptr->HEAD; 
    while (listptr->HEAD != nullptr && listptr->size >= 2) { 
        while (current->type != 1 && current->next != listptr->NIL) { 
            current = current->next; 
        } 

        if (current->type != 1 && current->next == listptr->NIL) { 
            cout << "NO" << endl; 
            return; 
        } 

        if ((current->key == ')' && current->prev->key != '(') || (current->key == '>' && current->prev->key != '<') ||
            (current->key == '}' && current->prev->key != '{') || (current->key == ']' && current->prev->key != '[')) { 
            cout << "NO" << endl; 
            return; 
        } 
        current->prev->prev->next = current->next; 
        current->next->prev       = current->prev->prev; 
        delete current->prev; 
        delete current; 
        listptr->size -= 2; 
        current = listptr->NIL->next; 
    } 

    if (listptr->size != 0) { 
        cout << "NO" << endl; 
        return; 
    } else { 
        cout << "YES" << endl; 
        return; 
    } 
}

int main() { 
    List *list = new List; 
 
    char x = ' '; 
 
    x = std::getchar(); 
    while (x != '\n' && x != '\0') { 
        push_back(list, x); 
        if (x == ')' ||  x == '>' ||  x == ']' || x == '}') { 
            list->TAIL->type = 1; 
        }
        x = std::getchar(); 
    } 

    is_expression_correct(list);
    return 0; 
}