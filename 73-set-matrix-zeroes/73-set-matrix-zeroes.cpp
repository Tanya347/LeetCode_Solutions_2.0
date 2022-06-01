class Solution {
public:
    void make_zeroes(vector<vector<int>>& matrix, int i, int j, int m, int n) {
        for(int x = i; x >= 0; x--) {
            matrix[x][j] = 0;
        }
        
        for(int x = i; x < m; x++) {
            matrix[x][j] = 0;
        }
        
        for(int x = j; x >= 0; x--) {
            matrix[i][x] = 0;
        }
        
        for(int x = j; x < n; x++) {
            matrix[i][x] = 0;
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> indices;
        
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] == 0)
                    indices.push_back({i, j});
            }
        }
        
        for(int i = 0; i < indices.size(); i++) {
            make_zeroes(matrix, indices[i][0], indices[i][1], m, n);
        }
//         vector<vector<bool>> visited(m, vector<bool>(n, false));
        
//         for(int i = 0; i < matrix.size(); i++) {
//             for(int j = 0; j < matrix[i].size(); j++) {
//                 if(matrix[i][j] == 0 && !visited[i][j]) {
//                     visited[i][j] = true;
//                     make_zeroes(matrix, visited, i, j, m, n);
//                 }
//             }
//         }
    }
};