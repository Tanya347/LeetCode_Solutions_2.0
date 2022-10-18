class Solution {
public:
    
    void colorBorderHelper(vector<vector<int>>& grid, int row, int col, int c) {
        
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] < 0 || grid[row][col] != c)
            return;
        
        grid[row][col] = -grid[row][col];
        
        colorBorderHelper(grid, row + 1, col, c);
        colorBorderHelper(grid, row, col + 1, c);
        colorBorderHelper(grid, row - 1, col, c);
        colorBorderHelper(grid, row, col - 1, c);
        
        if(row > 0 && col > 0 && row < grid.size() - 1 && col < grid[row].size() - 1 && c == abs(grid[row - 1][col]) && c == abs(grid[row + 1][col]) && c == abs(grid[row][col - 1]) && c == abs(grid[row][col + 1]))
            grid[row][col] = c;
            
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        
        colorBorderHelper(grid, row, col, grid[row][col]);
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] < 0)
                    grid[i][j] = color;
            }
        }
        
        return grid;
    }
    
 
};