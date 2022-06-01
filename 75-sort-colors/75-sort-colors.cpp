class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }
        
        int index = 0;
        for(int i = 0; i < nums.size(); ) {
            int j = i;
            int c = count[index];
            while(c > 0) {
                nums[j++] = index;
                c--;
            }
            i = i + count[index];
            index++;
        }
    }
};