class Solution {
public:
    
    void subset_helper(vector<vector<int>>& ans, vector<int>& subset, vector<int> nums, int i, int k) {
        if(subset.size() == k) {
            ans.push_back(subset);
            return;
        }
        
        for(int j = i; j < nums.size(); j++) {
            subset.push_back(nums[j]);
            subset_helper(ans, subset, nums, j + 1, k);
            subset.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        for(int k = 0; k <= nums.size(); k++) {
            subset_helper(ans, subset, nums, 0, k);
        }
        return ans;
    }
};