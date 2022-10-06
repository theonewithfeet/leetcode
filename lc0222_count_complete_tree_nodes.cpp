// https://leetcode.com/problems/count-complete-tree-nodes/

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
    int completeCount(TreeNode* root,int left,int right) {
        if (! root) return 0;
        
        if (left == 0) {
            auto node = root;
            do { left++; } while ((node = node->left));
        }
        if (right == 0) {
            auto node = root;
            do { right++; } while ((node = node->right));
        }
        if (left == right)
            return pow(2,left)-1;
        
        return 1 + completeCount(root->left,left-1,0) + completeCount(root->right,0,right-1);
    }
public:
    int countNodes(TreeNode* root) {
        return completeCount(root,0,0);
    }
};