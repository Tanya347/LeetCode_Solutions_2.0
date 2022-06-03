class Solution {
public:
    //-4 -1 -1 0 1 2
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        if(n < 3)
            return ans;
        sort(nums.begin(), nums.end());
        
        for(int k = 0; k < n - 2; k++) {
            if(k != 0 && nums[k] == nums[k - 1])
                continue;
            int x = 0 - nums[k];
            int i = k + 1, j = n - 1;
            
            while(i < j) {
                    if(nums[i] + nums[j] == x) {
                        vector<int> a = {nums[i], nums[j], nums[k]};
                        ans.push_back(a);
                        int im = i, jn = j;
                        while(i < nums.size() && nums[i] == nums[im])
                            i++;
                        while(j < nums.size() && nums[j] == nums[jn])
                            j--;
                    }
                else if(nums[i] + nums[j] < x)
                    i++;
                else
                    j--;
            }
        }
        
        return ans;
    }
};