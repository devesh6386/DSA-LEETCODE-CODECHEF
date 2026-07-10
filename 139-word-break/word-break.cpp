class Solution {
public:
    bool solve(int i,string &s,unordered_set<string>&st,vector<int>&dp){
        if(i==s.length())return true;
        int t=s.length();
        if(dp[i]!=-1)return dp[i];
        string temp="";
        for(int j=i;j<t;j++){
            temp+=s[j];
            if(st.count(temp) && solve(j+1,s,st,dp)){
                return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(),wordDict.end());//
        int n=s.size();
        vector<int>dp(n+1,-1);
        return solve(0,s,st,dp);

    }
};