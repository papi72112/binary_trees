# 0x1D. C - Binary trees

## Description

In this project we learn about the binary tree data structure.

Binary trees are non-linear hierarchical data structures where each node can have at most two children: a left child and a right child. They are fundamental to many algorithms and data structures in computer science. A binary data structure has the following properties, application, benefits, limitations and types.

**Properties:**

- Nodes contain data and references to their children.

- The root node is at the top, with no parent.

- Each node has 0, 1, or 2 children.

- Children are ordered as left and right.


**Applications:**

- Heap data structure for efficient priority queues.

- Binary search trees for efficient data search and sorting.

- Huffman coding for data compression.

- Syntax trees for representing the structure of computer programs.


**Benefits:**

- Efficient for searching and sorting.

- Flexibility for representing hierarchical relationships.

- Widely used in various algorithms and data structures.


**Limitations:**

- Can become unbalanced, impacting performance.

- Not ideal for large data sets with many levels.


**Types:**

There are different types of binary trees. They can be classified as follows

- **Types of binary trees based on the number of children**:
    - **Full/Strict/Proper Binary Tree** = A tree where every node has 0 or 2 children.
    - **Degenerate Binary tree** = A tree where every internal node has one child.
    - **Skewed Binary Tree** = A degenerate binary tree which is either dominated by the left or right nodes
- **Types of binary trees based on the completion of levels**:
    - **Complete Binary Tree** = A binary tree where all the levels are filled except maybe the last level, and that last leaf node must be left oriented
    - **Perfect Binary Tree** = A binary tree where all internal nodes have two children and all leaf nodes are at the same level.
    - **Balanced Binary Tree** = A binary tree where for every node the difference in height of its left sub-tree and right sub-tree is not more than an arbitrary `k` value.

As much as there are different types of binary trees, there are also different flavors of binary trees.

In this project we worked on four flavors of binary trees:

1.  Simple binary trees
2.  Binary search trees
3.  AVL Trees
4.  Max binary heaps

## Simple binary trees

Simple binary trees are the general form of binary trees with no special attributes.

| Functions | Description |
| --- | --- |
| [0-binary\_tree\_node.c](./0-binary_tree_node.c "./0-binary_tree_node.c") | A function that creates a binary tree node. |
| [1-binary\_tree\_insert\_left.c](./1-binary_tree_insert_left.c "./1-binary_tree_insert_left.c") | A function that inserts a node as the left-child of another node. |
| [2-binary\_tree\_insert\_right.c](./2-binary_tree_insert_right.c "./2-binary_tree_insert_right.c") | A function that inserts a node as the right-child of another node. |
| [3-binary\_tree\_delete.c](./3-binary_tree_delete.c "./3-binary_tree_delete.c") | A function that deletes an entire binary tree. |
| [4-binary\_tree\_is\_leaf.c](./4-binary_tree_is_leaf.c "./4-binary_tree_is_leaf.c") | A function that checks if a node is a leaf. |
| [5-binary\_tree\_is\_root.c](./4-binary_tree_is_root.c "./4-binary_tree_is_root.c") | A function that checks if a node is a root. |
| [6-binary\_tree\_preorder.c](./6-binary_tree_preorder.c "./6-binary_tree_preorder.c") | A function that traverses through a binary tree using pre-order traversal. |
| [7-binary\_tree\_inorder.c](./7-binary_tree_inorder.c "./7-binary_tree_inorder.c") | A function that traverses through a binary tree using in-order traversal. |
| [8-binary\_tree\_postorder.c](./8-binary_tree_postorder.c "./8-binary_tree_postorder.c") | A function that traverses through a binary tree using post-order traversal. |
| [9-binary\_tree\_height.c](./9-binary_tree_height.c "./9-binary_tree_height.c") | A function that measures the height of a node in a binary tree. |
| [10-binary\_tree\_depth.c](./10-binary_tree_depth.c "./10-binary_tree_depth.c") | A function that measures the depth of a node in a binary tree. |
| [11-binary\_tree\_size.c](./11-binary_tree_size.c "./11-binary_tree_size.c") | A function that measures the size of a binary tree. |
| [12-binary\_tree\_leaves.c](./12-binary_tree_leaves.c "./12-binary_tree_leaves.c") | A function that counts the leaves in a binary tree. |
| [13-binary\_tree\_nodes.c](./13-binary_tree_nodes.c "./13-binary_tree_nodes.c") | A function that counts the number of nodes with at least 1 child in a binary trees (i.e. number of internal nodes). |
| [14-binary\_tree\_balance.c](./14-binary_tree_balance.c "./14-binary_tree_balance.c") | A function that measures the balance factor of a binary tree. |
| [15-binary\_tree\_is\_full.c](./15-binary_tree_is_full.c "./15-binary_tree_is_full.c") | A function that checks if a binary tree is a full binary tree. |
| [16-binary\_tree\_is\_perfect.c](./16-binary_tree_is_perfect.c "./16-binary_tree_is_perfect.c") | A function that checks if a binary tree is a perfect binary tree. |
| [17-binary\_tree\_sibling.c](./17-binary_tree_sibling.c "./17-binary_tree_sibling.c") | A function that returns the sibling of a node. |
| [18-binary\_tree\_uncle.c](./18-binary_tree_uncle.c "./18-binary_tree_uncle.c") | A function that returns the uncle of a node. |
| [100-binary\_trees\_ancestor.c](./100-binary_trees_ancestor.c "./100-binary_trees_ancestor.c") | A function that returns the lowest common ancestor of two nodes. |
| [101-binary\_tree\_levelorder.c](./101-binary_tree_levelorder.c "./101-binary_tree_levelorder.c") | A function that traverses through a binary tree using level-order traversal. |
| [102-binary\_tree\_is\_complete.c](./102-binary_tree_is_complete.c "./102-binary_tree_is_complete.c") | A function that checks if a binary tree is a complete binary tree. |
| [103-binary\_tree\_rotate\_left.c](./103-binary_tree_rotate_left.c "./103-binary_tree_rotate_left.c") | A function that rotates a binary tree to the left. |
| [104-binary\_tree\_rotate\_right.c](./104-binary_tree_rotate_right.c "./104-binary_tree_rotate_right.c") | A function that rotates a binary tree to the right. |

