// https://leetcode.com/problems/maximum-binary-tree/

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
    TreeNode* maxTree(vector<int>& nums,int lo,int hi) {
        if (lo >= hi) return nullptr;
        
        int idx=lo;
        for (int i=lo; i<hi; i++)
            if (nums[i] > nums[idx])
                idx = i;
        
        TreeNode* node = new TreeNode(nums[idx]);
        
        node->left = maxTree(nums,lo,idx);
        node->right = maxTree(nums,idx+1,hi);
        
        return node;
    } 
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return maxTree(nums,0,nums.size());
    }
};