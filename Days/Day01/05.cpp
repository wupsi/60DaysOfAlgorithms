#include <iostream>
using namespace std;

int findIndexByValue(int arr[], int n, int value){
	int result = -1; 
	for(int i = 0; i < n; i++){
		if(arr[i] == value){
			result = i; 
		}
	}
	return result; 
}

int main(){

    int value = 3;
    int arr[5] = {1, 2, 3, 4, 5};
    
    cout << findIndexByValue(arr, 5, value);
}