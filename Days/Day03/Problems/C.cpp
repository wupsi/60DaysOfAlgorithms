#include <iostream>
using namespace std;

struct deque{

private:
    int start, finish;
    int arr[100000];

public:
    deque(){
        start = 50000;
        finish = 50000;
    }

    void push_back(int x){
        arr[finish++] = x;
    }

    void push_front(int x){
        arr[--start] = x;
    }

    void pop_back(){
        if(!empty())
            finish--;
        else
            cout << "ERROR\n";
    }

    void pop_front(){
        if(!empty())
            start++;
        else    
            cout << "ERROR\n";
    }

    int back(){
        if(!empty())
            return arr[finish - 1];
        else
            return -9999999;
    }

    int front(){
        if(!empty())
            return arr[start];
        else
            return -9999999;
    }

    bool empty(){
        return finish - start <= 0;
    }

    int size(){
        return finish - start;
    }

    void clear(){
        start = 50000;
        finish = 50000;
    }

    void print(){
        cout << "Array: ";
        for(int i = start; i < finish; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){

    deque dq;

    while(true){

        string command; cin >> command;

        if(command == "push_front"){
            int x; cin >> x;
            dq.push_front(x);
            cout << "ok\n";
        }

        if(command == "push_back"){
            int x; cin >> x;
            dq.push_back(x);
            cout << "ok\n";
        }

        if(command == "pop_front"){
            if(!dq.empty()){
                cout << dq.front() << endl;
                dq.pop_front();
            }
            else
                cout << "error\n";
        }

        if(command == "pop_back"){
            if(!dq.empty()){
                cout << dq.back() << endl;
                dq.pop_back();
            }
            else
                cout << "error\n";
        }

        if(command == "front"){
            if(!dq.empty())
                cout << dq.front() << endl;
            else
                cout << "error\n";
        }

        if(command == "back"){
            if(!dq.empty())
                cout << dq.back() << endl;
            else
                cout << "error\n";
        }

        if(command == "size")
            cout << dq.size() << endl;

        if(command == "clear"){
            dq.clear();
            cout << "ok\n";
        }

        if(command == "exit"){
            cout << "bye";
            return 0;
        }
    }
}