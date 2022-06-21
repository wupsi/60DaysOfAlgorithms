#include <iostream>
using namespace std;

struct stack{

private:
    int pos;
    int arr[100000];

public:
    stack(){
        pos = 0;
    }

    void push(int x){
        arr[pos++] = x;
    }

    void pop(){
        if(!empty())
            pos--;
        else 
            cout << "error\n";
    }

    int top(){
        if(!empty())
            return arr[pos - 1];
        else
            return -9999999;
    }

    bool empty(){
        return pos == 0;
    }

    int size(){
        return pos;
    }

    void clear(){
        pos = 0;
    }
};

int main(){

    stack st;

    while(true){
        
        string command; cin >> command;

        if(command == "push"){
            int n; cin >> n;
            st.push(n);
            cout << "ok\n";
        }

        if(command == "pop"){
            if(!st.empty()){
                cout << st.top() << endl;
                st.pop();
            }
            else
                cout << "error\n";
        }

        if(command == "back"){
            if(!st.empty())
                cout << st.top() << endl;
            else
                cout << "error\n";
        }

        if(command == "size")
            cout << st.size() << endl;
        
        if(command == "clear"){
            st.clear();
            cout << "ok\n";
        }

        if(command == "exit"){
            cout << "bye";
            return 0;
        }
    }
}