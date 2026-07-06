class Solution {
public:
    int n;//do simultaneously 
    vector<vector<vector<int>>>dp;
    int solve(vector<vector<int>>&grid,int i,int c1,int r2){
        n=grid.size();
        int c2=i+c1-r2;//r1+C1==r2+C2
        if(i>=n || c1>=n ||c2>=n || r2>=n)return -1e9;
        if(grid[i][c1]==-1 || grid[r2][c2]==-1)return -1e9;
        if(i==n-1 && c1==n-1)return grid[i][c1];
        if(dp[i][c1][r2]!=-1)return dp[i][c1][r2];
        int cherry=grid[i][c1];
        if(c1!=c2 || i!=r2){
            cherry+=grid[r2][c2];
        }
        int ans=-1e9;
         ans=max({ans,solve(grid,i+1,c1,r2+1),solve(grid,i+1,c1,r2),solve(grid,i,c1+1,r2),solve(grid,i,c1+1,r2+1)});
        return dp[i][c1][r2]=ans+cherry;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        dp.assign(n+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        return max(0,solve(grid,0,0,0));
    }
};

    