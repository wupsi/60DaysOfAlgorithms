#include <iostream>
#include <fstream>
using namespace std;

ifstream in;
ofstream out;

struct Node{
    string word;
    int count;
    Node *next;
    Node *prev;
    
    Node(string s, int amount){
        count = amount;
        word = s;
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

    void push_back(string s){
        Node *newNode = new Node(s, 1);

        if(tail == NULL)
            tail = newNode, head = newNode;
        else{
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void push_front(string s){
        Node *newNode = new Node(s, 1);

        if(head == NULL)
            head = newNode, tail = newNode;
        else{
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void insert(int pos, string s){
        int cnt = 0;
        Node *current = head;
        Node *newNode = new Node(s, 1);
        
        while(cnt != pos and current != NULL){
            current = current->next;
            cnt++;
        }

        if(current == head) push_front(s);
        else if(current == tail->next) push_back(s);
        else{
            Node *prevNode = current->prev;
            prevNode->next = newNode;
            current->prev = newNode;
            newNode->prev = prevNode;
            newNode->next = current;
        }
    }

    void sort_insert(string s){
        int cnt = 0;
        Node *current = head;

        while(current != NULL){
            int len = 0, compatibility = 0;
            if(s.size() == current->word.size()) len = s.size();
            else len = s.size() > current->word.size() ? s.size() : current->word.size();
            for(int i = 0; i < len; i++){
                if(s[i] < current->word[i]){
                    insert(cnt, s);
                    return;
                }
                else if(s[i] > current->word[i]) break;
                else compatibility++;
            }
            if(s.size() < current->word.size() and s[len - 1] == current->word[len - 1] and compatibility == len){
                insert(cnt, s);
                return;
            }

            current = current->next;
            cnt++;
        }
        push_back(s);
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

    int find(string s){
        int pos = -1, cnt = 0;
        Node *current = head;

        while(current != NULL){
            if(current->word == s){
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
            cout << current->word << " " << current->count << endl;
            current = current->next;
        }           
        cout << "---------------------------\n";
    }

    void write(){
        Node *current = head;

        while(current != NULL){
            out << current->word << " " << current->count << endl;
            current = current->next;
        }           
    }

    bool empty(){
        return head == NULL and tail == NULL;
    }

    void increase(int pos){
        int cnt = 0;
        Node *current = head;

        while(cnt != pos){
            current = current->next;
            cnt++;
        }   
        current->count++;
    }
};

int main(){

    string word;
    in.open("input.txt");
    out.open("output.txt");

    DoublyLinkedList dll;

    while(in >> word){
        if(dll.empty()){
            dll.push_back(word);
        }
        else{
            int finded_pos = dll.find(word);
            if(finded_pos != -1)
                dll.increase(finded_pos);
            else
                dll.sort_insert(word);
        }
        dll.print();
    }

    dll.write();

    out.close();   
}
bbe
be