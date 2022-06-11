class Solution {
public:
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> graph(n);
            for(int i = 0; i < edges.size(); i++){
                graph[edges[i][0]].push_back(edges[i][1]);
                graph[edges[i][1]].push_back(edges[i][0]);
            }
        
        vector<bool> visited(n, false);
        
        visited[source] = true;
        queue<int> q;
        q.push(source);
        
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            
            if(v == destination)
                return true;
            
            for(auto i : graph[v]) {
                if(!visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        
        return false;
    }
};