class Solution {
public:
    
    bool check(vector<vector<int>>& mat, int i, int j) {
        if(i < 0 || j < 0 || i >= mat.size() || j >= mat[i].size() || mat[i][j] >= 0)
            return false;
        return true;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        queue<pair<int, int>> cells;
        
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[i].size(); j++) {
                if(mat[i][j] == 0)
                    cells.push({i, j});
                else
                    mat[i][j] = -1;
            }
        }
        
        while(!cells.empty()) {
            int i = cells.front().first;
            int j = cells.front().second;
            cells.pop();
            
            int arr[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
            
            for(int k = 0; k < 4; k++) {
                int x = i + arr[k][0];
                int y = j + arr[k][1];
                if(check(mat, x, y)) {
                    mat[x][y] = mat[i][j] + 1;
                    cells.push({x, y});
                }
            }
        }
        
        return mat;
        
    }
};