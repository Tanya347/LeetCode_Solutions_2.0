class Solution {
    
    bool check(unordered_map<char, int> &mp, unordered_map<char, int> &m) {
        
        if(m.size() < mp.size()) return false;
        for(auto i : m) {
            if(i.second < mp[i.first]) return false;
        }
        return true;
    }
    
public:
    string minWindow(string s, string t) {
        
        unordered_map<char, int> mp, m;
        for(char c : t) mp[c]++;

        int i = 0, d = INT_MAX;
        string ans;
        for(int j=0; j<s.size(); j++) {
            if(mp.find(s[j]) != mp.end()) m[s[j]]++;
            while(check(mp, m)) {
                if(j - i + 1 < d) d = j - i + 1, ans = s.substr(i, j - i + 1);
                if(m.find(s[i]) != m.end()) m[s[i]]--;
                i++;
            }
        }
        return ans;
    }
};