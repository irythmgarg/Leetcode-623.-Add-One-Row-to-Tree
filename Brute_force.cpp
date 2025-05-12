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

    // Helper function to insert a row of nodes with the given value at the specified depth
    void isnot(unordered_set<TreeNode*> st, TreeNode* root, int val)
    {
        if (!root) return;

        // If the current node is in the set, insert new nodes between it and its children
        if (root && st.find(root) != st.end())
        {
            TreeNode* node = new TreeNode(val);   // New node for the left side
            TreeNode* node2 = new TreeNode(val);  // New node for the right side

            node->left = root->left;   // Link original left subtree to the new node
            node2->right = root->right; // Link original right subtree to the new node

            root->left = node;   // Attach new left node to root
            root->right = node2; // Attach new right node to root

            st.erase(root->left); // Remove the old left child from the set if needed
        }

        // Recurse to left and right children
        if (root->left) isnot(st, root->left, val);
        if (root->right) isnot(st, root->right, val);
    }

    // Main function to add one row to the tree
    TreeNode* addOneRow(TreeNode* root, int val, int depth)
    {
        // Special case: if depth is 1, create a new root
        if (depth == 1)
        {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }

        int level = 1;
        queue<TreeNode*> q;
        q.push(root);

        // Perform level order traversal to reach depth - 1
        while (!q.empty())
        {
            int n = q.size();

            // Stop if the next level is the target depth
            if (level == depth - 1)
                break;

            while (n--)
            {
                TreeNode* top = q.front(); q.pop();
                if (top->left) q.push(top->left);
                if (top->right) q.push(top->right);
            }

            level++;
        }

        // Collect all nodes at depth - 1 into a set
        unordered_set<TreeNode*> st;
        while (!q.empty())
        {
            st.insert(q.front());
            q.pop();
        }

        // Insert new row under each node in the set
        isnot(st, root, val);

        return root;
    }
};
