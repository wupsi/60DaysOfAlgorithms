#include <iostream>
using namespace std;

int  binarySearch(int arr[],  int l,  int r,  int x){
	if(r >= l){  
		int mid = l + (r - l) / 2;
		if(arr[mid] == x) 
			return mid;  
		if  (arr[mid]  > x)  
			return  binarySearch(arr, l, mid -  1, x);
		return  binarySearch(arr, mid +  1, r, x);  
	}  
	return -1;  
}

int main(){
	
	int x = 36, n = 15;
	int nums[n] = {1, 2, 3, 4, 6, 8, 10, 15, 22, 25, 27, 30, 36, 45, 47};

    cout << "Index of " << x << " in array: " << binarySearch(nums, 0, n - 1, x);
}
