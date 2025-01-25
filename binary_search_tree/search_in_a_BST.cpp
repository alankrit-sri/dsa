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
    TreeNode* searchBST(TreeNode* node, int val)
    {
        if(node == NULL)
            return NULL;

        if(val == node->val)
            return node;

        if(val < node->val)
            return searchBST(node->left, val);

        else
            return searchBST(node->right, val);

        return NULL;
    }
};
