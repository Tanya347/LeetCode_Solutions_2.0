class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int mins = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> cell;
        
        vector<vector<int>> level(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    cell.push({i, j});
                }
            }
        }
        
        vector<bool> visited(15, false);
            
        while(!cell.empty()) {
            
            int i = cell.front().first;
            int j = cell.front().second;
            cell.pop();
            
            if(!visited[level[i][j]]) {
                if(level[i][j])
                    mins++;
                visited[level[i][j]] = true;

            }
            
            int arr[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
            
            for(int k = 0; k < 4; k++) {
                int x = i + arr[k][0];
                int y = j + arr[k][1];
                
                if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 0)
                    continue;
                
                if(grid[x][y] == 1) {
                    grid[x][y] = 2;
                    cell.push({x, y});
                    level[x][y] = level[i][j] + 1;
                }
            }
            
            
        }
            
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) 
                    return -1;
            }
        }
        
        return mins;
    }
};