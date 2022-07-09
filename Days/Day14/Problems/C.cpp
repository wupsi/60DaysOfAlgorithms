#include <iostream>
using namespace std;

int newLeftArr[1000001];
int newRightArr[1000001];

int removeSameLeft(int arr[], int size){
    int newSize = 0;

    for(int i = 0; i < size - 1; i++)
        if(arr[i] < arr[i + 1]) newLeftArr[newSize++] = arr[i]; 

    if(size > 1 and arr[size - 1] > arr[size - 2]) newLeftArr[newSize++] = arr[size - 1];
    return newSize;
}

int removeSameRight(int arr[], int size){
    int newSize = 0;

    for(int i = 0; i < size - 1; i++)
        if(arr[i] < arr[i + 1]) newRightArr[newSize++] = arr[i]; 

    if(size > 1 and arr[size - 1] > arr[size - 2]) newRightArr[newSize++] = arr[size - 1];
    return newSize;
}

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
    int leftArr[n];

    for(int i = 0; i < n; i++)
        cin >> leftArr[i];

    int m; cin >> m;
    int rightArr[m];
    for(int i = 0; i < m; i++)
        cin >> rightArr[i];

    mergeSort(leftArr, 0, n - 1);
    mergeSort(rightArr, 0, m - 1);

    int leftSize = removeSameLeft(leftArr, n);
    int rightSize = removeSameRight(rightArr, m);

    if(leftSize != rightSize){
        cout << "NO";
        return 0;
    }

    for(int i = 0; i < leftSize; i++)
        if(newLeftArr[i] != newRightArr[i]){
            cout << "NO";
            return 0;
        }
    cout << "YES";
}
