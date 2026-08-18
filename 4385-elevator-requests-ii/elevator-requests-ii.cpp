class Solution {
public:
typedef  long long ll;
    long long solve(int i,int j,int pos,vector<int>&requests,vector<vector<vector<ll>>>&dp){
        ll N=requests.size();
        if(i>j)return 0;
        if(i==0 && j==N-1)return 0;
        if(dp[i][j][pos]!=-1)return dp[i][j][pos];
        ll rem=i+(N-1-j);
        ll curr=requests[j];
        if(pos==0)curr=requests[i];
        ll l=1e18;
        ll r=1e18;
        if(i>0){//l++
            ll dist=curr-requests[i-1];
            l=min(l,dist*rem+solve(i-1,j,0,requests,dp));
        }
        if(j<N-1){
            ll dist=requests[j+1]-curr;
            r=min(r,dist*rem+solve(i,j+1,1,requests,dp));//1 ==j
        }
        return dp[i][j][pos]=min(l,r);
    }
    long long elevatorRequests(int n, int start, vector<int>& requests) {
        if(std::find(requests.begin(),requests.end(),start)==requests.end()){
            requests.push_back(start);
        }
        std::sort(requests.begin(),requests.end());
        int t=requests.size();
        vector<vector<vector<ll>>>dp(t,vector<vector<ll>>(t,vector<ll>(2,-1)));
        int idx=find(requests.begin(),requests.end(),start)-requests.begin();
        return solve(idx,idx,0,requests,dp);
    }
};
    