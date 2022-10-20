class Solution {
public:
    
    string symbol[15] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "III", "II", "I"};
    
    int values[15] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 3, 2, 1};
    
    
    string intToRoman(int num) {
        string ans = "";
        int i = 0;
        while(i < 15) {
            if(num >= values[i]) {
                ans.append(symbol[i]);
                num = num - values[i];  
            } 
            else 
                i++;
        }
        
        return ans;
    }
};