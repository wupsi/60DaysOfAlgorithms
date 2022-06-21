
## Stack, Queue, Deque - Day 2

В течении следующих двух дней рассмотрим структуры данных stack, queue, deque. Разберем структуру(struct), приватность и публичность переменных и функции.

## Stack

Стек — это структура данных, которая работает по принципу **FILO** (first in - last out; первый пришел - последний ушел). В C++ уже есть готовый шаблон — `stack`. Но сегодня шаблон мы использовать не будем, вместо этого попытаемся реализовать структуру `stack` сами.

Стек имеет следующие 5 функции:
```
push(x)			Вставляет в стек x
pop() 			Удаляет верхний элемент стека
empty() 		Проверяет стек на пустоту
size() 			Возвращает размер стека
top() 			Возвращает верхний элемент стека
```
Для того, чтобы полноценно понять структуру стека, первым делом рассмотрим пример с готовым шаблоном стека:
```
int  main(){

	stack<int> st; 				// объявили стек st
	int n; cin >> n; 			// вводим n
	
	for(int i =  0; i < n; i++){		// вводим n элементов
		int num; cin >> num;
		st.push(num); 			// каждый введенный num вставляем в стек
	}
	
	while(!st.empty()){ 			// пока стек не будет пуст, делаем следующее:
		cout << st.top() <<  " "; 	// выводим верхний элемент стека
		st.pop(); 			// удаляем верхний элемент стека
	}
}
```
```
Input:
5
1 2 3 4 5

Output:
5 4 3 2 1	
```
Еще раз наглядно:
```
stack<int> st;			// объявили пустой стек []. Ниже будет содержимое стека в скобках
st.push(1);			// [1]
st.push(2);			// [2, 1]
st.push(3);			// [3, 2, 1]
st.push(4);			// [4, 3, 2, 1]
st.push(5);			// [5, 4, 3, 2, 1]
st.pop();			// [4, 3, 2, 1]
st.pop();			// [3, 2, 1]
```
**First in - last out** — первый введенный выходит последним, а последний введенный выходит первым. 

### Реализация структуры

Что такое стек - мы уже разобрались, теперь попробуем реализовать без использования готового шаблона. Для реализации любой структуры имеется ключевое слово `struct`, а его формат выглядит следующим образом:

```
struct название_структуры{
	
	компоненты_структуры;
	
	методы_структуры(){
		// код метода
	}
};
```

Как мы помним, стек имеет 5 функций - `push`, `pop`, `top`, `empty`, `size`.
`top`, `empty` и `size` возвращают некие значения, в то время как `push` и `pop` ничего не возвращают. Также `push` должен принимать данные. Тогда:

```
struct stack{

	void  push(int  x){
	}
	
	void  pop(){
	}

	int  top(){
	}

	bool  empty(){
	}

	int  size(){
	}

};
```

На начальном этапе допустим, что вводные данные только целые числа. Шаблон есть, теперь разберемся с логикой. Первое, что приходит в голову - создать массив  и пробегаться по элементам счетчиком. Пусть будет компонент `pos = 0`. Также массив размером побольше, чтоб уж наверняка: `arr[100000]`.  Стоит отметить: чтобы присвоить какое-либо значение компонентам внутри структуры, необходимо прописывать присвоения в отдельной функции, скелете структуры. 

```
struct stack{
	
	int pos;					// объявление компонентов pos и arr[]
	int arr[100000];
	
	stack(){			
		pos = 0;				// присваиваем значение
	}

	void push(int x){				// метод ввода
		arr[pos++] = x;				// в массив с индексом pos присваиваем число x,
	}						// затем увеличиваем pos, чтобы следующий ввод x был на новом индексе

	void pop(){					// метод удаления
		if(!empty())				// если стек не пустой
			pos--;				// уменьшаем pos, тем самым просто пропускаем конечный элемент
		else					// защита от ошибок
			cout << "ERROR\n";		// если стек пуст и была вызвана метод удаления, выведем ошибку
	}
	
	int top(){					// метод вывода верхнего элемента
		if(!empty())
			return arr[pos -  1];
		else					// защита от ошибок
			return -9999999;		// если стек пуст и была вызван метод вывода, возвратим -9999999.
	}						// без возвращаемого элемента метод работать не будет

	 bool empty(){					// метод для проверки на пустоту
		return pos == 0;			// если pos == 0, значит 0-й индекс массива не заполнен
	}						// соответственно стек пуст, возвращаем True. return возвратит результат условия.
	
	int size(){					// метод возврата размера
		return pos;				// размер стека в любом случае равен компоненту pos
	}
};
```

