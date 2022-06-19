#include <iostream>
using namespace std;

int main(){
	
	int sum = 0;
	int arr[5] = {4, 2, 3, 5, 1};

	for(int i = 0; i < 5; i++){
		sum = sum + arr[i];
	}
	
	cout << sum;
}