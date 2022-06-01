class Solution {
public:
    
    //Kadane's Algorithm
    
    int maxSubArray(vector<int>& nums) {
        
        int currSum = nums[0], maxSum = nums[0];
        
        //taken first element assuming size of current subarray to be 1
        for(int i = 1; i < nums.size(); i++) {
            
            //check whether adding the current element adds any value to the subarray being carried so far
            //and also check whether current element itself is bigger than currSum
            
            //basically seeing whether we should continue with previous subarray or move forward with the
            //element
            currSum = max(currSum + nums[i], nums[i]);
            
            //now after getting the optimal curr sum compare it with the maximum sum we have encountered
            //so far
            maxSum = max(currSum, maxSum);
        }
        
        
        return maxSum;
    }
};