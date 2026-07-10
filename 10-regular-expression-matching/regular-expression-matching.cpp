class Solution {
public:
    int solve(int i,int j,string & s,string &p,vector<vector<int>>&dp){
        if(i<0 && j<0)return true;
        if(i>=0 && j<0)return false;
        if(i<0 && j>=0){
            while(j>=0){
                if(p[j]=='*')j=j-2;
                else{//
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if((s[i]==p[j]) || (p[j]=='.'))return dp[i][j]=solve(i-1,j-1,s,p,dp);
        if(p[j]=='*'){
            bool ans=solve(i,j-2,s,p,dp);
            if(j>0 && (p[j-1]==s[i] || p[j-1]=='.')){
                ans=ans|| solve(i-1,j,s,p,dp);
            }
            return dp[i][j]=ans;
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(n-1,m-1,s,p,dp);
        
    }
};