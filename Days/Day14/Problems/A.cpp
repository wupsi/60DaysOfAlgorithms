#include <iostream>
using namespace std;

int main(){

    uint64_t x, left = 1, right = 1; cin >> x;
    uint64_t current = 0, leftVal = 1, rightVal = 1;

    while(x--){
        leftVal = left * left;
        rightVal = right * right * right;
        if(leftVal == rightVal) current = leftVal, left++, right++;
        else if(leftVal < rightVal) current = leftVal, left++;
        else current = rightVal, right++;
    }
    cout << current;
}

// A = [1, 4, 9, 16, 25, 36, 49, 64, 81, 100,..]
// B = [1, 8, 27, 64, 125, 216, 343, 512, 729, 1000,..]
// C = [1, 4, 8, 9, 16, 25, 27, 36, 49, 64, 81, 100, 125, 216, 343, 512, 729, 1000,..]