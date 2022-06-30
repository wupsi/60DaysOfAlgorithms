#include <iostream>
using namespace std;

int main(){

    int n = 5, x; 
    cin >> x;
    int arr[n] = {1, 2, 3, 4, 5};

    for(int i = 0; i < n; i++){
        if(x == arr[i]){
            cout << x << " found on pos " << i << "!";
            return 0;
        }
    }
    cout << x << " not found...";
}