#include <iostream>
using namespace std;

void QuickSort(int arr[], int left, int right){
    if(left < right){
        int l = left, r = right;
        int mid = arr[(left + right) / 2];
        while(l <= r){
            while(arr[l] < mid) l++;
            while(arr[r] > mid) r--;
            if(l <= r) swap(arr[l++], arr[r--]);
        }
        QuickSort(arr, left, r);
        QuickSort(arr, l, right);
    }
}

int main(){

    int n = 9;
    int arr[n] = {4, 6, 9, 5, 8, 1, 3, 7, 2};

    QuickSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}