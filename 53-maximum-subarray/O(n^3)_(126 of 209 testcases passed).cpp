class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums.size() - 1; j++) {
                int sum = 0;
                for(int k = i; k <= j; k++) 
                    sum += nums[k];
                
                if(sum > maxSum) maxSum = sum;
            }
        }
        
        return maxSum;
    }
};
