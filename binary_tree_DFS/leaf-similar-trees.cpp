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
    vector<int>leafArray1, leafArray2;
    void leafSimilarCheck(TreeNode* node, vector<int>&leafArrayTemp)
    {
        if(node == NULL)
            return;
        
        if(node->left == NULL && node->right == NULL)
            leafArrayTemp.push_back(node->val);
        
        leafSimilarCheck(node->left, leafArrayTemp);
        leafSimilarCheck(node->right, leafArrayTemp);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        leafSimilarCheck(root1, leafArray1);
        leafSimilarCheck(root2, leafArray2);

        if(leafArray1 == leafArray2)
            return true;
        return false;
    }
};
