#include <iostream>
using namespace std;

int main(){

    int n; cin >> n;
    int arr[n + 1];

    for(int i = 0; i <= n; i++)
        arr[i] = -1;
    arr[1] = 1;

    int factors[n + 1];
    factors[0] = 1;
    int p = 1, sizeFactors = 1;
    while(p < n){
        p++;
        if(arr[p] == -1){
            double l = float(n) / p;
            int secondFactors[n + 1];
            int sizeSecondFactors = 0;
            for(int i = 0; i < sizeFactors; i++){
                int j = factors[i];
                while(j <= l){
                    secondFactors[sizeSecondFactors++] = j;
                    arr[j * p] = arr[j] + arr[factors[i]];
                    j *= p;
                }
            }

            for(int i = 0; i < sizeSecondFactors; i++)
                factors[i] = secondFactors[i];
            sizeFactors = sizeSecondFactors;
        }
    }

    int ans = 0;
    for(int i = 0; i <= n; i++)
        if(arr[i] == 3 or arr[i] == 4) ans++;

    cout << ans;
}