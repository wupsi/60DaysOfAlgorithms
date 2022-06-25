## Linked Lists - Day 5

Для решения большинства задач, нам обычного однонаправленного связанного списка будет мало. Поэтому сегодня рассмотрим следующий этап связанных списков - Двусвязанный Список или Doubly-Linked List.

## Problems

- [✔️] [A.  Алфавитно-частотный словарь](https://informatics.msk.ru/mod/statements/view.php?chapterid=112510#1)
- [❌] [B. Словарь по частотам](https://informatics.msk.ru/mod/statements/view.php?chapterid=112511#1)
- [❌] [C. Словарь для файла](https://informatics.msk.ru/mod/statements/view.php?chapterid=112512#1)
- [❌] [D. Словарь для файла с пунктуацией](https://informatics.msk.ru/mod/statements/view.php?chapterid=112513#1)
- [❌] [E. Список чисел](https://informatics.msk.ru/mod/statements/view.php?chapterid=112514#1)
- [❌] [F. Построчный редактор](https://informatics.msk.ru/mod/statements/view.php?chapterid=112515#1)
- [❌] [G. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)
- [❌] [H. Remove Duplicates From Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)
- [❌] [I. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)
- [❌] [J. Intersection Of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/)
- [❌] [K. Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/)
- [❌] [L. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)
- [❌] [M. Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)
- [❌] [N. Delete Node In A Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list/)

## Doubly-Linked List

**Двусвязный список** — это линейная структура данных, в которой элементы хранятся в виде узла. Логически представить двусвязный список можно следующим образом:
![](https://www.alphacodingskills.com/imgfiles/doubly-linked-list.PNG)

В каждом узле мы можем увидеть 3 элемента, это:
-   `data` – данные. Данными могут быть любое значение любого типа;
-   `next` – указатель на следующий элемент;
-   `prev` – указатель на предыдущий элемент.

В однонаправленном мы могли перемещаться только в одно направление и не могли вернуться назад, что можно сделать в двунаправленном, так как любой из следующих узлов содержит в себе указателя на предыдущий. 
Учитываем следующие вещи: первый узел, также известный как `HEAD`, всегда используется в качестве узла для обхода списка. Предыдущий указатель(`prev`) из головного узла и следующий из последнего узла указывают на `NULL`. 
```
struct Node{
	int data;
	Node *next;
	Node *prev;
	
	Node(int x){
		data = x;
		next = NULL;
		prev = NULL;
	}
};
```
Чтобы не прописывать создание нового узла в каждой функции, решил добавить эту часть в конструктор самих узлов. Далее, когда в самой структуре списка будем создавать узел, просто пропишем
```
Node *newNode =  new  Node(x);		// x - вводимое число
```
Так мы сможем короче создавать узлы. Также разделил `head` на 2 части: `head` и `tail`. Двусвязный список своей структурой напоминает `deque`. С обоими надо реализовать работу и с началом, и с концом структуры. А с двумя переменными сделать это будет намного проще.

## Операции структуры

**Doubly-Linked List** (далее DLL) должен уметь проводить следующие операции:
```
push_back(x)		// Вставить узел в конец
push_front(x)		// Вставить узел в начало
insert(pos, x)		// Вставить узел в позиции pos
pop_back()			// Удалить последний узел
pop_front()			// Удалить первый узел
pop(pos)			// Удалить узел на позиции pos
find(x)				// Найти число x в списке
print()				// Вывести список
```
Сначала пропишем скелет:
```
struct Node{
	int data;
	Node *next;
	Node *prev;
	
	Node(int x){
		data = x;
		next = NULL;
		prev = NULL;
	}
};

struct DoublyLinkedList{

private:
	Node *head;
	Node *tail;

public:
	DoublyLinkedList(){
		head = NULL;
		tail = NULL;
	}

	void push_back(int x);	
	push_front(int x);
	insert(int pos, int x);
	pop_back();
	pop_front();
	pop(int pos);
	find(int x);
	print();
};
```
Пройдемся по каждому методу;

## push_back()
Создаем новый узел и меняем местами значения нового узла с последним узлом со списка. Перед этим подправляем адреса узлов.
```
void  push_back(int  x){
	Node *newNode =  new  Node(x);			// Создаем новый узел

	if(tail ==  NULL)						// Если узел первый в списке
		tail = newNode, head = newNode;		// Тогда значения и конца, и начала будут новым узлом.
	else{									// Если узел не первый
		newNode->prev = tail;				// Предыдущий указатель нового узла укажет на текущий последний узел
		tail->next = newNode;				// В свою очередь, следующим узлом после последнего на данный момент узла станет новый узел
		tail = newNode;						// Затем присуждаем tail'у значение нового узла. Теперь у нас новый конечный узел.
	}
}
```

## push_front()

Создаем новый узел и меняем местами значения нового узла с первым узлом со списка. Обязательно проверяем, пуст ли список. В таком случае заполняем первым элементом список.

```
void  push_front(int  x){
	Node *newNode =  new  Node(x);			// Создаем новый узел
	  
	if(head ==  NULL)						// Если узел первый в списке
		head = newNode, tail = newNode;		// Тогда значения и конца, и начала будут новым узлом.
	else{									// Если узел не первый
		head->prev = newNode;				// Теперь предыдущим элементом первого элемента станет новый узел. Т.е. заменяем начальный NULL на newNode
		newNode->next = head;				// Надо указать следующий узел для newNode. Им и будет head.
		head = newNode;						// Объявляем, что теперь головным узлом списка будет тот самый newNode.
	}
}
```

## pop_back()
При удалении последнего узла, мы просто отрезаем его адрес. Отрезанный узел существует где-то в памяти компьютера, но к нему мы уже не будем привязаны никаким указателем.
```
void  pop_back(){
	if(tail !=  NULL){						// Проверка на пустоту списка
		if(tail->prev ==  NULL)				// Проверка, не является ли узел единственным в списке
			head =  NULL, tail =  NULL;		// Если узел единственный в списке, просто приравниваем узлы к NULL
		else								// Если узлов больше 1
			tail = tail->prev;				// Меняем конечный узел на предпоследний
		tail->next =  NULL;					// Убираем предыдущий адрес узла, присваиваем NULL
	}
}
```
## pop_front()
Та же идея, что и в `pop_back`. Но на этот раз отрезаем голову списка. 
```
void  pop_front(){
	if(head !=  NULL){						// Условие для проверки на пустоту. Если головы не существует, соответственно удалять нам нечего.
		if(head->next ==  NULL)				// Если следующего узла после головы не существует
			head =  NULL, tail =  NULL;		// Значит в списке один элемент и мы отрезаем значения head и tail
		else								// Если узлов больше 1
			head = head->next;				// Отрезаем адрес головы
	}
}
```

## print()

Создаем временный узел `current`, который пройдется по всему списку узлов. Переходим на следующий узел, пока не встретим `NULL`(конец списка).

```
void  print(){
	Node *current = head;
	  
	while(current !=  NULL){
		cout << current->data <<  " ";
		current = current->next;
	}
	cout << endl;
}
```

## find()

Нахождение данного числа в списке узлов. Пройдемся по всем узлам и будем хранить текущую позицию узла в `cnt`, пока не дойдем до искомого числа `x`. В случае нахождения передаем значение `cnt` в `pos` и возвращаем позицию найденного числа.

```
int  find(int  x){
	int pos =  -1, cnt =  0;
	Node *current = head;
	  
	while(current !=  NULL){
		if(current->data == x){
			pos = cnt;
			break;
		}
		current = current->next;
		cnt++;
	}
	
	return pos;
}
```

## pop()

Удаление по позиции. Сначала найдем искомый узел, который надо удалить. Затем, если искомый узел первый/последний в списке, применяем удобные функции. Иначе делаем следующие шаги:
- Объявляем следующий узел от текущего в отдельную переменную `nextNode`
- Объявляем предыдущий узел от текущего в отдельную переменную `prevNode`
- Объявляем следующим узлом предыдущего узла `prevNode` следующим узлом от текущего - `nextNode`
- Объявляем предыдущим узлом следующего узла `nextNode` предыдущим узлом от текущего - `prevNode`.

```
void  pop(int  pos){
	int cnt =  0;
	Node *current = head;
	
	while(cnt != pos and current->next != tail){
		current = current->next;
		cnt++;
	}
	  
	if(current == head) pop_front();
	else  if(current == tail) pop_back();
	else{
		Node *nextNode = current->next;
		Node *prevNode = current->prev;
		prevNode->next = nextNode;
		nextNode->prev = prevNode;
	}
}
```
Вкратце, мы просто убрали и переписали адреса предыдущего и следующего узла от текущего.

## insert()

Работает почти так же, как и `pop()`. Но здесь вместо обрезки адреса добавляем новый узел и переписываем адреса под него.
```
void  insert(int  pos, int  x){
	int cnt =  0;
	Node *current = head;
	Node *newNode =  new  Node(x);
	
	while(cnt != pos and current !=  NULL){
		current = current->next;
		cnt++;
	}
	  
	if(current == head) push_front(x);
	else  if(current == tail->next) push_back(x);
	else{
		Node *prevNode = current->prev;
		prevNode->next = newNode;
		current->prev = newNode;
		newNode->prev = prevNode;
		newNode->next = current;
	}
}
```
Готовую структуру залил в файл. Протестируем в `main` функции работу структуры:
```
int  main(){
  
	DoublyLinkedList dll;
	dll.push_back(5);
	dll.push_back(6);
	dll.push_back(7);
	dll.push_back(8);
	dll.push_back(9);
	dll.push_back(10);
	dll.push_front(11);
	dll.push_front(12);
	dll.push_front(13);
	dll.push_front(14);
	dll.push_front(15);
	dll.print(); 										// [15, 14, 13, 12, 11, 5, 6, 7, 8, 9, 10]
	dll.pop_back();
	dll.pop_back();
	dll.pop_front();
	dll.pop_front();
	dll.print(); 										// [13, 12, 11, 5, 6, 7, 8]
	  
	int finded = dll.find(11);
	cout <<  "Finded on pos: "  << finded << endl; 		// Finded on pos: 2
	if (finded !=  -1) {
	dll.pop(finded);
	cout <<  "poped\n";
	}
	  
	dll.print(); 										// [13, 12, 5, 6, 7, 8]
	  
	finded = dll.find(6);
	dll.insert(finded, 100);
	dll.print(); 										// [13, 12, 5, 100, 6, 7, 8]
}
```
```
Output:
15 14 13 12 11 5 6 7 8 9 10
15 10
13 12 11 5 6 7 8
13 8
Finded on pos: 2
poped
13 12 5 6 7 8
13 12 5 100 6 7 8
```
В тесте все работает отлично. Но задачами структуру пока не тестил, посмотрим завтра :)

## Использованные материалы

- [Doubly Linked List | Set 1 (Introduction and Insertion)](https://www.geeksforgeeks.org/doubly-linked-list/)
- [Двусвязный линейный список](https://prog-cpp.ru/data-dls/)
- [Структура данных: двусвязный список](https://nuancesprog.ru/p/15493/)
- [C++ - Doubly Linked List](https://www.alphacodingskills.com/cpp/ds/cpp-doubly-linked-list.php)