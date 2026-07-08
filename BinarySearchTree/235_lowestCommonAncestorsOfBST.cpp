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
    private:
    void getPath(TreeNode *root, vector<TreeNode*> &path, TreeNode *dest){
        path.push_back(root);
        if(dest->val == root->val) return;
        if(dest->val < root->val){
            getPath(root->left, path, dest);
        }
        else{
            getPath(root->right, path, dest);
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;
        getPath(root, pathP, p);
        getPath(root, pathQ, q);

        int limit = min(pathP.size(), pathQ.size());
        for(int i = 0; i < limit; i++){
            if(pathP[i]->val != pathQ[i]->val){
                return pathP[i-1];
            }
        }
        return (pathP.size() < pathQ.size() ? pathP.back() : pathQ.back());
    }
};