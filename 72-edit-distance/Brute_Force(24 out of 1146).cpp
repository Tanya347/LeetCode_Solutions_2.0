class Solution {
public:
    int minDistance(string s1, string s2) {
        
        if(s1.size() == 0 || s2.size() == 0) {
            return max(s1.size(), s2.size());
        }
        
        if (s1[0] == s2[0]) {
            return minDistance(s1.substr(1), s2.substr(1)); 
        }
        
        return 1 + min(minDistance(s1.substr(1), s2), min(minDistance(s1, s2.substr(1)), minDistance(s1.substr(1), s2.substr(1))));
    }
};
