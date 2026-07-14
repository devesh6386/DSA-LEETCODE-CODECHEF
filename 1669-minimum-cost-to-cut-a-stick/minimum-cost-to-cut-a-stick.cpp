class Solution {
public:
    int solve(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
        int t=cuts.size();
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini=INT_MAX;//min cost for cuts
        for(int k=i;k<=j;k++){
            int steps=cuts[j+1]-cuts[i-1]+solve(i,k-1,cuts,dp)+solve(k+1,j,cuts,dp);
            mini=min(mini,steps);
        }
        return dp[i][j]=mini;
    }
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        int t=cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(t+1,vector<int>(t+1,-1));
        return solve(1,t-2,cuts,dp);


    }
};