Компонент `pos` будет пробегаться по массиву. По началу он равен нулю, но как только мы введем элемент, `arr[0]` присвоит себе значение вводимого пользователем числа, а pos увеличится на единичку. Затем, в следующем вводе, `pos = 1`, поэтому на этот раз значение вводимого числа присвоит себе `arr[1]` и т.д. В случае удаления элемента, сначала мы будем проверять стек на пустоту. Если он не пустой, мы просто уменьшаем `pos`, и к примеру было 2 элемента в стеке, тогда `pos = 2`(так как `arr[0]` и `arr[1]` заполнены, следующий элемент будет `arr[2]`), при удалении мы лишь уменьшаем `pos`(тогда `pos = 1`) и пропускаем последний заполненный элемент массива. В случае пустого стека также рассмотрена защита от ошибок. 
Протестируем структуру:
```
int  main(){

	stack st;		// Так объявляется структура. st - название, оно может быть любым
				// Методы в struct вызываются через точку
					
	st.push(1); 						// [1]
	st.push(2); 						// [2, 1]
	st.push(3); 						// [3, 2, 1]
	cout <<  "Stack size: "  << st.size() << endl; 		// 3
	cout <<  "Stack last element: "  << st.top() << endl;	// 3
	st.pop(); 						// [2, 1]
	cout <<  "Stack last element: "  << st.top() << endl; 	// 2
	st.pop(); 						// [1]
	cout <<  "Stack last element: "  << st.top() << endl; 	// 1
	st.pop(); 						// []
	cout <<  "Stack is empty? ";
	cout << (st.empty() ?  "YES\n"  :  "NO\n"); 		// YES
	cout <<  "Stack last element: "  << st.top() << endl; 	// -1
	st.pop(); 						// ERROR
	cout <<  "Stack last element: "  << st.top() << endl; 	// -1

}
```
```
Output:
Stack size: 3
Stack last element: 3
Stack last element: 2
Stack last element: 1
Stack is empty? YES
Stack last element: -9999999
ERROR
Stack last element: -9999999
```

### Спецификаторы доступа

По умолчанию члены структуры(компоненты и методы) являются публичными(public). Тоесть обращаться с `main` функции на члены структуры мы можем без проблем. Но порой это может стать помехой в работе в команде. Специально для таких случаев придуманы спецификаторы доступа. 

Всего есть 3 уровня доступа:
- **public** делает члены открытыми
- **private** делает члены закрытыми
- **protected** открывает доступ к членам только для дружественных и дочерних классов(нас это пока не интересует)

Обычно компоненты являются закрытыми, а методы — открытыми. В структуре это выглядит так:

```
struct stack{
	
private:
	int pos;
	int arr[100000];

public:	
	stack(){			
		pos = 0;
	}

	void push(int x){
		arr[pos++] = x;	
	}

	void pop(){
		if(!empty())
			pos--;
		else
			cout << "ERROR\n";
	}

	int top(){	
		if(!empty())
			return arr[pos - 1];
		else
			return -9999999;
	}

	 bool empty(){
		return pos == 0;
	}

	int size(){
		return pos;
	}
};
```
В структуре мы закрыли доступ к компонентам, к ним доступ имеют только другие члены структуры.

## Queue

Очередь(queue) - такая же структура данных, как и стек, но построенная по принципу **LILO**(last in — last out: последним пришел — последним вышел). В С++ уже есть готовый шаблон для `queue`.

