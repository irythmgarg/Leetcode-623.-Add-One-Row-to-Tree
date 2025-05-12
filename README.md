# Leetcode-623.-Add-One-Row-to-Tree

📘 README.md — Add One Row to Tree (BFS & DFS Solutions)
🧠 Problem Statement
Given the root of a binary tree, a value val, and a depth depth, insert a row of nodes with value val at the given depth. Return the modified tree’s root.

If depth == 1, a new root is created, and the original tree becomes the left subtree.

---

✅ Features Covered
Two approaches implemented:

Breadth-First Search (BFS)

Depth-First Search (DFS)

---

🔎 Approach 1: BFS (Level Order Traversal)

📌 Key Ideas:

Use a queue to perform BFS and stop at level depth - 1.

Insert new nodes with value val as left and right children.

Link original left and right children to the newly added nodes.

---

🧩 Time & Space:
Time Complexity: O(N), where N is the number of nodes.

Space Complexity: O(W), where W is the maximum width of the tree.

---

🔎 Approach 2: DFS (Recursive)

📌 Key Ideas:

Use recursive DFS to traverse the tree.

When the current level reaches depth - 1, insert new nodes.

Attach old left and right children accordingly.

---

🧩 Time & Space:
Time Complexity: O(N)

Space Complexity: O(H), where H is the height of the tree (due to recursion stack).

---
👨‍💻 Author
Ridham Garg
B.Tech Computer Engineering
Thapar University, Patiala
Roll No: 102203014



