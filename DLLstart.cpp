#include <iostream>

class Node {
    public:
        int value;
        Node* next;
        Node* prev;

        Node(int value) {
            this->value = value;
            next = nullptr;
            prev = nullptr;
        
    }     
        
};

class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
        int lenght;
    
    public:
        DoublyLinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            lenght = 1;
            
        }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }  
        lenght++;

    }

    void deleteLast() {
        if (head == nullptr) return; // List is empty
        if (head == tail) { // Only one node in the list
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        lenght--;
    
    }

    void prepend(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } 
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        lenght++;
    }

    void deleteFirst() {
        if (head == nullptr) return;
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp; 
        }
        lenght--;
    }

    Node* get(int index) {

        if (index < 0 || index >= lenght) return nullptr; // Index out of bounds
        Node* temp = head;

        if (index < lenght / 2) {
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
        }
        else {
            temp = tail;
            for (int i = lenght - 1; i > index; i--) {
                temp = temp->prev;
            }
        }
        return temp;
    }

    bool set(int index, int value) {
        Node* temp = get(index);
        if (temp) {
            temp->value = value;
            return true;
        }
        return false; // Index out of bounds
    }

    bool insert(int index, int value) {
        if (index < 0 || index > lenght) return false;
        if (index == 0) {
            prepend(value);
            return true;
        }
        if (index == lenght) {
            append(value);
            return true;
        }
        Node* newNode = new Node(value);
        Node* beforeNode = get(index - 1);
        Node* afterNode = beforeNode->next;
        newNode->prev = beforeNode;
        newNode->next = afterNode;
        beforeNode->next = newNode;
        afterNode->prev = newNode;
        lenght++;
        return true;
    }

    void deleteNode(int index) {
        if (index < 0 || index >= lenght) return;
        if (index == 0) {
            deleteFirst();
            return;
        }
        if (index == lenght - 1) {
            deleteLast();
            return;
        }
        Node* temp = get(index);
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        lenght--;
    }

};


        
int main() {
    DoublyLinkedList* myList = new DoublyLinkedList(10);
    

    
    
}