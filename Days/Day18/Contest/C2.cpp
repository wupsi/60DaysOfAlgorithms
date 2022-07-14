#include <iostream>
using namespace std;

int BinarySearch(int array[], int size, int value){
    int first = 0, last = size - 1, mid;

	while(true){
		mid = (first + last) / 2;

        if(value < array[first] or value > array[last] or first > last)
            return -1;

		if(value > array[mid])
			first = mid + 1;
		else if(value < array[mid])
			last = mid - 1;
		else
            return mid;
	}
}

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

int Search(int satisfied[], int cnt, int arr[], int size, int left, int right){
    int leftPos = -1;
    while(left <= right){                                                           // O((right - left) log(n))
        if(left > arr[size - 1]) break;
        int pos = BinarySearch(arr, size, left);
        if(pos != -1){
            leftPos = pos;
            break;
        }
        left++;
    }
    if(leftPos != -1)                                                               // O(cnt log(n))
        while(leftPos < size and arr[leftPos] <= right){
            if(BinarySearch(satisfied, cnt, arr[leftPos]) == -1)
                satisfied[cnt++] = arr[leftPos];
            leftPos++;
        }

    return cnt;
}

int main(){

    int n, q; cin >> n >> q;
    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    QuickSort(arr, 0, n - 1);                                       // O(n log(n))

    for(int i = 0; i < q; i++){
        int cnt = 0, left1, right1, left2, right2;
        int satisfied[n];
        cin >> left1 >> right1 >> left2 >> right2;

        cnt = Search(satisfied, cnt, arr, n, left1, right1);        // O((right - left)log(n) + cnt log(n))
        cnt = Search(satisfied, cnt, arr, n, left2, right2);
        cout << cnt << endl;
    }
}

// 1 2 3 5 8 13 21

// [1, 3], [2, 8]