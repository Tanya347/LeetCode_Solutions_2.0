class Solution {
public:
    
    int partition(vector<int>& nums, int si, int ei) {
        
        int count = 0;
        for(int i = si + 1; i <= ei; i++) {
            if(nums[i] <= nums[si])
                count++;
        }
    
        int pivot = si + count;
    
        int temp = nums[si];
        nums[si] = nums[pivot];
        nums[pivot] = temp;
    
        while(si < pivot && ei > pivot) {
            if(nums[si] > nums[pivot]) {
                if(nums[ei] <= nums[pivot]) {
                    int temp = nums[ei];
                    nums[ei] = nums[si];
                    nums[si] = temp;
                
                    si++, ei--;
                } else ei--;
            } else si++;
        }
    
        return pivot;
    }
    
    void quick_sort(vector<int>& nums, int si, int ei) {
        if(si < ei) {
            swap(nums[si + rand() % (ei - si + 1)], nums[si]);
            int p = partition(nums, si, ei);
            quick_sort(nums, si, p - 1);
            quick_sort(nums, p + 1, ei);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};