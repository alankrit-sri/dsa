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
    vector<int> rightSideArray;
    void rightSideViewData(TreeNode* node, int currentLevel)
    {
        if(node == NULL)
            return;
        ++currentLevel;
        if(rightSideArray.size() < currentLevel)
            rightSideArray.push_back(node->val);
        rightSideViewData(node->right, currentLevel);
        rightSideViewData(node->left, currentLevel);
    }
    vector<int> rightSideView(TreeNode* root) {
        rightSideViewData(root, 0);
        return rightSideArray;
    }
};
