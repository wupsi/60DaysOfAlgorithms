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

    deque dq;                   // []

    dq.push_back(1);            // [1]
    dq.push_back(2);            // [1, 2]
    dq.push_back(3);            // [1, 2, 3]
    dq.push_front(4);           // [4, 1, 2, 3]
    dq.push_front(5);           // [5, 4, 1, 2, 3]
    dq.push_front(6);           // [6, 5, 4, 1, 2, 3]

    cout << "Deque size: " << dq.size() << endl;    // 6
    cout << "Deque front: " << dq.front() << endl;  // 6
    cout << "Deque back: " << dq.back() << endl;    // 3
    dq.print();                                     // 6 5 4 1 2 3
    dq.pop_back();                                  // [6, 5, 4, 1, 2]
    dq.print();                                     // 6 5 4 1 2
    dq.pop_front();                                 // [5, 4, 1, 2]
    cout << "Deque front: " << dq.front() << endl;  // 5
    cout << "Deque back: " << dq.back() << endl;    // 2
    dq.print();                                     // 5 4 1 2

    dq.push_back(7);                                // [5, 4, 1, 2, 7]
    dq.push_back(8);                                // [5, 4, 1, 2, 7, 8]
    dq.print();                                     // 5 4 1 2 7 8
    dq.pop_front();                                 // [4, 1, 2, 7, 8]
    dq.pop_front();                                 // [1, 2, 7, 8]
    dq.pop_front();                                 // [2, 7, 8]
    dq.pop_front();                                 // [7, 8]
    dq.print();                                     // 7 8
    dq.pop_back();                                  // [7]
    
    cout << "Deque size: " << dq.size() << endl;    // 1
    dq.pop_back();                                  // []
    cout << "Deque is empty? ";
    cout << (dq.empty() ? "YES\n" : "NO\n");        // YES
    dq.pop_front();                                 // ERROR
    dq.pop_back();                                  // ERROR
    cout << "Deque front: " << dq.front() << endl;  // -9999999
    cout << "Deque back: " << dq.back() << endl;    // -9999999
    cout << "Deque size: " << dq.size() << endl;    // 0

    dq.push_back(9);                                // [9]
    dq.push_front(10);                              // [10, 9]
    dq.print();                                     // 10 9
    dq.clear();                                     // []
    dq.print();                                     // 
}