В очереди, если вы добавите элемент, который вошел самый первый, то он выйдет тоже самым первым. Чтобы понять принцип работы очереди вы можете представить себе магазинную очередь. И вы стоите посреди нее, чтобы вы оказались напротив кассы, сначала понадобится всех впереди стоящих людей обслужить. А вот для последнего человека в очереди нужно, чтобы кассир обслужил всех людей кроме него самого.

`queue` имеет следующие 6 функции:
```
push(x)			// Вставляет в очередь x
pop()			// Удаляет элемент в очереди
front()			// Возвращает первый элемент очереди
back()			// Возвращает последний элемент очереди
size()			// Возвращает размер очереди
empty()			// Проверяет очередь на пустоту
```
В отличии от стека, в очереди можно найти и первый, и последний элемент.

Рассмотрим пример с готовым шаблоном:
```
int  main(){

	queue<int> q;					// []

	q.push(1);					// [1]
	q.push(2);					// [2, 1]
	q.push(3);					// [3, 2, 1]
	q.push(4);					// [4, 3, 2, 1]
	cout << "Front: " << q.front() << endl;		// 1
	q.pop();					// [4, 3, 2]
	cout << "Front: " << q.front() << endl; 	// 2
	q.pop();					// [4, 3]
	cout << "Front: " << q.front() << endl;		// 3
	cout << "Back: " << q.back() << endl;		// 4
}
```
```
Output:
Front: 1
Front: 2
Front: 3
Back: 4
```
Реализовать будет чуть проблематичнее относительно стека, ведь удаление элемента приходится на начало массива, если использовать ту же идею что и в стеке. Когда мы вставляем в массив стека это происходит следующим образом:
```
[]			// Допустим есть пустой массив
[1]			// В 0-й индекс массива вставляем первый введенный элемент
[1, 2]			// В 1-й индекс вставляем следующий элемент, и тд
[1, 2, 3, 4, 5]		// Здесь, по логике стека
[1, 2, 3, 4]		// при удалении мы отрезаем последний элемент в массиве

// А в случае с очередью, удаление приходится на начало массива:
[1, 2, 3, 4, 5]
[2, 3, 4, 5]
[3, 4, 5]
...
```
Удалить элемент массива мы не можем, поэтому можно поступить хитрее. Вместо одного компонента `pos`, создадим сразу 2, `start = 0` и `finish = 0`. Эти компоненты будут отвечать за начало и конец массива. 
```
q = [1, 2, 3, 4, 5]		// Здесь start = 0, finish = 4. Получается некий отрезок индексов массива.
q.pop()				// [2, 3, 4, 5], тогда start = 1, finish = 4
q.push(6)			// [2, 3, 4, 5, 6], получается start = 1, finish = 5
```
Тоесть, идея состоит в том, чтобы увеличивать `finish` при вводе в очередь, и увеличивать `start` при удалении элемента. Тогда мы просто пропускаем элементы до `start` и берем во внимание элементы между `start` и `finish`. Это и будет нашей очередью.

Шаблон `queue` получился такой:
```
struct  queue{

private:
	int start, finish;
	int arr[100000];

public:
	queue(){
		start = 0;
		finish = 0;
	}

	void push(int  x){}

	void pop(){}

	int front(){}

	int back(){}

	int size(){}

	bool empty(){}

};
```
Структура `queue`:
```
struct queue{

private:	
	int start, finish;
	int arr[100000];
	
public:
	queue(){
		start = 0;
		finish = 0;
	}

	void push(int x){
		arr[finish++] = x;
	}

	void pop(){
		if(!empty())
			start++;
		else
			cout << "ERROR\n";
	}
	
	int front(){
		if(!empty())	
			return arr[start];
		else
			return -9999999;
	}

	int back(){
		if(!empty())
			return arr[finish - 1];
	else	
		return -9999999;
	}

	int size(){
		return finish - start;
	}
	
	bool empty(){
		return finish - start <= 0;
	}
};
```

