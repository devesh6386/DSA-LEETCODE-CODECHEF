class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<bool>&vis){
        vis[node]=true;
        for(int neigh:adj[node]){
            if(!vis[neigh]){
                dfs(neigh,adj,vis);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        for(auto &e:invocations){
            adj[e[0]].push_back(e[1]);
        }
        vector<bool>vis(n,false);
        dfs(k,adj,vis);
        for(auto &e:invocations){
            if(!vis[e[0]] && vis[e[1]]){
                vector<int>ans;
                for(int i=0;i<n;i++){
                    ans.push_back(i);
                }
                return ans;
                
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

    