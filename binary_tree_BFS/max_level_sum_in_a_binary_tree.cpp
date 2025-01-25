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
    unordered_map<int,int>mp;
    void maxSumLevelWise(TreeNode* node, int target)
    {
        if(node == NULL)
            return;
        ++target;
        mp[target] += node->val;
        maxSumLevelWise(node->left, target);
        maxSumLevelWise(node->right, target);
    }
    int maxLevelSum(TreeNode* root) {
        maxSumLevelWise(root, 0);
        int maxSum = INT_MIN, maxLevel = 0;
        for(auto itr:mp)
        {
            if(itr.second >= maxSum)
            {
                maxSum = itr.second;
                maxLevel = itr.first;
            }
        }
        return maxLevel;
    }
};
