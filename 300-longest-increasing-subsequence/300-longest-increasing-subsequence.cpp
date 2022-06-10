class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> dp(nums.size(), 1);
        
        int ans = 1;
        
        for(int i = 0; i < nums.size(); i++) {
            int max_ans = 1;
            for(int j = i - 1; j >= 0; j--) {
                int l = 1;
                if(nums[i] > nums[j])
                    max_ans = max(max_ans, dp[j] + 1);
            }
            dp[i] = max_ans;
            ans = max(max_ans, ans);
        }
        
        return ans;
    }
};