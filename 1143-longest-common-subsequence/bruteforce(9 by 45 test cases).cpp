class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.length() == 0 || text2.length() == 0)
            return 0;
        
        if(text1[0] == text2[0])
            return 1 + longestCommonSubsequence(text1.substr(1), text2.substr(1));
        
        else {
            int a = longestCommonSubsequence(text1.substr(1), text2);
            int b = longestCommonSubsequence(text1, text2.substr(1));
            int c = longestCommonSubsequence(text1.substr(1), text2.substr(1));
            
            return max(a, max(b, c));
        }
        
    }
};
