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
    private:
    int maxSum;
    int calculateSum(TreeNode* node){
        if (node == nullptr) return 0;

        int leftSum = max(0, calculateSum(node->left));
        int rightSum = max(0, calculateSum(node->right));

        maxSum = max(maxSum, node->val + leftSum + rightSum);

        return node->val + max(leftSum, rightSum);
    }
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        calculateSum(root);
        return maxSum;
    }
};