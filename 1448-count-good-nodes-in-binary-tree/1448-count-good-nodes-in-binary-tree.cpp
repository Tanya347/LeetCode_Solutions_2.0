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
    
    void countGoodNodes(TreeNode* root, int maximum, int& count) {
            
        if(!root) return;
        
        if(root -> val >= maximum) {
            maximum = root -> val;
            count++;
        }
        
        countGoodNodes(root -> left, maximum, count);
        countGoodNodes(root -> right, maximum, count);
        
    }
    
    int goodNodes(TreeNode* root) {
        int maximum = INT_MIN;
        int count = 0;
        countGoodNodes(root, maximum, count);
        return count;
    }
};