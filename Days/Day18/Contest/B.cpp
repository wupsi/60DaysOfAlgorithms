#include <iostream>
using namespace std;

void Reverse(int arr[], int size){
    for(int i = 0; i < size / 2; i++)
        swap(arr[i], arr[size -1 - i]);
}

int main(){

    int n, size = 0; cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++){
        int q; cin >> q;
        if(q == 1){
            int x; cin >> x;
            arr[size++] = x;
        }
        else Reverse(arr, size);
    }

    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

// 9
// 1 2
// 1 3
// 2
// 1 4
// 1 5
// 2
// 1 1
// 2
// 1 1

// [2, 3]
// [3, 2, 4, 5]
// [5, 4, 2, 3, 1]
// [1, 3, 2, 4, 5, 1]