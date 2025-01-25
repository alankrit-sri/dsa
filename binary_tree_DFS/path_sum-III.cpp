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
    // Helper function to count paths with sum equal to targetSum starting from the current node
    int pathSumCheck(TreeNode* node, long int currentSum, int targetSum) {
        if (node == NULL) return 0;
        
        // Update current sum with the value of the current node
        currentSum += node->val;
        
        // Initialize the count of valid paths
        int pathsFound = 0;
        
        // If the current sum equals the target sum, increment the count
        if (targetSum == currentSum) ++pathsFound;
        
        // Recursively check left and right subtrees
        return pathsFound + pathSumCheck(node->left, currentSum, targetSum) + pathSumCheck(node->right, currentSum, targetSum);
    }

    // Main function to count paths that sum to targetSum in the binary tree
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return 0;
        
        // Count valid paths starting from the current root and all its descendants
        // return pathSumCheck(root, 0, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
        return pathSumCheck(root, 0, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};
