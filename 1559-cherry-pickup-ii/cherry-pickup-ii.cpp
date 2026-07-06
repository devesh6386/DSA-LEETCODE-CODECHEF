class Solution {
public:
    int m,n;
    vector<vector<vector<int>>>dp;
    int solve(vector<vector<int>>&grid,int i,int c1,int c2){
        if(i>=m)return 0;
        if(dp[i][c1][c2]!=-1)return dp[i][c1][c2];
        m=grid.size();
        n=grid[0].size();
        int res=0;
        int cherry=grid[i][c1];
        if(c1!=c2){
            cherry+=grid[i][c2];//iniitial
        }
        //traverse as per given
        for(int val1=-1;val1<=1;val1++){
            for(int val2=-1;val2<=1;val2++){
                int newr=i+1;
                int newc1=c1+val1;
                int newc2=c2+val2;
                if(newr>=0 && newr<m && newc1>=0 && newc1<n && newc2>=0 && newc2<n){
                    res=max(res,solve(grid,newr,newc1,newc2));
                }
            }
        }
        return dp[i][c1][c2]=res+cherry;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        dp.assign(m,vector<vector<int>>(n,vector<int>(n,-1)));
        // memset(dp,-1,sizeof(dp));
        return solve(grid,0,0,n-1);
    }
};
        
        
