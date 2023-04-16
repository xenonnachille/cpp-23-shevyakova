#include <iostream> 
 
using std::cout; 
using std::cin; 
using std::endl; 
 
struct Node 
{ 
    char key   = ' '; 
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
 
void is_expression_correct(List* list){
    
    if (list->HEAD == nullptr) { 
        cout << "YES" << endl; 
        return; 
    } 
    if (list->HEAD->key == ')' || list->TAIL->key == '(') { 
        cout << "NO" << endl; 
        return; 
    } 
    Node *current = list->HEAD; 
    while (list->HEAD != nullptr && list->size >= 2) { 
        while (current->key != ')' && current->next != list->NIL) { 
            current = current->next; 
        } 

        if (current->key != ')' and current->next == list->NIL) { 
            cout << "NO" << endl; 
            return; 
        } 

        if (current->prev->key != '(') { 
            cout << "NO" << endl; 
            return; 
        } 

        current->prev->prev->next = current->next; 
        current->next->prev       = current->prev->prev; 
        delete current->prev; 
        delete current; 
        list->size -= 2; 
        current = list->NIL->next; 
    } 

    if (list->size != 0) { 
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
        x = std::getchar(); 
    } 
 
    is_expression_correct(list);
    return 0; 
}