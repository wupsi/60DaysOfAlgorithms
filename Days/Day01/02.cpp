#include <iostream>
using namespace std;

int main(){
	
	int n = 5, sum = 0;
	int arr[n] = {1, 2, 3, 4, 5};
	int lastElement = arr[n - 1];
	// наш последний элемент

    cout << lastElement * (lastElement + 1) / 2;
}