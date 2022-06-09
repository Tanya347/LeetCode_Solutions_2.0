class Solution {
public:
    int lcs_helper(string text1, string text2, vector<vector<int>>& dp, int i, int j) {
        if(text1.length() == 0 || text2.length() == 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(text1[0] == text2[0])
            dp[i][j] = 1 + lcs_helper(text1.substr(1), text2.substr(1), dp, i + 1, j + 1);
        
        else {
            int a = lcs_helper(text1.substr(1), text2, dp, i + 1, j);
            int b = lcs_helper(text1, text2.substr(1), dp, i, j + 1);
            
            dp[i][j] = max(a, b);
        }
        
        return dp[i][j];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        return lcs_helper(text1, text2, dp, 0, 0);
    }
};
