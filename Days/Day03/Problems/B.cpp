#include <iostream>
using namespace std;

struct queue{

private:
    int start, finish;
    int arr[100000];

public:
    queue(){
        start = 0;
        finish = 0;
    }

    void push(int x){
        arr[finish++] = x;
    }

    void pop(){
        if(!empty())
            start++;
        else 
            cout << "ERROR\n";
    }

    int front(){
        if(!empty())
            return arr[start];
        else
            return -9999999;
    }

    int back(){
        if(!empty())
            return arr[finish - 1];
        else
            return -9999999;
    }

    int size(){
        return finish - start;
    }

    bool empty(){
        return finish - start <= 0;
    }

    void clear(){
        start = 0;
        finish = 0;
    }

};

int main(){

    queue q;

    while(true){
        
        string command; cin >> command;

        if(command == "push"){
            int n; cin >> n;
            q.push(n);
            cout << "ok\n";
        }

        if(command == "pop"){
            if(!q.empty()){
                cout << q.front() << endl;
                q.pop();
            }
            else
                cout << "error\n";
        }

        if(command == "front"){
            if(!q.empty())
                cout << q.front() << endl;
            else
                cout << "error\n";
        }

        if(command == "size")
            cout << q.size() << endl;

        if(command == "clear"){
            q.clear();
            cout << "ok\n";
        }

        if(command == "exit"){
            cout << "bye";
            return 0;
        }
    }
}