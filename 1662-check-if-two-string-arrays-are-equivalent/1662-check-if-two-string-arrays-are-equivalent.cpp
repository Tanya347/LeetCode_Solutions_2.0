class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        // iterators for array and strings for both words
        int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
        
        while(true) {
            char c1 = word1[i1][j1];
            char c2 = word2[i2][j2];
            if(c1 != c2) return false;
            
            j1++; 
            j2++;
            
            // if string is over in word 1
            if(j1 == word1[i1].length()) {
                i1++;
                j1 = 0;
            }
            
            // if string is over in word 2
            if(j2 == word2[i2].length()) {
                i2++;
                j2 = 0;
            }
            
            // if both arrays are exhausted
            if(i1 == word1.size() && i2 == word2.size())
                break;
            
            // if anyone of the arrays is exhausted but the other is not
            if(i1 == word1.size() || i2 == word2.size())
                return false;
        }
        
        // if we reach out of the loop that means both are equivalent
        return true;
    }
};