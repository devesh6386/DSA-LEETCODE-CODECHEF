class Solution {
public:
    int m=1e9+7;
    int n;
    int cols;
    unordered_map<int,vector<int>>adj;
    vector<vector<int>>ancestortable;
    vector<int>depth;
    void dfs(int root,int parent){
        ancestortable[root][0]=parent;
        for(int &ngbr:adj[root]){
            if(ngbr==parent)continue;
            depth[ngbr]=depth[root]+1;
            dfs(ngbr,root);
        }
    }
    int findlca(int u,int v){
        if(depth[u]<depth[v])swap(u,v);
        int k= depth[u]-depth[v];
        for(int j=0;j<cols;j++){
            if(k&(1<<j)){
                u=ancestortable[u][j];
            }
        }
        if(u==v)return v;//samenpath
        for(int j=cols-1;j>=0;j--){
            if(ancestortable[u][j]==-1){
                continue;
            }
            if(ancestortable[u][j]!=ancestortable[v][j]){
                u=ancestortable[u][j];
                v=ancestortable[v][j];
            }
        }
        return ancestortable[u][0];
    }

    void buildancestortable(){
        for(int j=1;j<cols;j++){
            for(int node=0;node<n;node++){
                if(ancestortable[node][j-1]!=-1){
                    ancestortable[node][j]=ancestortable[ancestortable[node][j-1]][j-1];

                }
            }
        }
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n=edges.size()+1;
        cols=log2(n)+1;
        for(auto &edge:edges){
            int u=edge[0]-1;
            int v=edge[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        depth.resize(n,0);
        ancestortable.resize(n,vector<int>(cols,-1));
        dfs(0,-1);
        buildancestortable();
        //precompute power of 2
        vector<int>pow2(n+1);
        pow2[0]=1;
        for(int i=1;i<=n;i++){
            pow2[i]=(2LL*pow2[i-1])%m;
        }
        vector<int>result;
        for(auto &query:queries){
            int u=query[0]-1;
            int v=query[1]-1;
            int d=depth[u]+depth[v]-2*depth[findlca(u,v)];
            if(d==0){
                result.push_back(0);
            }
            else{
               result.push_back(pow2[d - 1]);
            }
        }
        return result;
    }
};


        