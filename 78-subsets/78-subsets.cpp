class Solution {
public:
    vector<vector<int>> subsets_helper(vector<int>& nums, int n) {
        
        if(n == 0)
            return {{}};
        
        vector<vector<int>> ans = subsets_helper(nums, n - 1);
        vector<vector<int>> temp = ans;
        
        for(int i = 0; i < temp.size(); i++) {
            temp[i].push_back(nums[n - 1]);
        }
        
        ans.insert(ans.end(), temp.begin(), temp.end());
        return ans;
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        return subsets_helper(nums, nums.size());
    }

};