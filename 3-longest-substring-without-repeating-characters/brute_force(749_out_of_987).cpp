class Solution {
public:
    
    bool unique(string s, int i, int j) {
        unordered_map<char, int> freq;
        
        for(int k = i; k <= j; k++) {
            if(freq[s[k] - '0'] == 1)
                return false;
            else
                freq[s[k] - '0']++;
        }
        
        return true;
    }
    
    int lengthOfLongestSubstring(string s) {
        
        if(s.length() == 0)
            return 0;
        
        int max_count = 0;
        
        for(int i = 0; i < s.length(); i++) {
            for(int j = i; j < s.length(); j++) {
                if(unique(s, i, j)) {
                    max_count = max(max_count, j - i + 1);
                }
            }
        }
        
        return max_count;
    }
};
