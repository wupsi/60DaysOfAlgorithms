#include <iostream>
#include <cmath>
using namespace std;

int intlog(double x) {
    return ceil((log(x) / log(2)));
}

int main(){

    int n; cin >> n;
    cout << intlog(n);
    
    // int n, i = 0; cin >> n;
    // int start = 0, endd = n - 1;
    
    // while(true){
    //     if(start > endd){
    //         cout << i;
    //         return 0;
    //     }
    //     i++;
    //     if(n < (start + endd) / 2) endd = (start + endd) / 2 - 1;
    //     else if(n > (start + endd) / 2) start = (start + endd) / 2 + 1;
    //     else{
    //         cout << i;
    //         return 0;
    //     }
    // }
}