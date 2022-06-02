class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        
        //trying to find the index just before where the peak ends as we notice that in every permutation 
        //there is a slope from the back which increases upto a certain point, and then the next element is  
        //lesser than the peak. This peak may be the last element as well i.e. just one element in slope
        while(i >= 0 && nums[i] >= nums[i + 1]) i--;
        
        if(i >= 0) {
            
            //we try to find the element just greater than element at i
            int j = nums.size() - 1;
            while(j > i && nums[j] <= nums[i]) j--;
            
            swap(nums[i], nums[j]);
            
            //we reverse the number after i after swapping as we are transitioning to the next place value we
            //have to begin with the minimum most number, and as the part after i is decreasing already
            //we can just make it increasing by reversering it
            reverse(nums.begin() + i + 1, nums.end());
        } else {
            reverse(nums.begin(), nums.end());
        }
        
    }
};