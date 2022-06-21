#include <iostream>
#include <queue>
using namespace std;

int main(){

    queue<int> q;                               // []

    q.push(1);                                  // [1]
    q.push(2);                                  // [2, 1]
    q.push(3);                                  // [3, 2, 1]
    q.push(4);                                  // [4, 3, 2, 1]
    cout << "Front: " << q.front() << endl;     // 1
    q.pop();                                    // [4, 3, 2]
    cout << "Front: " << q.front() << endl;     // 2
    q.pop();                                    // [4, 3]
    cout << "Front: " << q.front() << endl;     // 3
    cout << "Back: " << q.back() << endl;       // 4
}