## Binary Search Trees

A binary search tree is a binary tree where for every node all the elements in its left sub-tree are smaller in value than the node and all the elements in its right sub-tree are larger in value than the node. This feature is very useful for searching, hence the name Binary Search Tree (BST).

| Functions | Description |
| --- | --- |
| [110-binary\_tree\_is\_bst.c](./110-binary_tree_is_bst.c "./110-binary_tree_is_bst.c") | A function that checks if a binary tree is a BST. |
| [111-bst\_insert.c](./111-bst_insert.c "./111-bst_insert.c") | A function that inserts a node into a BST. |
| [112-array\_to\_bst.c](./112-array_to_bst.c "./112-array_to_bst.c") | A function that builds a BST from an array. |
| [113-bst\_search.c](./113-bst_search.c "./113-bst_search.c") | A function that searches for a value in a BST. |
| [114-bst\_remove.c](./114-bst_remove.c "./114-bst_remove.c") | A function that removes a node from a BST. |
| [115-O](./115-O "./115-O") | Average time complexities for insertion, deletion and searching operations of Binary Search Trees. |

## AVL Trees

AVL tree (named after inventors Adelson-Velsky and Landis) is a self-balancing binary search tree. In an AVL tree the difference between the heights of the left sub-tree and right-sub-tree of a node can only be -1, 0 or 1.

| Functions | Description |
| --- | --- |
| [120-binary\_tree\_is\_avl.c](./120-binary_tree_is_avl.c "./120-binary_tree_is_avl.c") | A function that checks if a binary tree is an AVL tree. |
| [121-avl\_insert.c](./121-avl_insert.c "./121-avl_insert.c") | A function that inserts a value in an AVL tree. |
| [122-array\_to\_avl.c](./122-array_to_avl.c "./122-array_to_avl.c") | A function that builds an AVL Tree from an array of integers. |
| [123-avl\_remove.c](./123-avl_remove.c "./123-avl_remove.c") | A function that removes a node from an AVL tree. |
| [124-sorted\_array\_to\_avl.c](./124-sorted_array_to_avl.c "./124-sorted_array_to_avl.c") | A function that builds an AVL tree from a sorted array of integers. |
| [125-O](./125-O "./125-O") | Average time complexities for insertion, deletion and searching operations of AVL Trees. |

## Max Binary Heap

A binary heap is a complete binary tree that follows a specific order property. The properties are as follows:

- **Min Binary Heap** = The value of each node is smaller than all its descendant nodes. The minimum value will always be at the root.
- **Max Binary Heap** = The value of each node is larger than all its descendant nodes. The maximum value will always be the root.

In this project we worked with Max Binary heap.

| Functions | Description |
| --- | --- |
| [130-binary\_tree\_is\_heap.c](./130-binary_tree_is_heap.c "./130-binary_tree_is_heap.c") | A function that checks if a binary tree is a valid Max-binary heap. |
| [131-heap\_insert.c](./131-heap_insert.c "./131-heap_insert.c") | A function that inserts a value in to a Max Binary Heap. |
| [132-array\_to\_heap.c](./132-array_to_heap.c "./132-array_to_heap.c") | A function that builds a Max Binary Heap from an array. |
| [133-heap\_extract.c](./133-heap_extract.c "./133-heap_extract.c") | A function that extracts the root node of a Max Binary Heap. |
| [134-heap\_to\_sorted\_array.c](./134-heap_to_sorted_array.c "./134-heap_to_sorted_array.c") | A function that converts a Max Binary Heap to sorted array of integers, that are sorted in descending order. |
| [135-O](./135-O "./135-O") | Average time complexities for insertion, extraction and searching operations of Max Binary Heap. |