Протестим:
```
int  main(){
	
	queue q;							// []
	  
	q.push(1); 							// [1]
	q.push(2); 							// [2, 1]
	q.push(3); 							// [3, 2, 1]
	cout << "Queue size: " << q.size() << endl; 			// 3
	cout << "Front: " << q.front() << endl; 			// 1
	q.pop(); 							// [3, 2]
	q.push(4);							// [4, 3, 2]
	q.push(5); 							// [5, 4, 3, 2]
	cout << "Front: " << q.front() << endl;				// 2
	cout << "Back: " << q.back() << endl; 				// 5
	q.pop(); 							// [5, 4, 3]
	q.push(6); 							// [6, 5, 4, 3]
	q.push(7);							// [7, 6, 5, 4, 3]
	cout << "Front: " << q.front() << endl; 			// 3
	q.pop(); 							// [7, 6, 5, 4]
	cout << "Queue is empty? " << (q.empty() ? "YES\n" : "NO\n");	// NO
	cout << "Front: " << q.front() << endl; 			// 4
	q.pop(); 							// [7, 6, 5]
	cout << "Front: " << q.front() << endl; 			// 5
	q.pop(); 							// [7, 6]
	cout << "Size: " << q.size() << endl; 				// 2
	cout << "Front: " << q.front() << endl; 			// 6
	cout << "Back: " << q.back() << endl; 				// 7
	q.pop();							// [7]
	cout << "Front: " << q.front() << endl; 			// 7
	q.pop(); 							// []
	cout << "Front: " << q.front() << endl; 			// -9999999
}
```

## Deque

Дек(deque) - структура данных, которая позволяет добавлять элементы и в конец, и в начало, а также удалять элементы из конца и из начала. В С++ уже есть готовый шаблон для `deque`.

### Функции `deque`
```
push_back(x)		// Вставляет в конец дека x
push_front(x)		// Вставляет в начало дека x
pop_back()			// Удаляет конец дека
pop_front()			// Удаляет начало дека
back()				// Возвращает конец дека
front()				// Возвращает начало дека
empty()				// Проверяет дек на пустоту
size()				// Возвращает размер дека
clear()				// Очищает дек
```

Думаю дальнейших объяснении дека не требуется, можно начать думать о реализации дека. Думаю будет правильным за основу брать метод реализации очереди, когда мы берем один отрезок массива двумя компонентами `start` и `finish`. Но в нашем случае мы работаем с обоих сторон, и спереди и сзади.  
```
dq = [1, 2, 3, 4, 5]	// здесь start = 0, finish = 4
```
В таком случае мы можем добавить спереди, увеличив `finish`, но добавить сзади мы не сможем, в таком случае `start` уйдет в минусовое значение. Чтобы таких последствий не было, можно `start` и `end` обозначить центром массива.
Допустим что размер массива `arr[100000]` 100.000. Тогда пусть `start = 50000`, `finish = 500000`. Тогда проблема с минусовым значением нас не потревожит. Можно запутаться в направлениях, поэтому в нашем случае пусть `front` будет слева, `back` справа массива. И так, подготовим шаблон: 

```
struct  deque{

private:
	int start, finish;
	int arr[100000];
	
public:
	deque(){
		start = 50000;
		finish = 50000;
	}

	void push_back(int x){}
	
	void push_front(int x){}

	void pop_back(){}

	void pop_front(){}

	int back(){}

	int front(){}

	bool empty(){}

	int size(){}
	
	void clear(){}
};
```

### Реализация `deque`

```
struct deque{

private:
	int start, finish;
	int arr[100000];

public:
	deque(){
	start = 50000;
	finish = 50000;
	}
	
	void push_back(int x){
		arr[finish++] = x;
	}

	void push_front(int x){
		arr[--start] = x;
	}

	void pop_back(){
		if(!empty())
			finish--;
		else
			cout << "ERROR\n";
	}
	
	void pop_front(){
		if(!empty())
			start++;
		else
			cout << "ERROR\n";
	}

	int back(){
		if(!empty())
			return arr[finish - 1];
		else
			return  -9999999;
	}

	int front(){
		if(!empty())
			return arr[start];
		else
			return  -9999999;
	}

	bool empty(){
		return finish - start <= 0;
	}

	int size(){
		return finish - start;
	}

	void clear(){
		start = 50000;
		finish = 50000;
	}

	void  print(){
		cout << "Array: ";
		for(int i = start; i < finish; i++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};
```

