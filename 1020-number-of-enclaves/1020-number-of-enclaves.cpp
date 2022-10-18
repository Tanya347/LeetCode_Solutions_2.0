class Solution {
public:
    
    
    void countEnclaves(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] == 0)
            return;
       
        grid[i][j] = 0;
        
        countEnclaves(grid, i + 1, j);
        countEnclaves(grid, i - 1, j);
        countEnclaves(grid, i, j + 1);
        countEnclaves(grid, i, j - 1);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if((i == 0 || j == 0 || i == grid.size() - 1 || j == grid[i].size() - 1) && grid[i][j] == 1)
                countEnclaves(grid, i, j);
            }    
        }
        
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1)
                    count++;
            }    
        }
        
        return count;
        
    }
};