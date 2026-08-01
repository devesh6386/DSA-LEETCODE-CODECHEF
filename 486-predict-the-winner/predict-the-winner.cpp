class Solution {
public:
    int solve(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        int n=nums.size();
        if(i==j)return nums[j];
        if(dp[i][j]!=-1)return dp[i][j];
        int left=nums[i]-solve(i+1,j,nums,dp);
        int right=nums[j]-solve(i,j-1,nums,dp);
        int maxi=max(left,right);
        return dp[i][j]=maxi;
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,n-1,nums,dp)>=0;
    }
};
        
