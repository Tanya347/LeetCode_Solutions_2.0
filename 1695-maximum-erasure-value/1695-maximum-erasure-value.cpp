class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int left = 0, right = 0, ans = 0, sum = 0;
        
        unordered_map<int, int> count;
        
        while(right < nums.size()){
            count[nums[right]]++;
            sum = sum + nums[right];
            
            while(count[nums[right]] > 1){
                sum = sum - nums[left];
                count[nums[left]]--;
                left++;
            }
            
            ans = max(ans, sum);
            right++;
        }
        return ans;
    }
};