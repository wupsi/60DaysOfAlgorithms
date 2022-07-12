#include <iostream>
#include <vector>
using namespace std;

void QuickSort(vector<int> &arr, int left, int right){
    if(left < right){
        int l = left, r = right;
        int mid = arr[(left + right) / 2];
        while(l <= r){
            while(arr[l] > mid) l++;
            while(arr[r] < mid) r--;
            if(l <= r) swap(arr[l++], arr[r--]);
        }
        QuickSort(arr, left, r);
        QuickSort(arr, l, right);
    }
}


int main(){

    int n; cin >> n;
    vector<int> v;
    long long all = 0;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    QuickSort(v, 0, v.size() - 1);

    while(v.size() > 1){
        int first = v[v.size() - 1], second = v[v.size() - 2];
        int sum = first + second;
        v.pop_back();
        v.pop_back();
        v.push_back(sum);
        QuickSort(v, 0, v.size() - 1);
        all += sum;
    }
    cout << all;
}