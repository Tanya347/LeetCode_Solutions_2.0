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
        return containsOne(root)? root : NULL;
    }
    
    bool containsOne(TreeNode* node) {
        if(node == NULL) return false;
        
        // check whether any node in left subtree contains one
        bool leftContains1 = containsOne(node -> left);
        
        // check whether any node in right subtree contains one
        bool rightContains1 = containsOne(node -> right);
        
        // If the left subtree does not contain a 1, prune the subtree
        if(!leftContains1) node -> left = NULL;
        
        // If the right subtree does not contain a 1, prune the subtree
        if(!rightContains1) node -> right = NULL;
        
        // Return true if the current node, its left or right subtree contains 1
        return node -> val == 1 || leftContains1 || rightContains1;
    } 
};