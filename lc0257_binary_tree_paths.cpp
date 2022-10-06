// https://leetcode.com/problems/binary-tree-paths/

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
    void findPaths(TreeNode* node,const string& path,vector<string>& result) {
        if (node->left != node->right) { 
            if (node->left)  findPaths(node->left, path+"->"+to_string(node->left->val),result);
            if (node->right) findPaths(node->right,path+"->"+to_string(node->right->val),result);
        }
        else
            result.push_back(path);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root)
            findPaths(root,to_string(root->val),result);
        return result;
    }
};