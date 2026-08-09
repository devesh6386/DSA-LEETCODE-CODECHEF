class Solution {
public:
    int solve(int p,int i,int M,vector<int>&piles,vector<vector<vector<int>>>&dp){
        int n=piles.size();
        if(i>=n){
            return 0;
        
        }
        if(dp[p][i][M]!=-1)return dp[p][i][M];
        int stones=0;
        int res=(p==1)?-1:INT_MAX;
        for(int x=1;x<=min(2*M,n-i);x++){
            stones+=piles[i+x-1];
            if(p==1){
                res=max(res,stones+solve(0,i+x,max(M,x),piles,dp));
            }
            else{
                res=min(res,solve(1,i+x,max(M,x),piles,dp));
            }
        }
        return dp[p][i][M]=res;
    }
    
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(n,vector<int>(n+1,-1)));
        return solve(1,0,1,piles,dp);
    }
};
        
