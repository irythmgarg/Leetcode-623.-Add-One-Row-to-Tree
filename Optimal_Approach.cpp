/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    // Recursive DFS function to reach depth - 1 and insert new nodes
    void dfs(TreeNode* root, int val, int depth, int level)
    {
        if (!root) return;

        // When at the level just above the target depth
        if (level == depth - 1)
        {
            TreeNode* node = new TreeNode(val);   // New node to insert on the left
            TreeNode* node1 = new TreeNode(val);  // New node to insert on the right

            node->left = root->left;      // Link original left child
            node1->right = root->right;   // Link original right child

            root->left = node;   // Attach new left node
            root->right = node1; // Attach new right node
            return;
        }

        // Continue traversing the tree
        dfs(root->left, val, depth, level + 1);
        dfs(root->right, val, depth, level + 1);
    }

    // Main function to add a row at a given depth
    TreeNode* addOneRow(TreeNode* root, int val, int depth)
    {
        // Special case: new root creation if depth is 1
        if (depth == 1)
        {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }

        // Start DFS from root at level 1
        dfs(root, val, depth, 1);
        return root;
    }
};
