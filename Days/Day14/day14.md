# Merge Sort - Day 14
![Sparta Leonidas Meme - Imgflip](https://i.imgflip.com/1pebsf.jpg)

## Problems

- [✔️] [A. Объединение последовательностей](https://informatics.msk.ru/mod/statements/view.php?chapterid=1442#1)
- [✔️] [B. Сортировка слиянием](https://informatics.msk.ru/mod/statements/view.php?chapterid=766#1)
- [✔️] [C. Похожие массивы](https://informatics.msk.ru/mod/statements/view.php?chapterid=767#1)
- [✔️] [D. Разные](https://informatics.msk.ru/mod/statements/view.php?chapterid=1418#1)

## Merge Sort

**Сортировка слиянием** - одна из быстрейших сортировок, которая работает за время `O(nlog(n))`. Идея сортировки слиянем очень проста - допустим есть некий массив:
`[7, 5, 1, 4, 2, 8, 0]`

**Первое** - разделим массив пополам: `[7, 5, 1] | [4, 2, 8, 0]`
**Второе** - отсортируем каждый из массивов: `[1, 5, 7] | [0, 2, 4, 8]`
**Третье** - объединим массивы, что и называется слиянием(merge).

**Слияние** происходит следующим образом:
	Берем 2 отсортированных массива, к примеру те же `[1, 5, 7]` и `[0, 2, 4, 8]`

- Ставим указатели на первые элементы массивов: 
	- `leftArr = [1, 5, 7];  i = 0 -> leftArr[i] = 1;`
	- `rightArr = [0, 2, 4, 8]; j = 0 -> rightArr[j] = 0;`
	*Здесь `i, j` - указатели на первый элемент массива.*
- Сравниваем значения указателей, меньший из них будет значением нового массива:
	- `leftArr[i] > rightArr[j]` `-> newArr = [0];`
- Увеличиваем указатель, значение которого присвоено новому массиву:
	- `j++;`
- Заново сравниваем элементы `leftArr[]` и `rightArr[]`, пока один из них не будет пуст:
	- `leftArr = []; rightArr = [8]`
- После этих сравнений окажется, что один из массивов мы уже в новый записали, а в другом мы часть записали, часть еще осталась. Естественно, все оставшиеся элементы мы запишем в конец нового массива.

Теперь возникает логичный вопрос - как мы отсортировали массив после деления поровну? `[7, 5, 1] | [4, 2, 8, 0]` `->` `[1, 5, 7] | [0, 2, 4, 8]`
Для того, чтобы отсортировать оставшийся массив мы делим получившиеся 2 массива опять, до тех пор, пока там не окажется по 1 элементу:
-  `[7, 5, 1] | [4, 2, 8, 0]`
-  `[7] | [5, 1] | [4, 2] | [8, 0]`
-  `[7] | [5], [1] | [4], [2] | [8], [0]`
*И на данном этапе применяем слияние(пока не получится один единый массив):*
-  `[7] | [5], [1] | [4], [2] | [8], [0]`
-  `[7] | [1, 5] | [2, 4] | [0, 8]`
-  `[1, 5, 7] | [0, 2, 4, 8]`
-  `[0, 1, 2, 4, 5, 7, 8]`


Чуть подробнее расписал в коде:
```
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
```
Задачки сегодня не успел, порешаю завтра

## Использованные материалы
- [Merge Sort](https://www.geeksforgeeks.org/merge-sort/)
- [Алгоритмы поиска и сортировки: Сортировка слиянием](https://www.youtube.com/watch?v=wQMSowIS2FY)
- [Merge Sort Algorithm](https://www.programiz.com/dsa/merge-sort)
- [Сортировка слиянием в python](https://www.youtube.com/watch?v=LCfwxi2RPK4)