class Solution {
public:
    vector<int>rank,parent;
    int findparent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findparent(parent[node]);
    }
    void UnionbyRank(int u,int v){
        int pu=findparent(u);
        int pv=findparent(v);
        if(pu==pv)return;
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
    

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        rank.resize(n+1,0);
        vector<bool>ans;
        parent.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<=maxDiff){
                UnionbyRank(i,i-1);
            }
        }
        for(auto &q:queries){
            ans.push_back(findparent(q[0])==findparent(q[1]));
        }
        return ans;
    }
};

    