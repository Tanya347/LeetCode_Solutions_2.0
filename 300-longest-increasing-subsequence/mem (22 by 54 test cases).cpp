class Solution {
public:
    int lis_Ending_Here(vector<int> nums, int i) {
        if(i == 0)
            return 1;
        
        int ans = 1;
        
        for(int j = i - 1; j >= 0; j--) {
            if(nums[j] < nums[i])
                ans = max(ans, 1 + lis_Ending_Here(nums, j));
        }
        
        return ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int max_ans;
        for(int i = 0; i <nums.size(); i++) {
            max_ans = max(max_ans, lis_Ending_Here(nums, i));
        }
        return max_ans;
    }
};
