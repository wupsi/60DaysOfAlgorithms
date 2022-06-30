#include <iostream>
using namespace std;

int main(){
    
    int n, k, x, start, endd;
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
        bool found = false;
        int pos = 0, val = 0, first, second;
        
        while(true){
            if(x < arr[start] or x > arr[endd]){
                found = false;
                break;
            }
            if(start > endd){
                found = false;
                break;
            }

            if(x < arr[(start + endd) / 2]) endd = (start + endd) / 2 - 1;
            else if(x > arr[(start + endd) / 2]) start = (start + endd) / 2 + 1;
            else{
                pos = (start + endd) / 2;
                val = arr[(start + endd) / 2];
                found = true;
                break;
            }
        }

        if(found){
            int f = pos, s = pos;
            while(true){
                f--;
                if(f < 0) break;
                if(arr[f] != val) break;
            }
            first = f + 1;

            while(true){
                s++;
                if(s >= n) break;
                if(arr[s] != val) break;
            }
            second = s - 1;
            cout << first+1 << " " << second+1 << endl;
        }
        else cout << "0\n";
    }
}