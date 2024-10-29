#include <iostream>

using namespace std;

template <typename T>
class Node {

    public:
        T data;
        Node* next;

        Node(T data) {
            this -> data = data;
            this -> next = nullptr;
        }

        ~Node() {
            T value = this -> data;
            if(this -> next != nullptr) {
                delete next;
                this -> next = nullptr;
            }
        }
};

template <typename T>
void insertAtHead(Node<T>* &head, T head_data) {
    Node<T>* temp = new Node<T>(head_data);
    temp -> next = head;
    head = temp;
}

template <typename T>
void insertAtTail(Node<T>* &head, Node<T>* &tail,T tail_data) {
    Node<T>* temp = new Node<T>(tail_data);
    
    if(head == nullptr) {
        head = temp;
        tail = temp;
    } else {
        tail -> next = temp;
        tail = temp;
    }

    tail -> next = nullptr;
}


template <typename T>
void insertAtPosition(Node<T>* &head, Node<T>* &tail, T data, int position) {

    if(position == 1) {
        insertAtHead(head, data);
        return;
    }
    Node<T>* temp = head;
    int cnt = 1;
     
     while(cnt < position - 1) {
        temp = temp -> next;
        cnt++;
     }

     if(temp -> next == nullptr) {
        insertAtTail(head, tail, data);
        return;
     }

     Node<T>* nodeToInsert = new Node<T>(data);
     nodeToInsert -> next = temp -> next;
     temp -> next = nodeToInsert;
}

template <typename T>
void deleteNode(Node<T>* &head, int position) {

    if(position == 1) {
        Node<T>* temp = head;
        head = head -> next;
        temp -> next = nullptr;
        delete temp; 
    } else {
        Node<T>* current = head;
        Node<T>* previous = nullptr;

        int cnt = 1;
        while (cnt < position) {
            previous = current;
            current = current -> next;
            cnt++;
        }

        previous -> next = current -> next;
        current -> next = nullptr;
        delete current;
    }
}

template <typename T>
void deleteNodeWithData(Node<T>* &head, T delData) {
    Node<T>* temp = head;
    int position = 1;
    while(head -> data != delData) {
        head = head -> next;
        position++;
    }
   
   if(temp == nullptr) {
    return;
   } 
   print(temp);
   cout << endl;
   deleteNode(temp, position);
   print(temp);
}


template <typename T>
void print(Node<T>* head) {

    Node<T>* temp = head;

    while(temp != nullptr) {
        cout << temp -> data << " ";
        temp = temp -> next;
    } 

}

int main() {

    Node<int>* head = nullptr;
    Node<int>* tail = nullptr;

    Node<float>* floatHead = nullptr;
    Node<float>* floatTail = nullptr;

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 69);
    insertAtTail(head, tail, 18);
    insertAtHead(head, 34);
    insertAtPosition(head, tail,5, 3);
    insertAtPosition(head, tail ,99, 6);

    print(head);
    cout << endl;

    // cout << "List after deleting the node" << endl;
    // deleteNode(head, 6);
    // print(head);
    // cout << endl;

    cout << "List after deleting the node with data" << endl;
    deleteNodeWithData(head, 10);

    return 0;
}