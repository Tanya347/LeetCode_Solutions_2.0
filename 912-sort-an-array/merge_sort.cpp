class Solution {
public:
    
    void merge_array(vector<int>& nums, int si, int ei, int mid) {
        
        int i = si, j = mid + 1, k = 0;
        vector<int> output(ei - si + 1);
        
        while(i <= mid && j <= ei) {
            if(nums[i] <= nums[j]) 
                output[k++] = nums[i++];
            else 
                output[k++] = nums[j++];
        }
    
        while(i <= mid) {
            output[k++] = nums[i++];
        }
    
        while(j <= ei) {
            output[k++] = nums[j++];
        }
        
        i = si, j = 0;
        for(int i = si; i <= ei; i++) {
            nums[i] = output[j++];
        }
    }
    
    void merge_sort(vector<int>& nums, int si, int ei) {
        if(si < ei) {
            int mid = (si + ei) / 2;
            merge_sort(nums, si, mid);
            merge_sort(nums, mid + 1, ei);
            
            merge_array(nums, si, ei, mid);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};
