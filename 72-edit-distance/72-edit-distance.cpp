class Solution {
public:
    int minDistance(string s1, string s2, vector<vector<int>>& dp, int i, int j) {
        
        if(s1.size() == 0 || s2.size() == 0) {
            return max(s1.size(), s2.size());
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if (s1[0] == s2[0]) 
            dp[i][j] = minDistance(s1.substr(1), s2.substr(1), dp, i + 1, j + 1); 
        
        else {
            int x = 1 + minDistance(s1.substr(1), s2, dp, i + 1, j);
            int y = 1 + minDistance(s1,s2.substr(1), dp, i, j + 1);
            int z = 1 + minDistance(s1.substr(1), s2.substr(1), dp, i + 1, j + 1);
        
            dp[i][j] = min(x , min(y , z));
        }
        
        return dp[i][j];
    }
    
    int minDistance(string s1, string s2) {
        
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        
        return minDistance(s1, s2, dp, 0, 0);
    }
};