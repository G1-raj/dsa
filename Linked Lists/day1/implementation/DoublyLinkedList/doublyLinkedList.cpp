#include <iostream>

using namespace std;

template <typename T>
class DoublyLinkedList {
    public:
        T data;
        DoublyLinkedList* next;
        DoublyLinkedList* prev;

        DoublyLinkedList(T data) {
            this -> data = data;
            this -> next = nullptr;
            this -> prev = nullptr;
        }

        ~DoublyLinkedList() {
            int val = this -> data;
            if(next != nullptr) {
                delete next;
                next = nullptr;
            }
        }
};

template <typename T>
void insertAtHead(DoublyLinkedList<T>* &head, DoublyLinkedList<T>* &tail,T data) {
    DoublyLinkedList<T>* temp = new DoublyLinkedList<T>(data);
    temp -> next = head;

    if(head != nullptr) {
        head -> prev = temp ;
    } else {
        tail = temp;
    }
    
    head = temp;

}

template <typename T>
void insertAtTail(DoublyLinkedList<T>* &head,DoublyLinkedList<T>* &tail, T tail_data) {
    DoublyLinkedList<T>* temp = new DoublyLinkedList<T>(tail_data);

    if(head == nullptr) {
        head = temp;
        tail = temp;
    } else {
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}

template <typename T>
void insertAtPosition(DoublyLinkedList<T>* &head,DoublyLinkedList<T>* &tail, T data, int position) {

    if(position == 1) {
        insertAtHead(head, tail, data);
        return;
    }

    DoublyLinkedList<T>* temp = head; 
    int cnt = 1;
    while(cnt < position - 1) {
        temp = temp -> next;
        cnt++; 
    }

    if(temp -> next == nullptr) {
        insertAtTail(head, tail, data);
        return;
    }

    DoublyLinkedList<T>* nodeToInsert = new DoublyLinkedList<T>(data);
    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp; 

}

template <typename T>
void deleteNodeAtPosition(DoublyLinkedList<T>* &head,DoublyLinkedList<T>* &tail, int position) {
 
    if(position == 1) {
        DoublyLinkedList<T>* temp = head;
        temp -> next -> prev = nullptr;
        head = temp -> next;
        temp -> next = nullptr;
        delete temp;

    } else {

        DoublyLinkedList<T>* curr = head;
        DoublyLinkedList<T>* previous = nullptr;

        int cnt = 1;
        while(cnt < position) {
            previous = curr;
            curr = curr -> next;
            cnt++;
        }

        curr -> prev = nullptr;
        previous -> next = curr -> next;
        curr -> next = nullptr; 
        delete curr;

    }

}

template <typename T>
void print(DoublyLinkedList<T>* &head) {
    DoublyLinkedList<T>* temp = head;

    while(temp != nullptr) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

int main() {

    DoublyLinkedList<int>* head = nullptr;
    DoublyLinkedList<int>* tail = nullptr;


    insertAtHead(head, tail, 5);
    insertAtHead(head, tail,10);
    insertAtHead(head, tail,18);
    insertAtHead(head, tail,69);

    insertAtTail(head, tail, 99);
    insertAtTail(head, tail, 39);

    insertAtPosition(head, tail, 45, 3);

    deleteNodeAtPosition(head, tail, 5);

    print(head);
    return 0;
}