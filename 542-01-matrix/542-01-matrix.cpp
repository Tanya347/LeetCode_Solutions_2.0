class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX - 1));
        
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(mat[r][c] == 0) {
                    distance[r][c] = 0;
                    continue;
                }
                
                if(r > 0)
                    distance[r][c] = min(distance[r][c], distance[r - 1][c] + 1);
                if(c > 0)
                    distance[r][c] = min(distance[r][c], distance[r][c - 1] + 1);
            }
        }
        
        for(int r = m - 1; r >= 0; r--) {
            for(int c = n - 1; c >= 0; c--) {
                if(r != m - 1)
                    distance[r][c] = min(distance[r][c], distance[r + 1][c] + 1);
                if(c != n - 1)
                    distance[r][c] = min(distance[r][c], distance[r][c + 1] + 1);
            }
        }
        
        return distance;
    }
};