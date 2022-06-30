## Linear, binary search - Day 8 

Сегодня рассмотрим довольно легкую, но немаловажную тему - **Линейный и Бинарный(Двоичный) поиск.** 

## Problems
  
### Informatics:

- [✔️] [A. Линейный поиск - 3](https://informatics.msk.ru/mod/statements/view.php?chapterid=226#1)
- [✔️] [B. Максимальный элемент массива](https://informatics.msk.ru/mod/statements/view.php?chapterid=227#1)
- [✔️] [C. Номер максимального элемента массива](https://informatics.msk.ru/mod/statements/view.php?chapterid=228#1)
- [✔️] [D. Матрица](https://informatics.msk.ru/mod/statements/view.php?chapterid=1427#1)
- [✔️] [E. Серебряная медаль](https://informatics.msk.ru/mod/statements/view.php?chapterid=1440#1)
- [✔️] [F. Контроперация](https://informatics.msk.ru/mod/statements/view.php?chapterid=1447#1)
- [✔️] [G. Двоичный поиск](https://informatics.msk.ru/mod/statements/view.php?chapterid=4#1)
- [✔️] [H. Сложность двоичного поиска](https://informatics.msk.ru/mod/statements/view.php?chapterid=3#1)
- [✔️] [I. Левый и правый двоичный поиск](https://informatics.msk.ru/mod/statements/view.php?chapterid=111728#1)
  
### Leetcode:

- [❌] [A. Search Insert Position](https://leetcode.com/problems/search-insert-position/)
- [❌] [B. Sqrt(x)](https://leetcode.com/problems/sqrtx/)
- [❌] [C. First Bad Version](https://leetcode.com/problems/first-bad-version/)
- [❌] [D. Intersection Of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/)
- [❌] [E. Intersection Of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/)
- [❌] [F. Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square/)
- [❌] [G. Guess Number Higher Or Lower](https://leetcode.com/problems/guess-number-higher-or-lower/)
- [❌] [H. Arranging Coins](https://leetcode.com/problems/arranging-coins/)
- [❌] [I. Find Smallest Letter Greater Than Target](https://leetcode.com/problems/find-smallest-letter-greater-than-target/)

## Linear search

Линейный поиск - алгоритм нахождения искомого элемента внутри какого-либо отрезка значений. Этот алгоритм является простейшим алгоритмом поиска. Из-за малой эффективностью по сравнению с другими алгоритмами линейный поиск обычно используют, только если отрезок поиска содержит очень мало элементов, тем не менее, линейный поиск не требует дополнительной памяти или обработки/анализа функции, так что может работать в потоковом режиме при непосредственном получении данных из любого источника. Также линейный поиск часто используется в виде линейных алгоритмов поиска максимума или минимума.

## Реализация

```
int  main(){
  
	int n = 5, x;
	cin >> x;
	int arr[n] = {1, 2, 3, 4, 5};
	
	for(int i = 0; i < n; i++){
		if(x == arr[i]){
			cout << x << " found on pos " << i << "!";
			return 0;
		}
	}
	cout << x << " not found...";
}
```
### Test #1
```
Input:
3
Output:
3 found on pos 2!
```

### Test #2
```
Input:
6
Output:
6 not found...
```
В линейном поиске мы всегда проходимся по всем элементам пока не найдем искомый элемент. И в самом худшем случае, когда искомый элемент окажется в конце контейнера(в нашем случае массива), у нас получится n операции, что равно размеру контейнера. Из этого мы получаем асимптотику `O(n)`. 


## Binary Search

**Бинарный поиск** — алгоритм с не сложной реализацией, который находит элемент с определенным значением в уже отсортированном массиве. 

В отличии от линейного поиска он очень быстр, но работает только с отсортированными массивами. При бинарном поиске искомый ключ сравнивается с ключом среднего элемента в массиве. Если они равны, то поиск успешен. В противном случае поиск осуществляется в левой или правой части в зависимости от того, где наш ключ может быть. Например, если в массиве 1024 элемента, в худшем случае мы бы произвели 1024 операции в линейном поиске. А с бинарным поиском мы обойдемся в 10 операции(в худшем случае), что равно асимптотике `O(log(n))`. 

### Реализация

Возьмем отсортированный массив размером 16 и искомый элемент x, который введем в терминале.
```
int main{

	int n = 16, x;
	int arr[n] = {1, 2, 4, 5, 7, 8, 9, 11, 12, 14, 16, 18, 21, 24, 27, 30};
	cin >> x;
}
```
Тогда наш массив:
![](https://www.linkpicture.com/q/sortedArray.png)

Теперь определим левую, правую и центральные части индексов массива. Ими будут `first`, `last` и `mid`. 

```
int main{

	int n = 16, x;
	int arr[n] = {1, 2, 4, 5, 7, 8, 9, 11, 12, 14, 16, 18, 21, 24, 27, 30};
	cin >> x;
	
	int first = 0;
	int last = n - 1;
	int mid;
}
```

`mid` пока не определен. Но визуально мы можем представить: элементов в массиве четное количество, поэтому пусть центром массива будет элемент под индексом `arr[7]`:

![](https://www.linkpicture.com/q/leftright.png)

Теперь надо понять саму суть бинарного поиска. Пока мы не дойдем до искомого числа, будем разделять массив на 2, и брать только ту часть, в которой потенциально может быть искомое число.
Допустим искомое число будет `x = 27`.   Тогда `x` больше чем центр массива(`mid`). А значит, в левой части массива искомого числа быть не может(центр также не равен), и ее мы игнорируем.
![](https://www.linkpicture.com/q/mid_1.png)
Теперь отрезок начинается с 8-го элемента, а центр равен 11 элементу. 18 тоже меньше 27, поэтому опять делим отрезок на 2.
![](https://www.linkpicture.com/q/mid2.png)

И еще раз:
![](https://www.linkpicture.com/q/last_1.png)

`mid`-элемент равен искомому числу. Значит мы нашли искомое число.

Эти операции можно описать одним циклом в коде:
```
	while(true){
		mid = (first + last) / 2;					// Находим центр

		if(x > arr[mid])						// Если искомое число больше mid-элемента
			first = mid + 1;					// Соответственно число находится в правой части массива
		else if(x < arr[mid])						// Если искомое число меньше mid-элемента
			last = mid - 1;						// Значит число в левой части массива
		else{								// Если число не больше, не меньше, значит оно равно, и мы нашли искомое число
			cout << x << " found on pos " << mid << "!";
			break;							// Завершаем цикл
		}
	}
```

Учтем возможность того, что искомого числа может и не быть в массиве. Добавим условие:
```
if(first > last){
	cout << x <<  " not found...";
	break;
}
```	
В случае, когда искомого числа нет, `first` перевалит за `last`. Тогда и останавливаем цикл.
Также возможно такое, что искомое число меньше, чем наименьший элемент в массиве или больше, чем наибольший. Тогда:
```
if(x < arr[first] or x > arr[last]){
	cout << x <<  " not found...";
	break;
}

```

Итого у нас получается следующий код:
```
int main(){

    int n = 16, x;
    int arr[n] = {1, 2, 4, 5, 7, 8, 9, 11, 12, 14, 16, 18, 21, 24, 27, 30};
    cin >> x;

    int first = 0;
    int last = n - 1;
    int mid;

	while(true){
		mid = (first + last) / 2;					// Находим центр

		if(x < arr[first] or x > arr[last]){                		// Если искомое число больше максимума или меньше минимума массива
		    cout << x <<  " not found...";                  		// Значит его в массиве нет
		    break;                                          		// Завершаем цикл
		}

		if(first > last){                                   		// Если искомого числа нету между элементами
		    cout << x <<  " not found...";                  		// Это говорит о том, что first завалил за last
		    break;                                          		// Завершаем цикл
		}

		if(x > arr[mid])						// Если искомое число больше mid-элемента
			first = mid + 1;					// Соответственно число находится в правой части массива
		else if(x < arr[mid])						// Если искомое число меньше mid-элемента
			last = mid - 1;						// Значит число в левой части массива
		else{								// Если число не больше, не меньше, значит оно равно, и мы нашли искомое число
			cout << x << " found on pos " << mid << "!";
			break;							// Завершаем цикл
		}
	}
}

```

### Тесты

```
Input 1:
27
Output 1:
27 found on pos 14!

Input 2:
0
Output 2:
0 not found...

Input 3:
1
Output 3:
1 found on pos 0!
```

Запихаем в функцию:
```
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
```

Протестируем функцию на числах от 0 до 32, только теперь с нечетным кол-вом элементов:
```
int main(){

    int n = 17;
    int arr[n] = {1, 2, 4, 5, 7, 8, 9, 11, 12, 14, 16, 18, 21, 24, 27, 30, 31};
    
    for(int i = 0; i <= 32; i++)
        cout << i << (BinarySearch(arr, n, i) != -1 ? " found!\n" : " not found.\n");
}
```
`Output:`
```
0 not found.
1 found!
2 found!
3 not found.
4 found!
5 found!
6 not found.
7 found!
8 found!
9 found!
10 not found.
11 found!
12 found!
13 not found.
14 found!
15 not found.
16 found!
17 not found.
18 found!
19 not found.
20 not found.
21 found!
22 not found.
23 not found.
24 found!
25 not found.
26 not found.
27 found!
28 not found.
29 not found.
30 found!
31 found!
32 not found.
```

## Плюсы и минусы

**Плюсы:**
- Реализация алгоритма достаточна легкая
- Очень быстрая работа алгоритма

**Минусы:**

- Для поиска массив должен быть отсортирован
- Двоичный поиск должен иметь возможность обратится к любому элементу по индексу. А это значит, что все структуры данных, которые построены на связных списках использоваться не могут

## Использованные материалы
[Бинарный поиск в C++: все что вам нужно знать](https://codelessons.ru/cplusplus/algoritmy/binarnyj-poisk-po-massivu-c.html)
