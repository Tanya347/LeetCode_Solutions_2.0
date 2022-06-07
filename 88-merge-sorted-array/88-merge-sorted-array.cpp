class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = 0, j = 0;
        
        if(n == 0)
            return;
        
        while(i < m && j < n) {
            if(nums2[j] <= nums1[i]) {
                auto it = nums1.begin() + i;
                nums1.insert(it, nums2[j]);
                nums1.pop_back();
                i++;
                m++;
                j++;
            }
            else
                i++;
        }
        
        int diff = n - j;
        while(diff > 0) {
            nums1.pop_back();
            diff--;
        }
        
        while(j < n) {
            nums1.push_back(nums2[j++]);
        }
    }
};