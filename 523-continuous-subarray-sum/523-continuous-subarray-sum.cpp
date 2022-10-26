class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int prefix_sum = 0;
        
        unordered_map<int, int> remainders;
        
        for(int i = 0; i < nums.size(); i++) {
            prefix_sum += nums[i];
            
            if((prefix_sum % k == 0) && i > 0)
                return true;
            
            // if a similar remainder already exists then that means a subarray of similar sum 
            // exists hence return true
            if(remainders.find(prefix_sum % k) != remainders.end()) {
                
                // checking to see if the index of previous remainder is not same as 
                // we need a subarray of size 2
                if(i - remainders[prefix_sum % k] > 1)
                return true;
            }
            
            // if this entry doesn't exist then just add it to the map
            else {
                remainders[prefix_sum % k] = i;
            }
        }
        
        return false;
        
    }
};