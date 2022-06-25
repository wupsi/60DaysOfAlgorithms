#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
    
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};

struct DoublyLinkedList{

private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList(){
        head = NULL;
        tail = NULL;
    }

    void push_back(int x){
        Node *newNode = new Node(x);

        if(tail == NULL)
            tail = newNode, head = newNode;
        else{
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void push_front(int x){
        Node *newNode = new Node(x);

        if(head == NULL)
            head = newNode, tail = newNode;
        else{
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void insert(int pos, int x){
        int cnt = 0;
        Node *current = head;
        Node *newNode = new Node(x);
        
        while(cnt != pos and current != NULL){
            current = current->next;
            cnt++;
        }

        if(current == head) push_front(x);
        else if(current == tail->next) push_back(x);
        else{
            Node *prevNode = current->prev;
            prevNode->next = newNode;
            current->prev = newNode;
            newNode->prev = prevNode;
            newNode->next = current;
        }
    }

    void pop_back(){
        if(tail != NULL){
            if(tail->prev == NULL)
                head = NULL, tail = NULL;
            else
                tail = tail->prev;
            tail->next = NULL;
        }
    }

    void pop_front(){
        if(head != NULL){
            if(head->next == NULL)
                head = NULL, tail = NULL;
            else
                head = head->next;
        }
    }

    void pop(int pos){
        int cnt = 0;
        Node *current = head;
        
        while(cnt != pos and current->next != tail){
            current = current->next;
            cnt++;
        }

        if(current == head) pop_front();
        else if(current == tail) pop_back();
        else{
            Node *nextNode = current->next;
            Node *prevNode = current->prev;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
        }
    }

    int find(int x){
        int pos = -1, cnt = 0;
        Node *current = head;

        while(current != NULL){
            if(current->data == x){
                pos = cnt;
                break;
            }
            current = current->next;
            cnt++;
        }

        return pos;
    }

    void print(){
        Node *current = head;

        while(current != NULL){
            cout << current->data << " ";
            current = current->next;
        }           
        cout << endl;
    }
};

int main(){

    DoublyLinkedList dll;
    dll.push_back(5);
    dll.push_back(6);
    dll.push_back(7);
    dll.push_back(8);
    dll.push_back(9);
    dll.push_back(10);
    dll.push_front(11);
    dll.push_front(12);
    dll.push_front(13);
    dll.push_front(14);
    dll.push_front(15);
    dll.print();                                                // [15, 14, 13, 12, 11, 5, 6, 7, 8, 9, 10]
    
    dll.pop_back(); 
    dll.pop_back();
    dll.pop_front(); 
    dll.pop_front();
    dll.print();                                                // [13, 12, 11, 5, 6, 7, 8]

    int finded = dll.find(11);
    cout << "Finded on pos: " << finded << endl;                // Finded on pos: 2
    if (finded != -1) {
        dll.pop(finded);
        cout << "poped\n";
    }

    dll.print();                                                // [13, 12, 5, 6, 7, 8]

    finded = dll.find(6);
    dll.insert(finded, 100);
    dll.print();                                                // [13, 12, 5, 100, 6, 7, 8]
}
