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
    int goodNodesCount = 0;
    void goodNodesCheck(TreeNode* node, int maxValueInPath)
    {
        if(node == NULL)
            return;
        if(node->val >= maxValueInPath)
        {
            maxValueInPath = node->val;
            ++goodNodesCount;
        }
        goodNodesCheck(node->left, maxValueInPath);
        goodNodesCheck(node->right, maxValueInPath);
    }
    int goodNodes(TreeNode* root) {
        if(root != NULL)
            goodNodesCheck(root, root->val);
        return goodNodesCount;
    }
};
