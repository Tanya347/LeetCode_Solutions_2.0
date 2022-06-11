class Solution {
public:
        
    void dfs(vector<vector<int>>& graph,int si, vector<bool>& visited){
            
        visited[si] = true;
        
        for(auto child : graph[si]){
            if(visited[child] == false){
                dfs(graph, child, visited);
            }
        }
            
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
          vector<vector<int>> graph(n);
            for(int i = 0; i < edges.size(); i++){
                    graph[edges[i][0]].push_back(edges[i][1]);
                    graph[edges[i][1]].push_back(edges[i][0]);
            }
        
            vector<bool> visited(n, false);
        
            dfs(graph, source, visited);
        
            return visited[destination];
    }
};