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
    string tree2str(TreeNode* root) {
        
        if(!root) 
            return "";
        
        string leftStr = tree2str(root -> left);
        string rightStr = tree2str(root -> right);
        
        string ans;
        
        if(rightStr == "" && leftStr != "")
            ans = to_string(root -> val) + "(" + leftStr + ")";
        
        else if(rightStr == "" && leftStr == "")
            ans = to_string(root -> val);
        
        else
            ans = to_string(root -> val) + "(" + leftStr + ")" + "(" + rightStr + ")";
        
        return ans;
    }
};