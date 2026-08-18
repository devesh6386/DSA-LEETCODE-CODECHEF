class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<n;i++){
            int w=0;
            int h=0;
            for(int j=i;j<n;j++){
                w+=books[j][0];
                h=max(h,books[j][1]);
                if(w<=shelfWidth){
                    dp[j+1]=min(dp[j+1],dp[i]+h);
                }
            }
        }
        return dp[n];
    }
};
               