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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> ans;
        
        queue<TreeNode*> nodes;
        nodes.push(root);
        
        unordered_map<TreeNode*, int> parent;
        parent[root] = 0;
        
        while(!nodes.empty()) {
            
            TreeNode* front = nodes.front();
            nodes.pop();
            
            if(ans.size() == parent[front])
                ans.push_back({front -> val});
            else
                ans[parent[front]].push_back(front -> val);
            
            
            if(front -> left) {
                nodes.push(front -> left);
                parent[front -> left] = parent[front] + 1;
            }
            
            if(front -> right) {
                nodes.push(front -> right);
                parent[front -> right] = parent[front] + 1;
            }
        }
        
        vector<double> avg;
        
        for(int i = 0; i < ans.size(); i++) {
            
            double n = ans[i].size();
            double average = 0;
            for(int j = 0; j < ans[i].size(); j++) {
                average += (double)ans[i][j];
            }
            
            average /= n;
            avg.push_back(average);
        }
        
        return avg;
    }
    
    
};