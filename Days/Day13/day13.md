# Heap Sort - Day 13

![](https://habrastorage.org/r/w1560/webt/qh/xz/os/qhxzos7q9w_r0prbkjurx1akd0m.png)Пирамидальная сортировка (или сортировка кучей, **HeapSort**) — это метод сортировки сравнением, основанный на такой структуре данных как двоичная куча. При этой сортировке сначала строится пирамида из элементов исходного массива. Пирамида (или двоичная куча) — это способ представления элементов, при котором от каждого узла может отходить не больше двух ответвлений. А значение в родительском узле должно быть больше значений в его двух дочерних узлах.
![](https://avatars.mds.yandex.net/get-media-platform/1619812/c65e0acc-f342-4689-8791-f5a01a2402cc/orig)

Для того, чтобы полноценно разобраться в сортировке, разберемся, что из себя представляет **Двоичная куча**, а затем уже перейдем к самой сортировке.

## Problems

- [✔️] [A. Пирамидальная сортировка](https://informatics.msk.ru/mod/statements/view3.php?id=&chapterid=754#1)
- [✔️] [B. Хипуй!](https://informatics.msk.ru/mod/statements/view.php?chapterid=755#1)
- [❌] [C. Минимум в окне](https://informatics.msk.ru/mod/statements/view.php?chapterid=756#1)

## Heap
**Двоичная куча (Heap)** – просто реализуемая структура данных, предназначенная для нахождения минимального или максимального элемента. Тоесть она оптимизирована под то, чтобы быстро(за логарифмическое время) находить максимальный/минимальный элемент в наборе данных.
К примеру возьмем такую кучу:
![](https://avatars.mds.yandex.net/get-media-platform/1619812/c65e0acc-f342-4689-8791-f5a01a2402cc/orig)

Максимум в куче будет храниться в верхнем элементе бинарного дерева. 
Кучу можно назвать правильной, если:
- Все уровни дерева заполнены целиком, не считая последний;
![](https://www.linkpicture.com/q/HeapSample.png)

- Последний уровень должен заполняться слева направо. Если мы хотим добавить еще один элемент:
![](https://www.linkpicture.com/q/HeapSample1.png) 

- Любое число является наибольшим относительно своих поддеревьев.
12 - наибольший во всем дереве, 10 - наибольший левого потомка 12, и т.д.

## Операции с кучей

Самые базовые операции с кучей:
- Найти максимальный элемент
- Удалить максимальный элемент
- Добавить элемент

### Постоим дерево:
```
struct maxHeap{
private:
	vector<int> mh;

public:
	int getMax();
	int extractMax();
	void insert(int x);
};
```
Для работы с кучей я использую вектор, очень удобен в нашем случае. Элементы кучи будут храниться в векторе, а позиции элементов кучи будут распологаться как показано на рисунке:
![Heap](https://aquarchitect.github.io/swift-algorithm-club/Heap/Images/LargeHeap.png)

Тоесть наш вектор в этом примере:
![](https://avatars.mds.yandex.net/get-media-platform/1619812/c65e0acc-f342-4689-8791-f5a01a2402cc/orig)
`[12, 10, 11, 5, 9, 8, 6, 1, 2, 7, 3, 4]`

Из этого можно получить последовательность:
- Родитель `i`-го элемента равен `(i - 1) / 2`
- Левое поддерево  `i`-го элемента равно `i * 2 + 1`
- Правое поддерево `i`-го элемента равно `i * 2 + 2`

```
struct maxHeap{
private:
	vector<int> v;
	
	int parent(int i){
		return (i - 1) / 2;
	}
	int left(int i){
		return i * 2 + 1;
	}
	int right(int i){
		return i * 2 + 2;
	}
	
public:
	int getMax();
	int extractMax();
	void insert(int x);
};
```


### Найти максимальный элемент

Найти максимальный элемент труда не составит, он всегда лежит на вершине дерева. 
```
int getMax(){
	return v[0];
}
```
`v` - вектор;
`0` - позиция максимального элемента(вершина кучи).

И так, мы находим максимум за `O(1)`.

### Удалить максимальный элемент

При удалении максимального элемента проходит 3 этапа:
- Меняем местами максимальный элемент с  последним элементом последнего уровня. 
![image](https://www.linkpicture.com/q/extractMaxStep1.png)

- Удаляем последний узел
![image](https://www.linkpicture.com/q/extractMaxStep2.png)

- Просеиваем замененный элемент. Просеивание в куче принято называть **heapify** и делится оно тоже на 3 этапа:
	- Если значение левого поддерева больше текущего, меняем их местами
	- Если значение правого поддерева больше левого, опять меняем их местами
	- Если оба условия верны, рекурсивно вызываем `heapify` еще раз, тем самым пройдя по всему дереву.
	Рекурсия продолжится, пока есть левое/правое поддерево и все условия верны.
```
int extractMax(){
	int root = v[0];
	swap(v[0], v[v.size() - 1]); 				// Step 1: Замена
	v.pop_back(); 								// Step 2: Удаление последнего узла
	if(!v.empty()) heapify(0); 					// Step 3: Просеивание
	return root;
}
  
void heapify(int  current){
	int temp = left(current); 												// Step 1
	if(temp > v.size() - 1) return;
	if(right(current) < v.size() and v[right(current)] > v[temp])
	temp = right(current); 													// Step 2
	  
	if(v[current] < v[temp]){
		swap(v[current], v[temp]);
		heapify(temp); 														// Step 3
	}
}
```

### Добавить элемент

Добавление элемента происходит следующим образом:
- Создаем новый элемент в конец вектора(т.е. становится последним элементом последнего уровня)
- Поднимаемся вверх по родителям элементам, пока наш текущий больше родительского:

```
void insert(int x){
	v.push_back(x);
	int current = v.size() - 1;
	  
	while(current != 0 and v[parent(current)] < v[current]){
		swap(v[parent(current)], v[current]);
		current = parent(current);
	}
}
```

## Heap Sort

И так, с кучей разобрались, теперь реализуем **Пирамидальную сортировку**.

Алгоритм следующий:
- Из данного массива построить кучу(элементы массива не всегда соответствуют правильной куче, поэтому кучу построим сами);
- После построения кучи наибольший элемент хранится в корне. Заменим наибольший элемент на последний в куче, затем уменьшим размер на 1. 

Повторяем алгоритм, пока размер кучи `> 1`.

Код получился следующий:
```
#include <iostream>
using namespace std;
  
void heapify(int arr[], int size, int root){
	int largest = root;
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	  
	if(left < size and arr[left] > arr[largest])
		largest = left;
	if(right < size and arr[right] > arr[largest])
		largest = right;
	  
	if(largest != root){
		swap(arr[root], arr[largest]);
		heapify(arr, size, largest);
	}
}
  
void heapSort(int arr[], int size){
	for(int i = size / 2 - 1; i >= 0; i--)
		heapify(arr, size, i);
  
	for(int i = size - 1; i >= 0; i--){
		swap(arr[0],arr[i]);
		heapify(arr, i, 0);
	}
}
  
int main(){
	int n = 12;
	int arr[n] = {5, 9, 1, 7, 2, 3, 11, 10, 12, 4, 8, 6};
	  
	heapSort(arr, n);
	  
	cout << "Sorted array:\n";
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
```

## Использованные материалы
- [Основные виды сортировок и примеры их реализации](https://academy.yandex.ru/posts/osnovnye-vidy-sortirovok-i-primery-ikh-realizatsii)
- [Структуры данных: двоичная куча (binary heap)](https://habr.com/ru/post/112222/)
- [Структуры данных: Куча (heap)](https://www.youtube.com/watch?v=noQ4SUoqrQA)
- [Пирамидальная сортировка (HeapSort)](https://habr.com/ru/company/otus/blog/460087/)
