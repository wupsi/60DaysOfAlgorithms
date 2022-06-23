#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct LinkedList{

private:
    Node *head;

public:
    LinkedList(){       
        head = NULL;
    }

    void addNode(int x){
        Node *newNode = new Node;           // Создаем новый узел newNode
        newNode->data = x;                  // Данные узла newNode будет равен x
        newNode->next = NULL;               // Указатель узла newNode будет NULL

        if(head == NULL)                    // Если добавляемые данные будут первым узлом
            head = newNode;                 // head присвоим значение нового узла
        else{                               // Если узел не первый
            Node *current = head;           // Создаем текущий узел
            while(current->next != NULL)    // Пока не дойдем до последнего узла
                current = current->next;    // Проходим по всем узлам до конца

            current->next = newNode;        // Теперь следующим узлом вместо NULL будет newNode
        }
    }

    void printNodes(){
        Node *current = head;
        while(current != NULL){
            cout << "[" << current->data << ", " << current->next << "]" << endl;
            current = current->next;
        }
    }
};

int main(){

    LinkedList list;

    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);

    list.printNodes();
}