Добавил метод `print` для ясности, что там вообще происходит.

### Тестирование

```
int main(){

    deque dq;                   // []

    dq.push_back(1);            // [1]
    dq.push_back(2);            // [1, 2]
    dq.push_back(3);            // [1, 2, 3]
    dq.push_front(4);           // [4, 1, 2, 3]
    dq.push_front(5);           // [5, 4, 1, 2, 3]
    dq.push_front(6);           // [6, 5, 4, 1, 2, 3]

    cout << "Deque size: " << dq.size() << endl;    // 6
    cout << "Deque front: " << dq.front() << endl;  // 6
    cout << "Deque back: " << dq.back() << endl;    // 3
    dq.print();                                     // 6 5 4 1 2 3
    dq.pop_back();                                  // [6, 5, 4, 1, 2]
    dq.print();                                     // 6 5 4 1 2
    dq.pop_front();                                 // [5, 4, 1, 2]
    cout << "Deque front: " << dq.front() << endl;  // 5
    cout << "Deque back: " << dq.back() << endl;    // 2
    dq.print();                                     // 5 4 1 2

    dq.push_back(7);                                // [5, 4, 1, 2, 7]
    dq.push_back(8);                                // [5, 4, 1, 2, 7, 8]
    dq.print();                                     // 5 4 1 2 7 8
    dq.pop_front();                                 // [4, 1, 2, 7, 8]
    dq.pop_front();                                 // [1, 2, 7, 8]
    dq.pop_front();                                 // [2, 7, 8]
    dq.pop_front();                                 // [7, 8]
    dq.print();                                     // 7 8
    dq.pop_back();                                  // [7]
    
    cout << "Deque size: " << dq.size() << endl;    // 1
    dq.pop_back();                                  // []
    cout << "Deque is empty? ";
    cout << (dq.empty() ? "YES\n" : "NO\n");        // YES
    dq.pop_front();                                 // ERROR
    dq.pop_back();                                  // ERROR
    cout << "Deque front: " << dq.front() << endl;  // -9999999
    cout << "Deque back: " << dq.back() << endl;    // -9999999
    cout << "Deque size: " << dq.size() << endl;    // 0

    dq.push_back(9);                                // [9]
    dq.push_front(10);                              // [10, 9]
    dq.print();                                     // 10 9
    dq.clear();                                     // []
    dq.print();                                     // 
}
```
```
Output:
Deque size: 6
Deque front: 6
Deque back: 3
Array: 6 5 4 1 2 3
Array: 6 5 4 1 2
Deque front: 5
Deque back: 2
Array: 5 4 1 2
Array: 5 4 1 2 7 8
Array: 7 8
Deque size: 1
Deque is empty? YES
ERROR
ERROR
Deque front: -9999999
Deque back: -9999999
Deque size: 0
Array: 10 9
Array:
```

## Заключение

На самом деле контейнеры `stack`, `queue` и `deque` очень быстры и полезны. Все методы, которые мы сегодня прописали, операции удаления или вставки выполняются за O(1), что является очень быстрым показателем. А то что мы сами себе прописали свою структуру очень даже неплохой результат :).

## Использованные материалы

- [C++ | Структуры](https://metanit.com/cpp/tutorial/5.8.php)
- [Стек(stack) в C++](https://codelessons.ru/cplusplus/realizaciya-steka-stack-v-c.html)
- [stack - C++ Reference](https://cplusplus.com/reference/stack/stack/)
- [Спецификаторы доступа](https://ravesli.com/urok-114-spetsifikatory-dostupa-public-i-private/)
- [Очередь(queue) в С++](https://codelessons.ru/cplusplus/ochered-queue-v-c-realizaciya-i-chto-eto-voobshhe-takoe.html)
- [queue - C++ Reference](https://cplusplus.com/reference/queue/queue/)
- [Контейнер deque](https://server.179.ru/tasks/cpp/total/225.html)
- [deque - C++ Reference](https://cplusplus.com/reference/deque/deque)