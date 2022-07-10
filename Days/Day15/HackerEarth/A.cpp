#include <iostream>
using namespace std;

void QuickSortAscending(long long arr[], int left, int right){
    if(left < right){
        int l = left, r = right;
        long long mid = arr[(left + right) / 2];
        while(l <= r){
            while(arr[l] < mid) l++;
            while(arr[r] > mid) r--;
            if(l <= r) swap(arr[l++], arr[r--]);
        }
        QuickSortAscending(arr, left, r);
        QuickSortAscending(arr, l, right);
    }
}

void QuickSortDescending(long long arr[], int left, int right){
    if(left < right){
        int l = left, r = right;
        long long mid = arr[(left + right) / 2];
        while(l <= r){
            while(arr[l] > mid) l++;
            while(arr[r] < mid) r--;
            if(l <= r) swap(arr[l++], arr[r--]);
        }
        QuickSortDescending(arr, left, r);
        QuickSortDescending(arr, l, right);
    }
}

int main(){

    int n; cin >> n;
    long long diff = 0;
    long long Bob[n], James[n];

    for(int i = 0; i < n * 2; i++)
        if(i < n) cin >> Bob[i];
        else cin >> James[i - n];

    QuickSortDescending(Bob, 0, n - 1);
    QuickSortAscending(James, 0, n - 1);

    for(int i = 0; i < n; i++)
        if(Bob[i] > James[i]) diff += Bob[i] - James[i];

    cout << diff;
}