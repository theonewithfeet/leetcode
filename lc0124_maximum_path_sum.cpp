// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int pathsum(TreeNode *tree,int& maxsum) {
        if (!tree) return 0;
        
        int lft = tree->val + pathsum(tree->left,maxsum);
        int rgt = tree->val + pathsum(tree->right,maxsum);
        
        maxsum = max({
                    maxsum,
                    lft,
                    rgt,
                    tree->val,
                    lft+rgt-tree->val});
        
        return max({lft,rgt,tree->val});
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        pathsum(root,maxsum);
        return maxsum;
    }
};