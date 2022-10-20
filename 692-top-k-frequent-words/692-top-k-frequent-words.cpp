class Solution {
public:
    
    static bool cmp(pair<string, int>& a, pair<string, int>& b) {
        if(a.second == b.second)           // if frequency are equal put lexicographically greater element on top
            {
                return a.first < b.first;
            }
            else                            // if frequency are not equal put the elements on top which has less frequency
            {
                return a.second > b.second;
            }
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        // finding the frequency of each word
        unordered_map<string, int> freq;
        for(int i = 0; i < words.size(); i++) {
            freq[words[i]]++;
        }
        
        // sorting according to the frequency
        vector<pair<string, int>> f;
        
        for(auto &it : freq) {
            f.push_back(it);   
        }
        
        sort(f.begin(), f.end(), cmp);
        
        // answer
        vector<string> ans;
        
        for(int i = 0; i < k; i++) {
            ans.push_back(f[i].first);
        }
        
        return ans;
    }
};