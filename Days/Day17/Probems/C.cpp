#include <iostream>
using namespace std;

struct Node {
    int value;
    int ans;
    Node *next;
    Node(int x) {
        value = x;
        next = nullptr;
        ans = -1;
}
};

struct Stack {
private:
    Node *head = nullptr;
    int sz = 0;
public:

    int top() { 
    return head->value; 
    }

    void pop() {
    head = head->next;
    sz--;
    }

    int size() { 
    return sz;
    }

    bool empty() { 
    return sz == 0; 
    }

    int push(int x) {
        Node *newNode = new Node(x);
        if(head == nullptr)
            head = newNode;
        else{
            Node *current = head;
            newNode->next = head;
            head = newNode;
            while(current != nullptr){
                if(current->value <= x){
                    newNode->ans = current->value;
                    break;
                }
                current = current->next;
            }
        }

        return newNode->ans;         
    }

}st;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cout << st.push(x) << ' ';
    }
}