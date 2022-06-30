#include <iostream>
using namespace std;

int main(){
    
    int n, k, x, start, endd;
    bool found = false;
    cin >> n >> k;
    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> x;
        arr[i] = x;
    }

    for(int i = 0; i < k; i++){
        cin >> x;
        start = 0;
        endd = n - 1;
        
        while(true){
            if(x < arr[start] or x > arr[endd]){
                cout << "NO\n";
                break;
            }
            if(start > endd){
                cout << "NO\n";
                break;
            }

            if(x < arr[(start + endd) / 2]) endd = (start + endd) / 2 - 1;
            else if(x > arr[(start + endd) / 2]) start = (start + endd) / 2 + 1;
            else{
                cout << "YES\n";
                break;
            }
        }
    }
}