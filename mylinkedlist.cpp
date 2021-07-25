#include <iostream>
using namespace std;
struct node {
    int data;
    node* prev;
    node* next;
};
node* head;
node* tail;

void insert_begin(int new_data) {
    node* new_node = new node();
    new_node->data = new_data;
    if (head == NULL) {
        head = new_node;
        tail = new_node;
    }
    else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}
void insert_end(int new_data) {
    node* new_node = new node();
    new_node->data = new_data;
    if (head == NULL) {
        head = new_node;
        tail = new_node;
    }
    else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}
void insert_node(node* prev_node, int new_data) {
    // check if the given prev node is NULL
    if (prev_node == NULL)
        return;
    // allocate new node and put it's data
    node* new_node = new node();
    new_node->data = new_data;
    // set the next of the new node to be the next of the prev node and vice versa
    new_node->next = prev_node->next;
    // check if the prev node is not the last node in the linked list
    if (prev_node->next != NULL)
        prev_node->next->prev = new_node;
    // move the next of the prev node to be the new node and vice versa
    prev_node->next = new_node;
    new_node->prev = prev_node;
}
void delete_begin() {
    // check if the linked list is empty
    if (head == NULL)
        return;
    // get the node which it will be deleted
    node* temp_node = head;
    // check if the linked list has only one node
    if (head == tail) {
        // delete the temp node
        delete(temp_node);
        head = NULL;
        tail = NULL;
    }
    // otherwise the linked list has nodes more than one
    else {
        // shift the head to be the next node 
        head = head->next;
        head->prev = NULL;
        // delete the temp node
        delete(temp_node);
    }
}
void delete_end() {
    // check if the linked list is empty
    if (head == NULL)
        return;
    // get the node which it will be deleted
    node* temp_node = tail;
    // check if the linked list has only one node
    if (head == tail) {
        // delete the temp node
        delete(temp_node);
        head = NULL;
        tail = NULL;
    }
    // otherwise the linked list has nodes more than one
    else {
        // jump the deleted node
        tail = tail->prev;
        tail->next = NULL;
        // delete the node which selected
        delete(temp_node);
    }
}
void delete_node(node* prev_node) {
    if (prev_node == NULL || prev_node->next == NULL)
        return;
    node* temp_node = prev_node->next;
    prev_node->next = temp_node->next;
    if (temp_node->next != NULL)
        temp_node->next->prev = prev_node;
    delete(temp_node);
}
bool search_node(int key) {
    node* curr = head;
    while (curr != NULL) {
        if (curr->data == key)
            return true;
        curr = curr->next;
    }
    return false;
}
void print_linked_list() {
    node* curr = head;
    while (curr != NULL) {
        cout << curr->data << ' ';
        curr = curr->next;
    }
}

//Q1
int count() {
    int c = 0;
    node* curr = head;
    while (curr != NULL) {
        c++;
        curr = curr->next;
    }
    return c;
}
//Q1
int count_recursive( node* curr = head ) {
    if (curr == NULL) {
        return 0;
    }
    curr = curr->next;
    return 1+ count_recursive(curr);
}
//Q2
void print_recursive(node* curr = head) {
    if (curr == NULL) {
        return;
    }
    cout << curr->data << ' ';
    curr = curr->next;
    return print_recursive(curr);
 
}
//Q3
void print_linked_list_reverse() {
    node* curr = tail;
    while (curr != NULL) {
        cout << curr->data << ' ';
        curr = curr->prev;
    }
}
//Q4
void print_middle() {
    node* curr = head;
    int m = floor(count()/2);
    for (int i = 0; i < m; i++) {
        curr = curr->next;
    }
    cout << curr->data <<endl;

}
//Q5 ,Q8
void print_index(int ind) {
    node* curr = head;
    for (int i = 0; i < ind; i++) {
        curr = curr->next;
    }
    cout << curr->data << endl;

}
//Q6
void insert_index(int ind,int new_data) {
    node* curr = head;
    int c = count();
    node* new_node = new node();
    new_node->data = new_data;

    if (ind < 0 || ind > c) {
        cout << "invalid postion" << endl;
        return;
    }
    for (int i = 0; i <ind-1; i++) {
        curr = curr->next;
    
    }
    new_node->next = curr->next;
   
    if (curr->next != NULL)
        curr->next->prev = new_node;
    curr->next = new_node;
    new_node->prev = curr;

}
//Q7
void delete_index(int ind) {
    node* curr = head;
    int c = count();
    if (ind < 0 || ind >= c) {
        cout << "invalid postion" << endl;
        return;
    }
    for (int i = 0; i < ind - 1; i++) {
        curr = curr->next;
    }
    node* temp_node = curr->next;
    curr->next = temp_node->next;
    if (temp_node->next != NULL)
        temp_node->next->prev = curr;
    delete(temp_node);

}

