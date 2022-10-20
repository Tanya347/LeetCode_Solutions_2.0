class Solution {
public:
    
    string symbol[15] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "III", "II", "I"};
    
    int values[15] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 3, 2, 1};
    
    int romanToInt(string s) {
        
        int ans = 0;
        int i = 0, j = 0;
        
        while(i < s.length()) {
            if(s.substr(i, 1) == symbol[j]) {
                ans += values[j];
                i++;
            } else if(s.substr(i, 2) == symbol[j]) {
                ans += values[j];
                i = i + 2;
            } else {
                j++;
            }
        }
        
        return ans;
    }
};