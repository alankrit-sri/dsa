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
    int maxDepthOfBST = 0;
    void bstLen(TreeNode* node, int currentDepth)
    {
        if(node == NULL)
            return;
        ++currentDepth;
        if(currentDepth > maxDepthOfBST)
            maxDepthOfBST = currentDepth;
        
        bstLen(node->left, currentDepth);
        bstLen(node->right, currentDepth);
    }
    int maxDepth(TreeNode* root) {
        bstLen(root, 0);
        return maxDepthOfBST;
    }
};
