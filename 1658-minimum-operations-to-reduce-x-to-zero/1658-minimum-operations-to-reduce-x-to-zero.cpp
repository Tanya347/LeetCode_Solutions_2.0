class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
    
        int total = 0;
        for(int i : nums)total+=i;
        
        int target = total -x;
        
        if(target < 0)
            return -1;
        
        if(target ==0)
            return nums.size();
        
        int i = 0, j = 0, sum = 0;
        int maxLen = -1;
   
        while (j < nums.size()) {
            sum += nums[j];
            if (sum < target) {
                j++;
            }
            
            else if (sum == target) {
                maxLen = max(maxLen, j-i+1);
                j++;
            }
            
            else if (sum > target) {
                while (sum > target) {
                    sum -= nums[i];
                    i++;
            }
                
            if(sum == target){
                maxLen = max(maxLen, j-i+1);
            }
                
            j++;
        }
    }
        
    if(maxLen == -1)
        return -1;
        
    return nums.size()-maxLen;
        
    }
};