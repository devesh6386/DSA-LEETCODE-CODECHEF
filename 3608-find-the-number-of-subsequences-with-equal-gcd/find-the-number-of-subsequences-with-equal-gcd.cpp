class Solution {
public:
    int mod=1e9+7;
    int solve(int i,int g1,int g2,vector<int>&nums,vector<vector<vector<int>>>&dp){
        int n=nums.size();
        if(i==n){
            return (g1==g2 && g1!=0);
        }//base case
        if(dp[i][g1][g2]!=-1)return dp[i][g1][g2];
        long long ans=solve(i+1,g1,g2,nums,dp);
        int newgcd1=(g1==0)?nums[i]:gcd(g1,nums[i]);
        ans=(ans+solve(i+1,newgcd1,g2,nums,dp))%mod;
        int newgcd2=(g2==0)?nums[i]:gcd(g2,nums[i]);
        ans=(ans+solve(i+1,g1,newgcd2,nums,dp))%mod;
        return dp[i][g1][g2]=ans;
    }
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
        int maxval=0;
        for(int x:nums){
            maxval=max(maxval,x);
        }
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(maxval+1,vector<int>(maxval+1,-1)));
        
        return solve(0,0,0,nums,dp);
    }
};