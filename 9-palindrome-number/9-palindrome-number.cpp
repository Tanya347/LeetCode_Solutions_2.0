class Solution {
public:
    bool isPalindrome(int x) {
        
        string num;
        if(x < 0)
            return false;
        
        while(x > 0) {
            int n = x % 10;
            x = x / 10;
            num += n + '0';
        }
        
        for(int i = 0; i < num.size()/2; i++) {
            if(num[i] != num[num.size() - i - 1])
                return false;
        }
        
        return true;
    }
};