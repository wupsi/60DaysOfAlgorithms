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

int main(){

    int n = 17;
    int arr[n] = {1, 2, 4, 5, 7, 8, 9, 11, 12, 14, 16, 18, 21, 24, 27, 30, 31};
    
    for(int i = 0; i <= 32; i++)
        cout << i << (BinarySearch(arr, n, i) != -1 ? " found!\n" : " not found.\n");
}

