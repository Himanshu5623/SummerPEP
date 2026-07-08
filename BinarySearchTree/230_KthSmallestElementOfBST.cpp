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
    void inorder(TreeNode* node, vector<int>& tree){
        if(node == nullptr) return;
        inorder(node->left, tree);
        tree.push_back(node->val);
        inorder(node->right, tree);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector <int> tree;
        inorder(root, tree);
        return tree[k-1];
    }
};