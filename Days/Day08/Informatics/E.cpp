#include <iostream>
using namespace std;

int main(){
    int n, maxf = 0, maxs = 0; cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++){ 
        cin >> arr[i];
        if(arr[i] > maxf) maxf = arr[i];
    }

    for(int i = 0; i < n; i++) 
        if(arr[i] > maxs and arr[i] != maxf) maxs = arr[i];
        
    cout << maxs;
}