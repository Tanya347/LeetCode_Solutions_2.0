class Solution {
public:
        
    void dfs(vector<vector<int>>&adj,int node,vector<bool>&visit){
            visit[node]=true;
            for(auto child : adj[node]){
                    if(visit[child]==false){
                            dfs(adj,child,visit);
                    }
            }
            
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
          vector<vector<int>>adj(n);
            for(int i=0;i<edges.size();i++){
                    adj[edges[i][0]].push_back(edges[i][1]);
                    adj[edges[i][1]].push_back(edges[i][0]);
            }
            vector<bool>visit(n,false);
            dfs(adj,source,visit);
            return visit[destination];
    }
};