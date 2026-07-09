class Solution {
public:
    int longestcommonsubs(string text1,string text2){
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    int longestpal(string text1){
        string rev=text1;
        reverse(rev.begin(),rev.end());
        return longestcommonsubs(text1,rev);
    }
    int minInsertions(string s) {
        int n=s.length();
        return n-longestpal(s);
    }
};
        
    