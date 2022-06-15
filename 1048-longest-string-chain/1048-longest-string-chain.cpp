class Solution {
public:
    
    static bool comparator(string s1, string s2) {
        return s1.length() < s2.length();
    }
    
    int longestStrChain(vector<string>& words) {
        
        int count = 1;
        sort(words.begin(), words.end(), comparator);
        
        unordered_map<string, int> dp;
        
        for(int i = 0; i < words.size(); i++) {
            int maxChain = 0;
            
            for(int j = 0; j < words[i].length(); j++) {
                string predecessor = words[i].substr(0, j) + words[i].substr(j + 1);
                if(dp.find(predecessor) != dp.end()) {
                    maxChain = max(dp[predecessor], maxChain);
                }
            }
            
            dp[words[i]] = 1 + maxChain;
            count = max(count, dp[words[i]]);
        }
        
        return count;
    }
    
    
};