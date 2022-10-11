// https://leetcode.com/problems/binary-search-tree-iterator/

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
class BSTIterator {
    stack<TreeNode*> nodes;
    
    void pushLeft(TreeNode *node) {
        while (node) {
            nodes.push(node);
            node = node->left;
        }
    } 
public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        if (hasNext()) {
            TreeNode *node = nodes.top(); nodes.pop();
            pushLeft(node->right);
            return node->val;
        }
        return -1;
    }
    
    bool hasNext() {
        return nodes.empty() == false;
    }
};