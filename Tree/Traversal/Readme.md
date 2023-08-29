# Tree Traversals

Tree traversal is a foundational concept in data structures. The primary tree traversal methods for binary trees are Preorder, Inorder, and Postorder. In this guide, we will display these trees visually and then list their traversal sequences.

## Definitions:

1. **Preorder Traversal (DLR)**:
   - Visit the current node (D for Data)
   - Traverse the left subtree (L for Left)
   - Traverse the right subtree (R for Right)

2. **Inorder Traversal (LDR)**:
   - Traverse the left subtree
   - Visit the current node
   - Traverse the right subtree

3. **Postorder Traversal (LRD)**:
   - Traverse the left subtree
   - Traverse the right subtree
   - Visit the current node

## Trees and Their Traversals:

### Tree of Height 1:

         A

- **Preorder**: A
- **Inorder**: A
- **Postorder**: A  

### Tree of Height 2:


        B
       / \
      A   C

- **Preorder**: B, A, C
- **Inorder**: A, B, C
- **Postorder**: A, C, B



### Tree of Height 3:

        D
       / \
      B   E
     / \
    A   C 

- **Preorder**: D, B, A, C, E
- **Inorder**: A, B, C, D, E
- **Postorder**: A, C, B, E, D

### Tree of Height 4: 

            J
          /   \
         F     K
        / \   / \
        D   G L   M
        / \   \
        B   E   I
- **Preorder**: J, F, D, B, E, G, I, K, L, M
- **Inorder**: B, D, E, F, I, G, J, L, K, M
- **Postorder**: B, E, D, I, G, F, L, M, K, J


# Tree Traversal Algorithms

## 1. Preorder Traversal (Recursive):

**Algorithm:**
1. Start from the root node.
2. Visit the node.
3. If the node has a left child, recursively call the Preorder function on the left child.
4. If the node has a right child, recursively call the Preorder function on the right child.

**Pseudocode:**
```pseudo
function Preorder(node):
    if node is not null:
        print(node.value)
        Preorder(node.left)
        Preorder(node.right)
```


# Inorder Traversal Algorithm


**Algorithm:**
1. Start from the root node.
2. If the node has a left child, recursively call the Inorder function on the left child.
3. Visit the node.
4. If the node has a right child, recursively call the Inorder function on the right child.

**Pseudocode:**
```pseudo
function Inorder(node):
    if node is not null:
        Inorder(node.left)
        print(node.value)
        Inorder(node.right)
``` 
# Postorder Traversal Algorithm

## Postorder Traversal (Recursive):

**Algorithm:**
1. Start from the root node.
2. If the node has a left child, recursively call the Postorder function on the left child.
3. If the node has a right child, recursively call the Postorder function on the right child.
4. Visit the node.

**Pseudocode:**
```pseudo
function Postorder(node):
    if node is not null:
        Postorder(node.left)
        Postorder(node.right)
        print(node.value)
```