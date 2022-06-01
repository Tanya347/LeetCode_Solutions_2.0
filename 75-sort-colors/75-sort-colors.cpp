class Solution {
public:
    void sortColors(vector<int>& nums) {
        //i is just the iterator, j is used to maintain position of 1s encountered while iterating meanwhile k
        //is used to maintain the index from end
        int i = 0, j = 0, k = nums.size() - 1;
        
        //using two pointers travel from beginning and end both
        while(i <= k) {
            
            //if 0 swap with jth element which could be 1
            if(nums[i] == 0) {
                swap(nums[i], nums[j]);
                i++;
                j++;
                
            //if 1 just move on, notice here j will remain same hence retaining the postion of j
            } else if(nums[i] == 1) {
                i++;
                
            //if 2 then swap with kth element in an attempt to send it to the back
            } else if(nums[i] == 2) {
                swap(nums[i], nums[k]);
                k--;
            }
        }
    }
};

