class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> freq;
        
        for(int i = 0; i < nums.size(); i++) {
            
            if(freq.find(target-nums[i]) != freq.end()) {
                result.push_back(i);
                result.push_back(freq[target - nums[i]]);
                return result;
            }
            
            else
                freq[nums[i]] = i;
        }
        
        return result;
    }
};