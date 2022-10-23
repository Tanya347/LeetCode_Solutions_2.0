class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    
        int n = nums.size();
        long long nsum = (n*(n + 1))/2;
        long long nsqsum = ((long(n*(n + 1)))*(2*n + 1))/6;
        
        // sum of array
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        
        long long AminusB = sum - nsum;
        
        // sum of squares of array
        long long sqsum = 0;
        for(int j = 0; j < n; j++) {
            sqsum += nums[j]*nums[j];
        }
        
        long long AplusB = (sqsum - nsqsum) / AminusB;
        
        int a = int((AplusB + AminusB) / 2);
        int b = int((AplusB - AminusB) / 2);
        
        vector<int> ans;
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};