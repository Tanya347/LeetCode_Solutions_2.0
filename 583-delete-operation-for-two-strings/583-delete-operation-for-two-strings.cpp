class Solution {
public:
//     int minDistance(string word1, string word2, int i, int j, vector<vector<int>>& dp) {
//         if(word1.size() == 0 || word2.size() == 0)
//             return max(word1.size(), word2.size());
        
//         if(dp[i][j] != -1)
//             return dp[i][j];
        
//         if(word1[0] == word2[0])
//             return minDistance(word1.substr(1), word2.substr(1));
        
//         int x = minDistance(word1.substr(1), word2, i + 1, j, dp);
//         int y = minDistance(word1, word2.substr(1), i, j + 1, dp);
        
//         dp[i][j] = 1 + min(x, y);
//         return dp[i][j];
//     }
    
//     int minDistance(string word1, string word2) {
//         vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
//         return minDistance(word1, word2, 0, 0, dp);
//     }
    
    int minDistance(string w1, string w2) {
        
        int n = w1.size();
        int m = w2.size();
        int dp[n+1][m+1];
      
        for(int i = 0; i<=n; i++) {
            dp[i][0] = i;
        }
        
        for(int i = 0; i<=m; i++) {
            dp[0][i] = i;
        }
        
        for(int i = 1; i<=n; i++) {
          
            for(int j = 1; j<=m; j++) {
              
                if(w1[i-1] == w2[j-1]) {
                  
                    dp[i][j] = dp[i-1][j-1];
                }
              
                else {
                  
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }
};