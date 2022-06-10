class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> bs;
        bs.push_back(nums[0]);
        int count = 1;
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > bs.back()) {
                bs.push_back(nums[i]);
                count++;
            }
            else {
                int idx = lower_bound(bs.begin(), bs.end(), nums[i]) - bs.begin();
                bs[idx] = nums[i];
            }
        }
        
        return count;
    }
};