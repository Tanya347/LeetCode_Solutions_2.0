class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> ans(n, vector<int>(m, 0));
        
        if(m == n) {
            
            for(int i = 0; i < m - 1; i++) {
                for(int j = i + 1; j < n; j++) {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }
            
            return matrix;
            
        } else  {
            
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    ans[j][i] = matrix[i][j];
                }
            }
            
            return ans;
        }
    }
};