/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lca(TreeNode* node, TreeNode* p, TreeNode* q)
    {
        if(node == NULL) return NULL;

        if(node == p || node == q) return node;
    
        TreeNode* left = lca(node->left, p, q);
        TreeNode* right = lca(node->right,p, q);

        if(left && right)
            return node;
        if(left)
            return left;
        if(right)
            return right;
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root, p, q); 
    }
};
