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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(!root) return {};
        
        vector<vector<int>> ans;
        levelOrder(root, 0, ans);
        return ans;
    }
    
    void levelOrder(TreeNode* node, int level, vector<vector<int>>& ans) {
        if(level == ans.size())
            ans.push_back({node -> val});
        else
            ans[level].push_back(node -> val);
        
        if(node -> left)
            levelOrder(node -> left, level + 1, ans);
        
        if(node -> right)
            levelOrder(node -> right, level + 1, ans);
        
    }
};