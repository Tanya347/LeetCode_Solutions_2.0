class Solution {
public:
    //-4 -1 -1 0 1 2
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        
        if(nums.size() < 3)
            return result;
        
        for(int i = 0; i < nums.size() - 2;) {
            
            int j = i + 1, k = nums.size() - 1;
            int x = 0 - nums[i];
            
            while(j < k) {
                if(nums[j] + nums[k] == x) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    while(j + 1 < nums.size() && nums[j] == nums[j + 1]) j++;
                    j++;
                    while(k - 1 >= 0 && nums[k] == nums[k - 1]) k--;
                    k--;
                } else if(nums[j] + nums[k] > x) {
                    while(k - 1 >= 0 && nums[k] == nums[k - 1]) k--;
                    k--;
                } else {
                    while(j + 1 < nums.size() && nums[j] == nums[j + 1]) j++;
                    j++;
                }
            }
            
            while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
                i++;
        }
        
        return result;
    }
};