//------------ Function No.9 ----------------//
void delete_all_iterative()
{
    node* temp = head;
    if (head == NULL)
        return;
    while (head != NULL)
    {
        head = head->next;
        delete(temp);
        node* temp = head;
        head = NULL;
    }
}


//---------------------------------------------
//---------------------------------------------
//----xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx--------
void delete_all_recursive(node* head)
{
    if (head == tail)
        return;
    else {
        delete_all_recursive(head->next);
        delete(head);

    }

}


//------------ Function No.10 ----------------//
bool search_iterative(int key)
{
    node* curr = head;
    while (curr != NULL) {
        if (curr->data == key)
            return true;
        curr = curr->next;
    }
    return false;
}

//---------------------------------------------

bool search_recursive(node* head, int key)
{
    if (head == NULL) {
        return false;
    }
    else if (head->data == key) {
        return true;
    }
    return search_recursive(head->next, key);

}

//---------------------------------------------

//------------ Function No.11 ----------------//

void swap_by_index(int x, int y)
{

    if (x == y)
        return;

    // Search for x (keep track of prevX and CurrX
    node* prevX = NULL; node* currX = head;
    while (currX && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }

    // Search for y (keep track of prevY and CurrY
    node* prevY = NULL; node* currY = head;
    while (currY && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    // If either x or y is not present, nothing to do
    if (currX == NULL || currY == NULL)
        return;

    // If x is not head of linked list
    if (prevX != NULL)
        prevX->next = currY;
    else // Else make y as new head
        head = currY;

    // If y is not head of linked list
    if (prevY != NULL)
        prevY->next = currX;
    else // Else make x as new head
        head = currX;

    // Swap next pointers
    node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}


//---------------------------------------------


//------------ Function No.12 ----------------//
void reverse_linkedList() {
    node* curr = tail;
    while (curr != NULL) {
        cout << curr->data << ' ';
        curr = curr->prev;
    }
}
//---------------------------------------------

//------------ Function No.13 ----------------//
bool check_Loop(node* head)
{
    unordered_set<node*> Set_of_elements;
    while (head != NULL) {
        if (Set_of_elements.find(head) != Set_of_elements.end())
            return true;
        Set_of_elements.insert(head);
        head = head->next;
    }
    return false;

}

//---------------------------------------------


//------------ Function No.14 ----------------//
//----xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx--------
int loop_length(node* head)
{

}
//---------------------------------------------

//------------ Function No.15 ----------------//
int times_of_occurrence_iterative(int element)
{
    node* temp = head;
    int counter = 0;
    while (temp != NULL) {
        if (temp->data == element)
        {
            counter++;
        }
        temp = temp->next;
    }
    return counter;
}

//---------------------------------------------

int element_frequency = 0;

int times_of_occurrence_recursive(node* head, int element)
{
    if (head == NULL)
        return element_frequency;
    if (head->data == key)
        element_frequency++;
    return times_of_occurrence_recursive(head->next, element);
}
//---------------------------------------------


//------------ Function No.16 ----------------//
void Remove_Duplication()
{
    node* curr = head;
    node* next_next;

    if (head == NULL)
        return;

    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            next_next = curr->next->next;
            delete(curr->next);
            curr->next = next_next;
        }
    }
}


int main() {
    insert_end(10);
    insert_end(20);
    insert_end(30);
    insert_end(40);
    insert_end(50);
   // insert_end(60);
    print_linked_list();
    cout << endl;
    int c = count();
    cout << c << endl;
    int x =count_recursive();
    cout << x << endl;
    print_middle();
    print_index(4);
    insert_index(2, 70);
    print_recursive();
    cout << endl;
    delete_index(2);
    print_linked_list();

}
