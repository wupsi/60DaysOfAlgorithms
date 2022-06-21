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

};

int main(){

    queue q;

    q.push(1);                                                      // [1]
    q.push(2);                                                      // [2, 1]
    q.push(3);                                                      // [3, 2, 1]
    cout << "Queue size: " << q.size() << endl;                     // 3
    cout << "Front: " << q.front() << endl;                         // 1
    q.pop();                                                        // [3, 2]
    q.push(4);                                                      // [4, 3, 2]
    q.push(5);                                                      // [5, 4, 3, 2]
    cout << "Front: " << q.front() << endl;                         // 2
    cout << "Back: " << q.back() << endl;                           // 5
    q.pop();                                                        // [5, 4, 3]
    q.push(6);                                                      // [6, 5, 4, 3]
    q.push(7);                                                      // [7, 6, 5, 4, 3]
    cout << "Front: " << q.front() << endl;                         // 3
    q.pop();                                                        // [7, 6, 5, 4]
    cout << "Queue is empty? " << (q.empty() ? "YES\n" : "NO\n");   // NO
    cout << "Front: " << q.front() << endl;                         // 4
    q.pop();                                                        // [7, 6, 5]
    cout << "Front: " << q.front() << endl;                         // 5
    q.pop();                                                        // [7, 6]
    cout << "Size: " << q.size() << endl;                           // 2
    cout << "Front: " << q.front() << endl;                         // 6
    cout << "Back: " << q.back() << endl;                           // 7
    q.pop();                                                        // [7]
    cout << "Front: " << q.front() << endl;                         // 7
    q.pop();                                                        // []
    cout << "Front: " << q.front() << endl;                         // -9999999
}