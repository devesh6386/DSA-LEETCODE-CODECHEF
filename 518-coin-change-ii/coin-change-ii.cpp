class Solution {
public:
    int n;
    int solve(vector<vector<int>>&dp,vector<int>&coins,int i,int amount){
        n=coins.size();
        if(amount==0)return 1;
        if(i==n){
            return 0;
        }
        
        if(dp[i][amount]!=-1)return dp[i][amount];
        int take=0;
        int skip=0;
        if(coins[i]<=amount){
            take=solve(dp,coins,i,amount-coins[i]);
             
        }
        skip=solve(dp,coins,i+1,amount);
        
        return dp[i][amount]=take+skip;
    }

    int change(int amount, vector<int>& coins) {
        n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return solve(dp,coins,0,amount);
        
    }
};