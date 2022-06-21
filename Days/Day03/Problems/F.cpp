#include <iostream>
#include <deque>
using namespace std;

deque<int> first, second;

void firstwin(){
    first.push_back(first.front());
    first.push_back(second.front());
    first.pop_front();
    second.pop_front();
}

void secondwin(){
    second.push_back(first.front());
    second.push_back(second.front());
    second.pop_front();
    first.pop_front();
}

int main(){

    int step = 0;

    for(int i = 0; i < 10; i++){
        int card; cin >> card;
        if(i < 5) first.push_back(card);
        else second.push_back(card);
    }

    while(step <= 1000000){

        if(first.empty()){
            cout << "second " << step;
            return 0;
        }
        if(second.empty()){
            cout << "first " << step;
            return 0;
        }

        if(first.front() == 0 and second.front() == 9) firstwin();
        else if(second.front() == 0 and first.front() == 9) secondwin();
        else{
            if(first.front() > second.front()) firstwin();
            else secondwin();
        }

        step++;
    }

    cout << "botva";
}

// 0. 
// [1, 3, 5, 7, 9]
// [2, 4, 6, 8, 0]

// 1. 
// [3, 5, 7, 9]
// [4, 6, 8, 0, 1, 2]

// 2. 
// [5, 7, 9]
// [6, 8, 0, 1, 2, 3, 4]

// 3.
// [7, 9]
// [8, 0, 1, 2, 3, 4, 5, 6]

// 4.
// [9]
// [0, 1, 2, 3, 4, 5, 6, 7, 8]

// 5.
// []
// [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]

// ans: second 5


// Input:
// 1 2 3 4 0
// 5 6 7 8 9

// 0.
// [1, 2, 3, 4, 0]
// [5, 6, 7, 8, 9]

// 1.
// [2, 3, 4, 0]
// [6, 7, 8, 9, 1, 5]

// 2. 
// [3, 4, 0]
// [7, 8, 9, 1, 5, 2, 6]

// 3. 
// [4, 0]
// [8, 9, 1, 5, 2, 6, 3, 7]

// 4.
// [0]
// [9, 1, 5, 2, 6, 3, 7, 4, 8]

// 5.
// [0, 9]
// [1, 5, 2, 6, 3, 7, 4, 8]

// 6. 
// [9]
// [5, 2, 6, 3, 7, 4, 8, 0, 1]

// 7.
// [9, 5]
// [2, 6, 3, 7, 4, 8, 0, 1]

// 8. 
// [5, 9, 2]
// [6, 3, 7, 4, 8, 0, 1]

// 9.
// [9, 2]
// [3, 7, 4, 8, 0, 1, 5, 6]

// 10.
// [2, 9, 3]
// [7, 4, 8, 0, 1, 5, 6]

// 11.
// [9, 3]
// [4, 8, 0, 1, 5, 6, 2, 7]

// 12.
// [3, 9, 4]
// [8, 0, 1, 5, 6, 2, 7]

// 13.
// [9, 4]
// [0, 1, 5, 6, 2, 7, 3, 8]

// 14.
// [4]
// [1, 5, 6, 2, 7, 3, 8, 9, 0]

// 15.
// [4, 1]
// [5, 6, 2, 7, 3, 8, 9, 0]

// 16.
// [1]
// [6, 2, 7, 3, 8, 9, 0, 4, 5]

// 17.
// []
// [2, 7, 3, 8, 9, 0, 4, 5, 1, 6]

// ans: second 17