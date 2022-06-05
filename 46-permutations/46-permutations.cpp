class Solution {
public:
    
    void permute_helper(vector<int> nums, vector<int>& temp, vector<vector<int>>& ans, int* freq) {
        
        if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(!freq[i]) {
                temp.push_back(nums[i]);
                freq[i] = 1;
                
                permute_helper(nums, temp, ans, freq);
                
                temp.pop_back();
                freq[i] = 0;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        int *freq = new int[nums.size()];
        
        for(int i = 0; i < nums.size(); i++)
            freq[i] = 0;
        
        permute_helper(nums, temp, ans, freq);
        
        return ans;
    }
};