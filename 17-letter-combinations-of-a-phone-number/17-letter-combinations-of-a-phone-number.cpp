class Solution {
public:
    
    vector<string> codes = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> combinations_helper(string digits, int n) {
        
        if(n == 0) {
            vector<string> ans;
            ans.push_back("");
            return ans;
        }
        
        vector<string> res = combinations_helper(digits.substr(1), n - 1);
        vector<string> ans;
        
        int c = digits[0] - '0';
        
        for(int i = 0; i < codes[c].length(); i++) {
            
            for(string ch : res) {
                string temp = codes[c].at(i) + ch;
                ans.push_back(temp);
            }
            
        }
        
        return ans;
    }
    
    vector<string> letterCombinations(string digits) {
        
        int n = digits.length();
        if(n == 0)
            return {};
        return combinations_helper(digits, n);
    }
};