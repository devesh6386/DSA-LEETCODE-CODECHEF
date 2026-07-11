class Solution {
public:
    vector<vector<int>>adj;
    vector<int>vis;
    int node=0;
    int degreesum=0;
    void dfs(int u){
        vis[u]=1;
        node+=1;
        degreesum+=adj[u].size();//component
        for(int v:adj[u]){
            if(!vis[v]){
                dfs(v);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        vis.assign(n,0);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);//undirected
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                 node=0;
                 degreesum=0;
                 dfs(i);
                 int edges=0;
                 edges=degreesum/2;
                 if(edges==(node*(node-1))/2)res++;
            }
        }
        return res;
    }
};
