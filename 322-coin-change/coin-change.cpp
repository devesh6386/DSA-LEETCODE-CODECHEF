class Solution {
public:
    int n;
    int solve(vector<int>&dp,vector<int>&coins,int amount){
        n=coins.size();
        if(amount==0)return 0;
        if(amount<0)return 1e9;
        if(dp[amount]!=-1)return dp[amount];
        int ans=INT_MAX;
        for(int coin:coins){
            ans=min(ans,1+solve(dp,coins,amount-coin));
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        n=coins.size();
        vector<int>dp(amount+1,-1);
        int ans=solve(dp,coins,amount);
        return (ans>=1e9)?-1:ans;
        //return solve(dp,coins,amount);
    }
};

        
    