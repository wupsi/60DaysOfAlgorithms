#include <iostream>
using namespace std;

struct Pair{
    string word;
    int counter;

    Pair(){
        counter = 0;
    }
};

struct Node{
    Pair data;
    Node *next;
};

struct LinkedList{

private:
    Node *head;

public:
    LinkedList(){       
        head = NULL;
    }

    void addNode(string s){
        Node *newNode = new Node;
        newNode->data.word = s;
        newNode->next = NULL;

        if(head == NULL)
            head = newNode;
        else{
            Node *current = head;
            while(current->next != NULL)
                current = current->next;

            current->next = newNode;
        }
    }

    void printNodes(){
        Node *current = head;
        while(current != NULL){
            cout << "[" << current->data.word << ", " << current->next << "]" << endl;
            current = current->next;
        }
    }
};

int main(){

    cout << "done";
}


i       [[i, 1], x]
was     [[i, 1], x] -> [[was, 1], y]
she     [[i, 1], x] -> [[she, 1], z] -> [[was, 1], y]
was     [[i, 1], x] -> [[was, 2], y] -> [[she, 1], z]
he      [[i, 1], x] -> [[was, 2], y] -> [[she, 1], z] -> [[he, 1], ]
she
wasnt
wat
waa
waa