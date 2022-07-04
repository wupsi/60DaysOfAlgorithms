# Binary Search Tree - Day 10

### Продолжаем разбор `BST`!

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

## Удаление узла

При удалении какого-либо узла в `BST` стоит учесть множество факторов. В пример возьмем следующее `BST`:
![](https://www.linkpicture.com/q/bstExample1.png)

Допустим надо удалить 4. Это обычный лист, соответственно у него нет потомков и мы можем без лишних проблем удалить этот элемент, присвоив значение `NULL`. 

![](https://www.linkpicture.com/q/bstExample2.png)

Теперь удалим 5. Это узел, у которого есть один потомок. Здесь тоже довольно просто, мы просто присвоим этому узлу значения потомка:
![](https://www.linkpicture.com/q/bstExample3.png)	

В случае, когда мы хотим удалить узел с двумя потомками, немного сложнее. К примеру возьмем 3, сам корень, который имеет 2 потомка. Мы должны помнить, что при удалении элемента свойство бинарного дерева не должно ломаться. Элементы левого потомка всегда меньше родителя, а элементы правого потомка всегда больше родителя. И чтобы сохранить свойство дерева мы найдем минимальное число из правого потомка, заменим его на текущий и удалим тот самый минимум правого потомка.

```
Node  *remove(Node  *current, int  x){
	if(current ==  NULL) return  NULL;
	if(x > current->data) current->right =  remove(current->right, x); 			// Рекурсивно находим узел
	else  if(x < current->data) current->left =  remove(current->left, x);
	else{ 											// Если узел найден
		if(current->left ==  NULL  and current->right ==  NULL) current =  NULL; 	// Если это лист, текущий узел приравниваем к NULL
		else  if(current->right ==  NULL) current = current->left; 			// Если у узла только левый потомок
		else  if(current->left ==  NULL) current = current->right; 			// Если у узла только правый потомок
		else{ 										// Если у узла два потомка
			Node *minRight =  findMin(current->right);
			current->data = minRight->data;
			current->right =  remove(current->right, minRight->data);
		}
	}
	return current;
}
```

## Обход дерева

В отличие от линейных структур данных (массив, связанный список, очереди, стеки и т. д.), у которых есть только один логический способ обхода, деревья можно обойти разными способами. Деревья можно обходить «в глубину» или «в ширину». В ширину пока обходить не будем, остановимся на обходе в глубину.
![Example Tree](https://media.geeksforgeeks.org/wp-content/cdn-uploads/2009/06/tree12.gif)


Существует три основных способа обхода в глубину(цифрами обозначена последовательность посещения каждого узла):
```
- InOrder(Left, Root, Right): 4, 2, 5, 1, 3
- PreOrder(Root, Left, Right): 1, 2, 4, 5, 3
- PostOrder(Left, Right, Root): 4, 5, 2, 3, 1
```
В случае `BST` `In-Order` обход  выводит в порядке неубывания. 
`Pre-Order` обход используется для создания копии дерева.
Обход `Post-Order` используется для удаления дерева.

### In-Order Traversals

Алгоритм:
1. Находим самого левого потомка
2. Выводим содержимое узла
3. Переходим в корень текущего узла
4. Выводим содержимое
5. Посещаем правого потомка
6. Выводим содержимое

Рекурсивно повторяем этот алгоритм: 
Нашли самый левый узел -> Переходим в корень -> Посещаем правого потомка -> Находим самый левый узел(пропуская предыдущие) -> Переходим в корень и т.д.

```
void inOrder(Node *current){
	if(current == NULL) return;
	inOrder(current->left);
	cout << current->data << " ";
	inOrder(current->right);
}
```


### Pre-Order Traversals

Алгоритм:
1. Выводим содержимое текущего корня
2. Переходим в левый потомок
3. Выводим содержимое
4. Когда дойдем до конечного узла, переходим к правым потомкам

```
void preOrder(Node *current){
	if(current == NULL) return;
	cout << current->data << " ";
	preOrder(current->left);
	preOrder(current->right);
}
```

### Post-Order Traversals

Алгоритм:
1. Обходим левого потомка
2. Обходим правого потомка
3. Выводим значение текущего узла
4. Возвращаемся в корень

```
void postOrder(Node *current){
	if(current == NULL) return;
	postOrder(current->left);
	postOrder(current->right);
	cout << current->data << " ";
}
```

## Использованные материалы

- [Бинарное дерево поиска | Реализация на C++](https://www.youtube.com/watch?v=VRX99cNoczY&ab_channel=LizavetaShelengovskaya)
- [Программная реализация бинарных поисковых деревьев](https://acm.bsu.by/wiki/Программная_реализация_бинарных_поисковых_деревьев)
- [Бинарные деревья поиска и рекурсия – это просто](https://habr.com/ru/post/267855/)
- [Binary Search Tree](https://www.programiz.com/dsa/binary-search-tree)
- [Алгоритмы и структуры данных для начинающих: двоичное дерево поиска](https://tproger.ru/translations/binary-search-tree-for-beginners/)
- [Двоичные деревья поиска: начальные сведения](https://algolist.ru/ds/btree.php)
