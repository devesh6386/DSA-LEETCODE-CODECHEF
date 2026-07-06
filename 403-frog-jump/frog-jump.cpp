class Solution {
public://hashmap to quickly find index
//memoize currindex,lastjump
    unordered_map<int,int>mpp;
    vector<vector<int>>dp;
    bool solve(int i,int lastjump,vector<int>&stones){
        int n=stones.size();
        if(i==n-1)return true;
        if(dp[i][lastjump]!=-1)return dp[i][lastjump];
        for(int k=lastjump-1;k<=lastjump+1;k++){
            if(k<=0)continue;
            int nextstone=stones[i]+k;
            if(mpp.count(nextstone)){
                if(solve(mpp[nextstone],k,stones)){
                    dp[i][lastjump]=true;
                    return true;
                }
            
            }
        }
        dp[i][lastjump]=false;
        return false;
    }

    bool canCross(vector<int>& stones) {
        int n=stones.size();
        if(n==1)return true;
        dp.assign(n,vector<int>(n+1,-1));
        if(stones[1]!=1)return false;
        for(int i=0;i<n;i++){
            mpp[stones[i]]=i;//pos
        }
       // memset(dp,0,n);
        return solve(0,0,stones);

    }
};