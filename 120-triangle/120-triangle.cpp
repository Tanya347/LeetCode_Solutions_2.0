class Solution {
public:
    int total_helper(vector<vector<int>>& triangle, int r, int c, vector<vector<int>>& dp) {
        //base case
        if(r == triangle.size() - 1)
            return triangle[r][c];
        
        if(c >= triangle[r].size())
            return INT_MAX;
        
        if(dp[r][c] != -1)
            return dp[r][c];
        
        int x = total_helper(triangle, r + 1, c, dp);
        int y = total_helper(triangle, r + 1, c + 1, dp);
            
        dp[r][c] = triangle[r][c] + min(x, y);
        return dp[r][c];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
        return total_helper(triangle, 0, 0, dp);
    }
    
};