class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>dp(n,1);//column length initailyy1
        for(int c=0;c<n;c++){
            for(int j=c-1;j>=0;j--){
                if(dp[j]+1>dp[c]){//till previous col compare
                    bool good=true;
                    for(auto &r:grid){
                        if(abs(r[c]-r[j])>limit){
                            good=false;
                            break;
                        }
                    }
                    if(good){
                        dp[c]=dp[j]+1;
                    }
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
        