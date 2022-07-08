/*      Первый шаг - вызываем mergeSort() в главной функции                     48 строка
        Второй шаг - делим массив на все возможные подмассивы в MergeSort()     37, 38 строки    
        Третий шаг - применяем слияние всем разделенным массивам                39 строка
*/

#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right){            // Функция слияния

    int leftSize = mid - left + 1, rightSize = right - mid;     // Инициализируем размеры текущих массивов
    int leftArr[leftSize];                                      // С каждым введенным массивом отрезок отличается,
    int rightArr[rightSize];                                    // соответственно размер массива не всегда одинаковый
                                                                // Объявляем массивы для левой и правой стороны массива
    for(int i = 0; i < leftSize; i++)                           
        leftArr[i] = arr[left + i];                             // Заполняем левый массив
    for(int i = 0; i < rightSize; i++)
        rightArr[i] = arr[mid + 1 + i];                         // Заполняем правый массив

    int indexLeft = 0, indexRight = 0, indexArr = left;         // Те самые указатели на начало массивов
                                                                // Также нам понадобится индекс текущего массива 'indexArr'
                                                                
    while(indexLeft < leftSize and indexRight < rightSize)      // Пока не дойдем до конца одного из массивов
        if(leftArr[indexLeft] <= rightArr[indexRight])          // Берем наименьший элемент из левого и правого массива,
            arr[indexArr++] = leftArr[indexLeft++];             // записываем в текущий массив,
        else                                                    // параллельно увеличивая индексы
            arr[indexArr++] = rightArr[indexRight++];
    
                                                                // Массивы на пустоту проверять не будем, вместо этого                                 
    while(indexLeft < leftSize)                                 // Пока левый массив не пуст
        arr[indexArr++] = leftArr[indexLeft++];                 // добавляем в текущий массив элементы левого массива
    while(indexRight < rightSize)                               // Пока правый массив не пуст
        arr[indexArr++] = rightArr[indexRight++];               // добавляем в текущий массив элементы левого массива
}

void mergeSort(int arr[], int start, int finish){               // Каждый раз делим массив, 
    if(start < finish){                                         // пока условие верно
        int mid = (start + finish) / 2;                         // Центр массива
        mergeSort(arr, start, mid);                             // Левая часть массива в отрезке [start, mid]
        mergeSort(arr, mid + 1, finish);                        // Правая часть массива в отрезке [mid + 1, finish]
        merge(arr, start, mid, finish);                         // Слияние массива
    }
}

int main(){

    int n = 7;
    int arr[n] = {7, 5, 1, 4, 2, 8, 0};

    mergeSort(arr, 0, n - 1);                                   // Передаем массив, индексы начала и конца массива

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}