class Solution {
public:
//condtion
//1.max value throw
//2.
    
    
    int solve(int l,int r,vector<int>&stoneValue,vector<int>&pre,vector<vector<int>>&dp){
        if(l==r)return 0;
        int n=stoneValue.size();
        if(dp[l][r]!=-1)return dp[l][r];
        int ans=0;
        for(int k=l;k<r;k++){
            int left=pre[k+1]-pre[l];
            int right=pre[r+1]-pre[k+1];
            if(left<right){
                ans=max(ans,left+solve(l,k,stoneValue,pre,dp));
            }
            else if(right<left){
                ans=max(ans,right+solve(k+1,r,stoneValue,pre,dp));
            }
            else{
                ans=max(ans,left+max(solve(l,k,stoneValue,pre,dp),solve(k+1,r,stoneValue,pre,dp)));
            }
        }
        return dp[l][r]=ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        vector<int>pre(n+1);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+stoneValue[i];
        }
        
         return solve(0,n-1,stoneValue,pre,dp);
    }
};
        
        
