// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    // inorder   => lefttree root righttree
    // postorder => lefttree righttree root
    
    TreeNode* build(vector<int>& inord,int x,int y,vector<int>& post,int a,int b) {
        if (x>y || a>b) return nullptr;
        
        TreeNode* node = new TreeNode(post[b]);
        
        int i = x;
        while (inord[i] != post[b]) i += 1;
         
        node->left  = build(inord,x,i-1,post,a,a+i-1-x);
        node->right = build(inord,i+1,y,post,a+i-x,b-1);
        
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        return build(inorder,0,n-1,postorder,0,n-1);
    }
};
