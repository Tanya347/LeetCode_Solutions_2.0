class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int m = nums1.size(), n = nums2.size();
        
        vector<int> result;
        
        int i = 0, j = 0;
        
        while(i < m && j < n) {
            if(nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
                while(i + 1 < m && nums1[i] == nums1[i + 1]) i++;
                i++;
                while(j + 1 < n && nums2[j] == nums2[j + 1]) j++;
                j++;
                
            } else if(nums1[i] < nums2[j]) {
                
                while(i + 1 < m && nums1[i] == nums1[i + 1]) i++;
                i++;
                
            } else {
                
                while(j + 1 < n && nums2[j] == nums2[j + 1]) j++;
                j++;
                
            }
        }
        
        return result;
    }
};