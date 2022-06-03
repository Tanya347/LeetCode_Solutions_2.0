class NumMatrix {
    private:
    
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        sum = vector<vector<int>>(m, vector<int>(n + 1)); 
        //accumulate sum in rows
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i][j + 1] = sum[i][j] + matrix[i][j];
            }
        }
    }
    int sumRegion(int r1, int c1, int r2, int c2) {
		// subtract the sum of prior columns from the onces required
      
        int s = 0;
        for(int r = r1; r <= r2; r++) {
            s += sum[r][c2 + 1] - sum[r][c1];
        }
        return s;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */