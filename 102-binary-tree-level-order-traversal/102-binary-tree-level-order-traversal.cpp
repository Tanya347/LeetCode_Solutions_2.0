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
        
        vector<vector<int>> ans;
        
        if(!root)
            return ans;
        
        queue<TreeNode*> nodes;
        nodes.push(root);
        unordered_map<TreeNode*, int> parent;
        parent[root] = 0;
        
        while(!nodes.empty()) {
            
            TreeNode* front = nodes.front();
            nodes.pop();
                        
            if(parent[front] == ans.size()) {
                ans.push_back({front -> val});
            } else {
                ans[parent[front]].push_back(front -> val);
            }
             
            if(front -> left) {
                parent[front -> left] = parent[front] + 1;
                nodes.push(front -> left);
            }
            
            if(front -> right) {
                parent[front -> right] = parent[front] + 1;
                nodes.push(front -> right);
            }
        }
        
        return ans;
    }
};