
class WordFilter {
    unordered_map<string, int> words;
public:
    WordFilter(vector<string>& words) {
        for(int i = 0; i <words.size(); i++) {
            string word = words[i];
            int n = word.size();
            
            for(int j = 1; j <= n; j++) {
                string key = word.substr(0, j);
                key += '.';
                
                for(int k = 1; k <= n; k++) {
                    key.resize(j + 1);
                    key.append(word, n - k, k);
                    this -> words[key] = i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        prefix += '.';
        prefix += suffix;
        return words.count(prefix) ? words[prefix] : -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */