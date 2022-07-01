## Binary Search Tree - Day 9 

Сегодня рассмотрим довольно сложную на первый взгляд структуру данных - `Binary Search Tree`. `BST` обычно применяются для реализации множеств и разного рода контейнеров(например, `set` и `map` в `C++`). 

## Problems
  
### Informatics:

- [❌] [A. Высота дерева](https://informatics.msk.ru/mod/statements/view.php?chapterid=757#1)
- [❌] [B. Количество элементов](https://informatics.msk.ru/mod/statements/view.php?chapterid=758#1)
- [❌] [C. Второй максимум](https://informatics.msk.ru/mod/statements/view.php?chapterid=759#1)
- [❌] [D. Обход](https://informatics.msk.ru/mod/statements/view.php?chapterid=760#1)
- [❌] [E. Вывод листьев](https://informatics.msk.ru/mod/statements/view.php?chapterid=761#1)
- [❌] [F. Вывод развилок](https://informatics.msk.ru/mod/statements/view.php?chapterid=762#1)
- [❌] [G. Вывод веток](https://informatics.msk.ru/mod/statements/view.php?chapterid=763#1)
- [❌] [H. Сбалансированность](https://informatics.msk.ru/mod/statements/view.php?chapterid=764#1)

### Leetcode:

- [❌] [A. Convert Sorted Array To Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)
- [❌] [B. Lowest Common Ancestor Of A Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)
- [❌] [C. Find Mode In Binary Search Tree](https://leetcode.com/problems/find-mode-in-binary-search-tree/)
- [❌] [D. Range Sum Of BST](https://leetcode.com/problems/range-sum-of-bst/)
- [❌] [E. Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees/)
- [❌] [F. Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)

## Binary Search Tree

Ранее мы рассматривали структуру связных списков, в котором узел указывает лишь на один элемент, и даже в двухсвязном связанном списке мы проходились только по одной линии узлов. А в случае с бинарным деревом поиска каждый узел имеет некое значение и два указателя на два разных узла.

Для начала разберемся, что такое **Бинарное Дерево**. Это иерархическая структура данных, в которой каждый узел имеет хранимые данные и ссылки на левого и правого потомка.

**Бинарное Дерево Поиска** — это бинарное дерево, обладающее дополнительными свойствами: значение левого потомка меньше значения родителя, а значение правого потомка больше значения родителя. Визуально мы можем представить дерево так:
![Бинарное дерево поиска](https://www.linkpicture.com/q/bstExample.png)

Узел, находящийся на самом верхнем уровне (не являющийся чьим либо потомком) называется корнем. Узлы, не имеющие потомков называются листьями.
Здесь значение корня - 8. А листья - 1, 4, 7, 13.

Сегодня разберем следующие функции `BST`:
```
insert()			// Добавление в дерево
find()				// Поиск в дереве
findMax()			// Нахождение максимального элемента в дереве
findMin()			// Нахождение минимального элемента в дереве
```

### Узел и шаблон структуры

Сначала создадим сам узел для операции `BST`:
```
struct Node {
	int data;
	Node* left;
	Node* right;
	  
	Node(int x){
		data = x;
		left = NULL;
		right = NULL;
	}
};
```
У нас есть некое значение - `data`, указатель на левого потомка `*left` и на правого `right`. В конструкторе отмечаем, что данным присвоим значение которое передадим, а указатели будут указывать на `NULL`, тоесть пока что никуда.

```
struct BinarySearchTree{
  
	Node *root;
	  
	BinarySearchTree(){
		root =  NULL;
	}
};
```
Для самой структуры `BST` определим корень и присвоим ей `NULL` значение.

### Операция вставки

Алгоритм у нас следующий:
- Если дерево пустое, создаем узел и присваиваем значению корня новый созданный узел
- Если дерево не пустое, сравниваем вставляемое значение со значениями потомков корня:
	1. Если вставляемое значение больше текущего, переходим к правому потомку;
	2. Если вставляемое значение меньше текущего, переходим к левому потомку;
	3. Если вставляемое значение равно текущему, игнорируем и не вставляем это значение;
- Продолжаем до тех пор, пока следующий потомок существует.

![insert bst](https://www.linkpicture.com/q/insertionBST_1.png)

```
struct  BinarySearchTree{
	  
	Node *root;
	  
	BinarySearchTree(){
	root =  NULL;
	}
	  
	Node  *insert(Node  *current, int  x){
		if(current ==  NULL){
			current =  new  Node(x);
			return current;
		}
		if(x > current->data) current->right =  insert(current->right, x);
		else  if(x < current->data) current->left =  insert(current->left, x);
	  
		return current;
	}
};
```

в `main` функции:
```
int main(){

	BinarySearchTree BST;
	// Step 1:
	BinarySearchTree BST; 						// root = NULL;
	  
	// Step 2:
	BST.root = BST.insert(BST.root, 1); 		// root = node; node->data = 1, node->left = NULL, node->right = NULL;
	  
	// Step 3: 
	BST.root = BST.insert(BST.root, 2); 		// node->right = node1; node1->data = 2, node1->left = NULL, node1->right = NULL;
	  
	// Step 4:
	BST.root = BST.insert(BST.root, 0); 		// node->left = node2, node2->data = 0, node2->left = NULL, node2->right = NULL;
	  
	// Step 5:
	BST.root = BST.insert(BST.root, 10);
	}
```
В коде не существует никакого `node1` или `node2`, они созданы лишь для понимания самой сути.

- Step 1: Объявляем `BST`. Пока он пуст, поэтому `root` не имеет значения.
- Step 2: Вставляем 1. Так как дерево у нас было пустым, корнем будет первый введенный элемент. 
- Step 3: Вставляем 2. 2 > 1, поэтому правым потомком корня объявим новый узел созданный узел.
- Step 4: 0 < 1, поэтому левый потомок корня - 0. 
- Step 5: Вставляем 10. 10 > 1, переходим к правому потомку. Встречаем 2. 10 > 2, поэтому следующим правым потомком 2 будет 10.

Подробнее про шаги на картинке:
![](https://www.linkpicture.com/q/newStepsBST.png)

### Операция поиска

```
bool find(Node *current, int x){
	if(current == NULL)
		return false;
	
	if(x > current->data) return find(current->right, x);
	else if(x < current->data) return find(current->left, x);
	return true;
} 
```
Тот же самый алгоритм: пока не найдем искомое число, проходимся по дереву:
- Если значение больше, проходим к правому потомку
- Если значение меньше, переходим к левому потомку
- Если значение равно, значит мы нашли искомое число
- Если текущий узел сравнялся с `NULL`, значит искомого числа не существует

### Нахождение максимального элемента

С этим в `BST` все просто. Так как наша иерархия отсортирована, самый правый элемент дерева и будет наибольшим. Значит пройдемся по правым потомкам до тех пор, пока не окажемся в конце.
```
Node  *findMax(Node  *current){
	if(current->right ==  NULL)
		return current;
	return  findMax(current->right);
}
```

### Нахождение минимального элемента

В свою очередь самый левый узел дерева будет наименьшим. Пройдемся по левому краю до тех пор, пока не встретим `NULL`.

```
Node  *findMin(Node  *current){
	if(current->left ==  NULL)
		return current;
	return  findMin(current->left);
}
```


## Использованные материалы

- [Бинарное дерево поиска | Реализация на C++](https://www.youtube.com/watch?v=VRX99cNoczY&ab_channel=LizavetaShelengovskaya)
- [Программная реализация бинарных поисковых деревьев](https://acm.bsu.by/wiki/Программная_реализация_бинарных_поисковых_деревьев)
- [Бинарные деревья поиска и рекурсия – это просто](https://habr.com/ru/post/267855/)
- [Binary Search Tree](https://www.programiz.com/dsa/binary-search-tree)
- [Алгоритмы и структуры данных для начинающих: двоичное дерево поиска](https://tproger.ru/translations/binary-search-tree-for-beginners/)
- [Двоичные деревья поиска: начальные сведения](https://algolist.ru/ds/btree.php)