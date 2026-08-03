class Solution {
public:
    int solve(int i,int n,vector<int>&stoneValue,vector<int>&dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int curr=0;
        int ans=INT_MIN;
        for(int k=0;k<3;k++){
            if(i+k<n){
                curr+=stoneValue[i+k];
                int margin=curr-solve(i+k+1,n,stoneValue,dp);
                ans=max(ans,margin);
            }
        }
        return dp[i]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>dp(n+1,-1);
        int alic=solve(0,n,stoneValue,dp);
        if(alic>0)return "Alice";
        else if(alic==0)return "Tie";
        return "Bob";
    }

};    
        