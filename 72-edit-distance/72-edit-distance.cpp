class Solution {
public:
    int minDistance(string s1, string s2) {
        
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> output(m + 1, vector<int>(n + 1));
    
        for(int i = 0; i <= m; i++) {

            for(int j = 0; j <= n; j++) {
                
                if(i == 0)
                    output[i][j] = j;
                
                else if(j == 0)
                    output[i][j] = i;
                
                else {
                    if(s1[m - i] == s2[n - j])
                        output[i][j] = output[i - 1][j - 1];
                    
                    else
                    output[i][j] = 1 + min(min(output[i-1][j], output[i][j-1]), output[i-1][j-1]);
                }
            }
        }
        
        return output[m][n];
    }
};