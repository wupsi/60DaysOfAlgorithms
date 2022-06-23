## Linked Lists - Day 4

Сегодня рассмотрим Связные Списки или Linked Lists. Связный список используется практически везде — от ОС до игр, а на его основе строится множество других структур данных.

## Problems
- [✔️] [A.  Алфавитно-частотный словарь](https://informatics.msk.ru/mod/statements/view.php?chapterid=112510#1)
- [❌] [Словарь по частотам](https://informatics.msk.ru/mod/statements/view.php?chapterid=112511#1)
- [❌] [Словарь для файла](https://informatics.msk.ru/mod/statements/view.php?chapterid=112512#1)
- [❌] [Словарь для файла с пунктуацией](https://informatics.msk.ru/mod/statements/view.php?chapterid=112513#1)
- [❌] [Список чисел](https://informatics.msk.ru/mod/statements/view.php?chapterid=112514#1)
- [❌] [Построчный редактор](https://informatics.msk.ru/mod/statements/view.php?chapterid=112515#1)
- [❌] [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)
- [❌] [Remove Duplicates From Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)
- [❌] [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)
- [❌] [Intersection Of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/)
- [❌] [Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/)
- [❌] [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)
- [❌] [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)
- [❌] [Delete Node In A Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list/)

## Linked List

**Связный список** - динамическая структура данных, состоящий из узлов. А в свою очередь, каждый узел(`Node`) состоит из двух значений:
- Какое-либо данное, которым может быть что угодно: обычная переменная, объект класса, и т.д. 
- Указатель на следующий узел.

Список называется "связным", потому что все узлы списка связаны между собой указателями, а динамический потому что во время выполнения программы можно расширять данную структуру путем добавления новых узлов в список. Если мы объявили массив `arr[1000]`, мы объявили ровно 1000 ячеек памяти заполненных данными. И в случаях когда мы используем лишь к примеру ячеек 10, остальные 990 ячеек останутся неиспользованными, хотя все равно занимают память. А связный список хорош тем, что мы не объявляем определенное количество места в памяти, а просто будем выделять ячейку памяти для нового узла.

Связный список можно изобразить следующим образом:
![Linked List](https://www.alphacodingskills.com/imgfiles/linked-list.PNG)

Здесь мы видим 3 узла(`[Data, Next]` - один узел), хранящие в себе 2 значения - данное и указатель. Указатель всегда указывает на следующий узел связанного списка. А указатель последнего узла должен всегда указывать на `NULL`, так он сообщает что является последним узлом в списке и дальше указывать не на что.

Теперь мы можем создать сам узел:
```
struct Node{
	int data;
	Node *next;
};
```
Данными будет переменная `data` типа `int`. А указатель мы назовем `next`, типа `Node`. Пока указатель `*next` никуда не указывает, но мы знаем что он может указывать лишь на структуру `Node`.

Итак, теперь создадим саму структуру `LinkedList`.  Первый узел будет началом списка, назовем его `head`. Пока что в нем ничего не хранится. Соответственно, в конструкторе прописываем  `head = NULL;`.

### Шаблон структуры
```
struct LinkedList{

private:
	Node *head;					

public:
	LinkedList(){
		head = NULL;
	}
};
```

Мы выяснили, что динамический список состоит из узлов, значит структура `LinkedList` должна манипулировать этими узлами: создавать/выводить/удалять. 

### Создание нового узла

Для того, чтобы создать новый узел, определимся с инициализацией нового узла. Для начала создадим новый узел:
```
void addNode(int x){
	Node *newNode =  new Node; 	// Создаем новый узел newNode
	newNode->data = x;			// Данным узла newNode присваиваем значение x
	newNode->next = NULL;		// Указателю узла newNode будет NULL
}
```
**1-строка:** В атрибутах передаем значение числа, которое хотим сохранить в узле(`int x`). 
**2-строка:** Создан узел с названием `newNode` типа `Node`. 
**3-строка:** Присваиваем новому узлу `newNode` значение `x`. `data` узла будет равна x.
**4-строка:** Указатель узла будет указывать на `NULL`. То есть это будет последним узлом в списке.	

Теперь новый узел надо объявить последним в списке:
```
void  addNode(int  x){
	Node *newNode =  new Node; 			// Создаем новый узел newNode
	newNode->data = x; 					// Данные узла newNode будет равен x
	newNode->next =  NULL; 				// Указатель узла newNode будет NULL
	
	if(head ==  NULL) 					// Если добавляемые данные будут первым узлом
		head = newNode; 				// head присвоим значение нового узла
	else{ 								// Если узел не первый
		Node *current = head; 			// Создаем текущий узел
		while(current->next !=  NULL) 	// Пока не дойдем до последнего узла
		current = current->next; 		// Проходим по всем узлам до конца

		current->next = newNode; 		// Теперь следующим узлом вместо NULL будет newNode
	}
}
```
Пока не дойдем до момента, когда указатель будет указывать на `NULL`, будем перебирать все узлы. Когда найдем последний узел, указывающий на `NULL`, значение меняем на новый узел `newNode`. При этом не забываем условие первого элемента.

### Вывод всех узлов

Вывод реализуем следующим образом:
```
void  printNodes(){
	Node *current = head;
	while(current !=  NULL){
		cout << current->data << endl;
		current = current->next;
	}
}
```
Перебираем все узлы, пока не дойдем до последнего узла. В это же время выводим данные, который хранит узел(`current->data`).

Структура которая у меня получилась:
```
struct Node{
	int data;
	Node *next;
};
  
struct  LinkedList{

private:
	Node *head;

public:
	LinkedList(){
		head =  NULL;
	}
	
	void  addNode(int  x){
		Node *newNode =  new Node;
		newNode->data = x;
		newNode->next =  NULL;
		
		if(head ==  NULL)
			head = newNode;
		else{
			Node *current = head;
			while(current->next !=  NULL)
				current = current->next;
			
			current->next = newNode;
		}
	}
	  
	void  printNodes(){
		Node *current = head;
		while(current !=  NULL){
			cout <<  "["  << current->data <<  ", "  << current->next <<  "]"  << endl;
			current = current->next;
		}
	}
};
```
В строке
`cout <<  "["  << current->data <<  ", "  << current->next <<  "]"  << endl;` я вывел данные вместе с адресом, куда указывает `next`.

Протестируем:
```
int  main(){
	  
	LinkedList list;
	  
	list.addNode(1);
	list.addNode(2);
	list.addNode(3);
	list.addNode(4);
	list.addNode(5);
	  
	list.printNodes();
}
```
`Output:`
```
[1, 0xd71720]
[2, 0xd71a70]
[3, 0xd71a90]
[4, 0xd71ab0]
[5, 0]
```
Последний элемент указывает на `NULL`. Поэтому мы видим 0 вместо адреса.


## Использованные материалы

- [Алгоритмы и Структуры данных для начинающих: связный список](https://tproger.ru/translations/linked-list-for-beginners/)
- [Linked List Data Structure](https://www.geeksforgeeks.org/data-structures/linked-list/)
- [Реализация связных списков на С++](https://pro-prof.com/forums/topic/реализация-связных-списков-на-с)