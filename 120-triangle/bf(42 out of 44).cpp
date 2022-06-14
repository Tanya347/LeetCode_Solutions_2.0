class Solution {
public:
    int total_helper(vector<vector<int>>& triangle, int r, int c) {
        //base case
        if(r == triangle.size() - 1)
            return triangle[r][c];
        
        if(c >= triangle[r].size())
            return INT_MAX;
        
        int minPath = INT_MAX;
        
        int x = total_helper(triangle, r + 1, c);
        int y = total_helper(triangle, r + 1, c + 1);
            
        minPath = triangle[r][c] + min(x, y);
        
        
        return minPath;
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        return total_helper(triangle, 0, 0);
    }
    
};
