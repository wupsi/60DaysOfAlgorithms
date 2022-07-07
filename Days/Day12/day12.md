# Binary Search Tree - Day 12

Продолжаем практиковаться на задачах Binary Search Tree!

## Leetcode problems

### Base:

- [✔️] [A. Convert Sorted Array To Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)
- [✔️] [B. Lowest Common Ancestor Of A Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)
- [✔️] [C. Find Mode In Binary Search Tree](https://leetcode.com/problems/find-mode-in-binary-search-tree/)
- [✔️] [D. Range Sum Of BST](https://leetcode.com/problems/range-sum-of-bst/)
- [❌] [E. Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees/)
- [✔️] [F. Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)

### Additional

- [✔️] [A. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/submissions/)
- [✔️] [B. Increasing Order Search Tree](https://leetcode.com/problems/increasing-order-search-tree/)
- [✔️] [C. Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/)
- [✔️] [D. Minimum Absolute Difference in BST](https://leetcode.com/problems/minimum-absolute-difference-in-bst/)
- [✔️] [E. Minimum Distance Between BST Nodes](https://leetcode.com/problems/minimum-distance-between-bst-nodes/)

Задачу Base-E не решил, там скорее всего дп(динамическое программирование), чего я пока что не знаю. Чтобы найти все уникальные деревья без использования дп, пришлось бы найти все возможные перестановки чисел от 1 до `n`, что равно `n!`. А как можно увидеть из описания, мы ограничены `n = 19`, что дает нам `19! = 121 645 100 000 000 000` перестановок. Такое количество перестановок в любом случае не пройдет ограничений по времени :(
