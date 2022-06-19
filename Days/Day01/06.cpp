#include <iostream>
using namespace std;

int findAllNumbersGreater(int arr[], int n, int value){
	int size = 0;
	int newArr[n];
	for(int i = 0; i < n; i++)
		if(arr[i] > value)
			newArr[size++] = arr[i];
	
	return newArr;
}

int main(){

    int value = 3;
    int arr[5] = {1, 2, 3, 4, 5};
    
    int resultArr = findAllNumbersGreater(arr, 5, value);

}