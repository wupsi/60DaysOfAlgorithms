## Linked Lists - Day 6

## Problems

- [✔️] [A. Алфавитно-частотный словарь](https://informatics.msk.ru/mod/statements/view.php?chapterid=112510#1)
- [✔️] [B. Словарь по частотам](https://informatics.msk.ru/mod/statements/view.php?chapterid=112511#1)
- [✔️] [C. Словарь для файла](https://informatics.msk.ru/mod/statements/view.php?chapterid=112512#1)
- [✔️] [D. Словарь для файла с пунктуацией](https://informatics.msk.ru/mod/statements/view.php?chapterid=112513#1)
- [✔️] [E. Список чисел](https://informatics.msk.ru/mod/statements/view.php?chapterid=112514#1)
- [✔️] [F. Построчный редактор](https://informatics.msk.ru/mod/statements/view.php?chapterid=112515#1)
- [❌] [G. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)
- [❌] [H. Remove Duplicates From Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)
- [❌] [I. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)
- [❌] [J. Intersection Of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/)
- [❌] [K. Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/)
- [❌] [L. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)
- [❌] [M. Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)
- [❌] [N. Delete Node In A Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list/)

Потратил кучу времени на первой задаче, вообще не подходящая под `LL`. Хотя является лабраторной работой универа на тему связных списков. Интересно то, что в задаче надо сначала прочитать с файла, а затем записать в файл. Каждое слово с файла я проверял следующим образом:
- Если слово первое, вставляю его в конец списка
- Если слово не первое и есть в списке(метод find()) увеличиваю счетчик слова на 1
- Если слово не первое и его нет в списке, добавляю его в список, предварительно сортируя по приоритетности в алфавите.

По итогу добавление по приоритетности в список получился довольно медленный из-за обхода всего списка + обхода всех элементов строки, и у меня прошло лишь 13 из 21 тестов. Другие тесты не прошли по времени :/. В остальных задачах до G смысла не вижу, обычная сортировка не связанная с `LL`. 
Дальше я приступил к задачам с литкода.


UPD: Залил решения A-F на питоне :)
