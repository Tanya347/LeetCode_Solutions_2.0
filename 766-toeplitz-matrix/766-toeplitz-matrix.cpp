class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0; i < m - 1; i++) {
            for(int j = i, k = 0; j < m - 1 && k < n - 1; j++, k++) {
                if(matrix[j][k] != matrix[j + 1][k + 1]) {
                    return false;
                }
            }
        }
        
        for(int i = 1; i < n - 1; i++) {
            for(int j = 0, k = i; j < m - 1 && k < n - 1; j++, k++) {
                if(matrix[j][k] != matrix[j + 1][k + 1]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};