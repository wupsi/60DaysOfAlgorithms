#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right){
    int leftSize = mid - left + 1, rightSize = right - mid;
    int indexLeft = 0, indexRight = 0, indexArr = left;
    int leftArr[leftSize];
    int rightArr[rightSize];

    for(int i = 0; i < leftSize; i++)
        leftArr[i] = arr[left + i];
    for(int i = 0; i < rightSize; i++)
        rightArr[i] = arr[mid + 1 + i];

    while(indexLeft < leftSize and indexRight < rightSize)
        if(leftArr[indexLeft] <= rightArr[indexRight])
            arr[indexArr++] = leftArr[indexLeft++];
        else
            arr[indexArr++] = rightArr[indexRight++];
    

    while(indexLeft < leftSize)
        arr[indexArr++] = leftArr[indexLeft++];
    while(indexRight < rightSize)
        arr[indexArr++] = rightArr[indexRight++];
}

void mergeSort(int arr[], int start, int finish){
    if(start < finish){
        int mid = (start + finish) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, finish);
        merge(arr, start, mid, finish);
    }
}

int main(){

    int n; cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}