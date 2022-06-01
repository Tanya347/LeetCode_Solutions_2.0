class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++) {
            //might be possible that the beginning element itself is the subarray we need
            
            int sum = nums[i];
            if(sum > maxSum) maxSum = sum;
            for(int j = i + 1; j < nums.size(); j++) {
                sum += nums[j];
                
                //as we travel through j it automatically gives us the subarray sum and we keep comparing 
                //it with max
                if(sum > maxSum) maxSum = sum;
            }
            cout<<sum<<" ";
        }
        
        return maxSum;
    }
};
