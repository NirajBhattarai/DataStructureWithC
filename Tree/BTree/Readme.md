

A B-tree is a self-balancing tree data structure that maintains sorted data in a way that allows searches, insertions, and deletions to be performed in logarithmic time. B-trees are particularly well-suited for applications in which the data is too large to fit entirely in main memory.

The following are characteristics of a B-tree:

All leaves are at the same level.
A B-tree with height 'h' is represented by a root, internal nodes, and leaves.
Each node has at most 'm' children.
Each node (except the root) has at least ceil(m/2) children.
The root has at least two children if it is not a leaf node.
A non-leaf node with 'k' children contains 'k-1' keys.
Keys in nodes are sorted.

# B-tree of Order 4

Given data: `6,4,22,10,2,14,3,8,11,13,5,9`

## B-tree Construction:

1. Insert `6`:  
   `6`

2. Insert `4`:  
   `4,6`

3. Insert `22`:  
   `4,6,22`

4. Insert `10`:  
   Splitting `4,6,10,22`:

    ```
        6
       / \
      4   10,22
    ```

5. Insert `2`:

    ```
        6
       / \
    2,4   10,22
    ```

6. Insert `14`:

    ```
           6
          / \
       2,4   10
            /   \
          14    22
    ```

7. Insert `3`:

    ```
           6
          / \
      2,3,4   10
            /   \
          14    22
    ```

8. Insert `8`:

    ```
           6
          / \
      2,3,4   8,10
                \
              14,22
    ```

9. Insert `11`:

    ```
           6
          / \
      2,3,4   10
        /  \   \
       8   11   14,22
    ```

10. Insert `13`:

    ```
           6
          / \
      2,3,4   10
        /  \   \
       8   11   13
                /  \
              14   22
    ```

11. Insert `5`:

    ```
           6
        /     \
      2,3,4   5,10
      /        /   \
     8        13   14,22
    ```

12. Insert `9`:

    ```
           6,9
        /   |   \
      2,3,4 5   10
      /        /   \
     8        13   14,22
    ```

## Final B-tree:

    ```
           6,9
        /   |   \
      2,3,4 5   10
      /        /   \
     8        13   14,22
    ```
