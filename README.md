# Red-Black-Tree


# Red-Black Tree Implementation

This project is a C++ implementation of a self-balancing **Red-Black Tree** data structure. It focuses on generating code for **insertion** and **deletion** operations while maintaining the Red-Black Tree properties for balanced search performance.

##  About the Project

The Red-Black Tree is a type of self-balancing binary search tree (BST) that guarantees O(log n) time complexity for insertion, deletion, and search operations.

This implementation was developed as a **final project** for an advanced data structures course. The project was completed over 3 weeks and aimed to:

* Understand and apply Red-Black Tree algorithms.
* Implement insertion and deletion with rebalancing.
* Explore pointer manipulation and memory management in C++.

---

##  Features

*  Self-balancing Red-Black Tree
* Support for insertion of nodes
*  Support for deletion of nodes with rebalancing
*  Maintains Red-Black properties after each operation:

  * Every node is red or black
  * The root is always black
  * Red nodes have black children
  * Every path from a node to descendant NIL nodes contains the same number of black nodes

---

##  Technologies Used

* **Language**: C++
* **Concepts**: Data Structures, Pointers, Recursion, Memory Management

---

## How to Run

1. Clone the repository:

   ```bash
   git clone https://github.com//red-black-tree.git
   cd red-black-tree
   ```
2. Compile the code:

   ```bash
   g++ -o rbtree main.cpp
   ```
3. Run the executable:

   ```bash
   ./rbtree
   ```

---
## 📂 Project Structure

```
red-black-tree/
├── Node.h            # Definition of Red-Black Tree Node
├── RBTree.h          # Red-Black Tree class header
├── RBTree.cpp        # Implementation of insertion and deletion
├── main.cpp          # Driver code for testing
└── README.md         # Project documentation
```


