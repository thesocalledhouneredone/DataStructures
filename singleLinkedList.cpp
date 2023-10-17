#include<iostream>

class Node {;
    public:
    int value;
    Node* next;

    Node(int some) {
        value = some;
    };
};

void printList(Node*);
void insertAtStart(Node**);
void insertAtEnd(Node**);
void insertAtValue(Node**);

int main() {
    
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);

    a->next = b;
    b->next = c;
    c->next = NULL;

    printList(a);
    insertAtStart(&a);
    insertAtStart(&a);
    printList(a);
    insertAtValue(&a);
    printList(a);

    return 0;
}

void printList(Node* n) {
    while(n != NULL) {
        std::cout << n->value << std::endl;
        n = n->next;
    }
    std::cout << "END" << std::endl;
    std::cout << std::endl;
}

void insertAtStart(Node** head) {
    std::cout << "Enter new value to be inserted: \n";
    int insert;
    std::cin >> insert;
    Node* newNode = new Node(insert);

    //make newnode next as head
    newNode->next = *head;

    //make newnode the new HEAD
    *head = newNode;
    std::cout << std::endl;
}

void insertAtEnd(Node** head) {
    std::cout << "Enter the value to be inserted at END: \n";
    int insert;
    std::cin >> insert;

    Node* newNode = new Node(insert);;
    newNode->next = NULL;

    //if list empty make newnode head
    if(*head == NULL) {
        *head = newNode;
        return;
    }

    //find last element
    Node* last = *head;
    while(last->next != NULL) {
        last = last->next;
    }

    //insert newnode as last node
    last->next = newNode;

    std::cout << std::endl;
}

// void insertAtValue(Node** head) {
//     std::cout << "Enter the value to be inserted at POSITION: \n";
//     int insert;
//     std::cin >> insert;

//     int where;
//     std::cout << "Enter the value where new element to be inserted: \n";
//     std::cin >> where;

//     Node* newNode = new Node(insert);

//     //find the element to be inserted after
//     Node* temp = *head;
//     while(temp != NULL) {
//         if(temp->value == where) {
//             newNode->next = temp;
//         }
//         temp = temp->next;
//     }

//     std::cout << std::endl;
// }