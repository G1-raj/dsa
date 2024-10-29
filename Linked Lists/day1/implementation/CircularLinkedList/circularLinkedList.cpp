#include <iostream>

using namespace std;

template <typename T>
class CircularLinkedList {

    public:
        T data;
        CircularLinkedList* next;

        CircularLinkedList(T insert_data) {
            this -> data = insert_data;
            next = nullptr;
        }
};

template <typename T>
void insertAtHead(CircularLinkedList<T>* head, CircularLinkedList<T>* tail, T data) {
    CircularLinkedList<T>* temp = new CircularLinkedList<T>(data);
    temp -> next = head;
    head = temp;
}

template <typename T>
void print(CircularLinkedList<T>* head) {

    CircularLinkedList<T>* temp = head;

    while(temp != nullptr) {
        cout << temp -> data << " ";
        temp = temp -> next;
    } 

}

int main() {

    CircularLinkedList<int>* head = nullptr;
    CircularLinkedList<int>* tail = nullptr;

    insertAtHead(head, tail, 32);
    print(head);
    return 0;
}