#include <iostream>
using namespace std;

int main(){
    int n, max = -1e9, min = 1e9; cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++){ 
        cin >> arr[i];
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
    }
    for(int i = 0; i < n; i++)
        cout << (arr[i] == max ? min : arr[i]) << " ";
}