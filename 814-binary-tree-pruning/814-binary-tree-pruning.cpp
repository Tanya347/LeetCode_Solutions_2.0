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
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return NULL;
        
        TreeNode* leftSubt = pruneTree(root -> left);
        TreeNode* rightSubt = pruneTree(root -> right);
        
        if(!leftSubt && !rightSubt && root -> val == 0) {
            delete root;
            return NULL;
        }
        
        root -> left = leftSubt;
        root -> right = rightSubt;
        
        return root;
    }
};