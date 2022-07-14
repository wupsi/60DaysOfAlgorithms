#include <iostream>
// #include <cstdio>
// #include <ctime>
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

    int n, k; cin >> n >> k;
    int arr[n];

    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        arr[i] = max(x2, y2);
    }
    // double duration;
    // clock_t start = clock();

    QuickSort(arr, 0, n - 1);

    cout << arr[k - 1];

    // duration = (clock() - start) / (double)CLOCKS_PER_SEC;
    // cout << endl << duration;
}

// то шо в скобках измеряет затраченное время на выполнение программы