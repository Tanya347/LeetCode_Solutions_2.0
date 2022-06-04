class Solution {
public:
    
    void subsets_helper(vector<int>&nums,int n,vector<vector<int>>&ans)
    {
        if(n == 0) {
            ans.push_back({});
            return;
        }

        subsets_helper(nums, n - 1, ans);
        
        int count = ans.size();
        
        for(int i = 0 ; i < count; i++) {
            ans.push_back(ans[i]);
            ans[i].push_back(nums[n - 1]);
        }
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        subsets_helper(nums,nums.size(),ans);
        return ans;    
    }
    
//     void subsets_helper(vector<vector<int>>& ans, vector<int>nums, int n) {
//         if(n == nums.size()) {
//             ans.push_back({});
//             return;
//         }    
        
//         subsets_helper(ans, nums, n + 1);
        
//         for(int i = 0; i < ans.size(); i++) {
//             ans.push_back(ans[i]);
//             ans[i].push_back(nums[n]);
//         }
//     }
    
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> ans;
//         subsets_helper(ans, nums, 0);
//         return ans;
//     }
};