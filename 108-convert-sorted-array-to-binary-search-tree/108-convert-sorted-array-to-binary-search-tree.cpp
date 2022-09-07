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
    
    
    TreeNode* convert(vector<int>& nums, int s, int e) {
        if(s <= e) {
            int mid = (s + e) / 2;
            TreeNode* node = new TreeNode(nums[mid]);
            TreeNode* leftStr = convert(nums, s, mid - 1);
            TreeNode* rightStr = convert(nums, mid + 1, e);
            node -> left = leftStr;
            node -> right = rightStr;
            return node;
        }
        return NULL;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return convert(nums, 0, nums.size() - 1);
    }
};