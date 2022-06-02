class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        for(int i = 0; i < nums.size(); i++) {
            if(freq.find(nums[i]) == freq.end())
                freq[nums[i]]++;
            else
                return nums[i];
        }
        
        return 0;
    }
};