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
  
	int n = 7;
	int arr[n] = {1, 7, 5, 4, 2, 8, 0};
	  
	QuickSort(arr, 0, n - 1);
	
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
