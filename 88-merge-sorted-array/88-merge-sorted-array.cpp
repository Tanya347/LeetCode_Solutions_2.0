class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if(m == 0) {
            nums1 = nums2;
            return;
        } else if(n == 0) {
            return;
        }
        
        
        int i = 0, j = 0;
        
        while(i < m && j < n) {
            if(nums1[i] >= nums2[j]) {
                for(int k = nums1.size() - 1; k > i; k--) {
                        nums1[k] = nums1[k - 1];
                }
                nums1[i] = nums2[j];
                i++;
                j++;
                m++;
            } 
            else {
                i++;
            }

                
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