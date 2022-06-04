class Solution {
public:
    
    void subsets_helper(vector<vector<int>>& ans, vector<int>& subset, vector<int>nums, int n) {
        if(n == 0) {
            ans.push_back(subset);
            return;
        }    
        
        subset.push_back(nums[n - 1]);
        subsets_helper(ans, subset, nums, n - 1);
        
        subset.pop_back();
        subsets_helper(ans, subset, nums, n - 1);
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        subsets_helper(ans, subset, nums, nums.size());
        return ans;
    }
};