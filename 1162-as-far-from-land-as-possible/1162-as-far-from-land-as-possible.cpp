class Solution {
public:
    
    int maxDistance(vector<vector<int>>& grid) {
        
        queue<pair<int, int>> cell;
        
        int m = grid.size();
        int n = grid[0].size();
        
        // push all the neighbouring cells of land and mark those cells as 2 
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(grid[i][j] == 1) {
                    
                    int arr[4][2] = {{-1 , 0}, {1, 0}, {0, 1}, {0, -1}};
                    
                    for(int k = 0; k < 4; k++) {
                        
                        int x = i + arr[k][0];
                        int y = j + arr[k][1];
                        
                        if(x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 0) {
                            cell.push({x, y});
                            grid[x][y] = 2;
                        }
                    }
                }
            }
        }
        
        int maxdis = 0;
        
        // now apply bfs on all cells beginning from those that are 2 and make the 
        // neighbouring cells +1 and keep updating maximum distance
        while(!cell.empty()) {
            
            int i = cell.front().first;
            int j = cell.front().second;
            cell.pop();
                        
            maxdis = max(maxdis, grid[i][j]);
            
            int arr[4][2] = {{-1 , 0}, {1, 0}, {0, 1}, {0, -1}};
            
            for(int k = 0; k < 4; k++) {
                        
                int x = i + arr[k][0];
                int y = j + arr[k][1];
                        
                if(x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 0) {
                    cell.push({x, y});
                    grid[x][y] = grid[i][j] + 1;
                }
            }
        }
        
        return maxdis? maxdis - 1 : -1;
    }
};