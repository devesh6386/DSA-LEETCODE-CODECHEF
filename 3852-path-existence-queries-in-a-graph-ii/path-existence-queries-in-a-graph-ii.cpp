class Solution {
public:
    int rows;
    int cols;
    vector<vector<int>>ancestor;
    int customupperbound(vector<pair<int,int>>&arr,int target){
        int n=arr.size();
        int l=0;
        int r=n-1;
        int res=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid].first<=target){
                res=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return res;
    }
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>>arr(n);
        for(int i=0;i<n;i++){
            arr[i]={nums[i],i};
        }
        sort(arr.begin(),arr.end());
        vector<int>nodetoidx(n);
        for(int i=0;i<n;i++){
            int val=arr[i].first;
            int node=arr[i].second;
            nodetoidx[node]=i;//isindexz pr hai
        }
        //binary lifting
        rows=n;
        cols=log2(n)+1;
        ancestor.resize(rows,vector<int>(cols,0));
        //fill 0h=th row
        for(int node=0;node<n;node++){
            int farthestidx=customupperbound(arr,arr[node].first+maxDiff);
            ancestor[node][0]=farthestidx;
        }
        //fill remailcol
        for(int j=1;j<cols;j++){
            for(int node=0;node<n;node++){
                ancestor[node][j]=ancestor[ancestor[node][j-1]][j-1];
            }
        }
        vector<int>ans;
        for(auto &q:queries){
            int u=q[0];
            int v=q[1];
            int a=nodetoidx[u];
            int b=nodetoidx[v];
            if(a==b){
                ans.push_back(0);
                continue;
            }
            if(a>b)swap(a,b);
            int curr=a;
            int jumps=0;
            for(int j=cols-1;j>=0;j--){
                if(ancestor[curr][j]<b){
                    curr=ancestor[curr][j];
                    jumps+=(1<<j);
                }
            }
            if(ancestor[curr][0]>=b){
                ans.push_back(jumps+1);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};