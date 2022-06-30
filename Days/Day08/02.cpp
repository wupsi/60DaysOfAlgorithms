#include <iostream>
using namespace std;

int main(){

    int n = 16, x;
    int arr[n] = {1, 2, 4, 5, 7, 8, 9, 11, 12, 14, 16, 18, 21, 24, 27, 30};
    cin >> x;

    int first = 0;
    int last = n - 1;
    int mid;

	while(true){
		mid = (first + last) / 2;						    // Находим центр

        if(x < arr[first] or x > arr[last]){                // Если искомое число больше максимума или меньше минимума массива
            cout << x <<  " not found...";                  // Значит его в массиве нет
            break;                                          // Завершаем цикл
        }

        if(first > last){                                   // Если искомого числа нету между элементами
            cout << x <<  " not found...";                  // Это говорит о том, что first завалил за last
            break;                                          // Завершаем цикл
        }

		if(x > arr[mid])								    // Если искомое число больше mid-элемента
			first = mid + 1;							    // Соответственно число находится в правой части массива
		else if(x < arr[mid])							    // Если искомое число меньше mid-элемента
			last = mid - 1;								    // Значит число в левой части массива
		else{											    // Если число не больше, не меньше, значит оно равно, и мы нашли искомое число
			cout << x << " found on pos " << mid << "!";
			break;										    // Завершаем цикл
		}
	}
}

