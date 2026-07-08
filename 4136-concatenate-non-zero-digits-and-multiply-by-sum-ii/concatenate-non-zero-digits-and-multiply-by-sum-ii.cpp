class Solution {
public:

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int mod=1e9+7;
        int m=s.size();
        vector<long long>val(m+1,0);
        vector<long long>ps(m+1,0);
        vector<int>cnt(m+1,0);
        vector<long long>pow10(m+1,1);
        for(int i=1;i<=m;i++){
            pow10[i]=pow10[i-1]*10%mod;
        }
        for(int i=0;i<m;i++){
            int dig=s[i]-'0';
            ps[i+1]=ps[i]+dig;
            if(dig){
                val[i+1]=(val[i]*10+dig)%mod;
                cnt[i+1]=cnt[i]+1;
            }
            else{
                val[i+1]=val[i];
                cnt[i+1]=cnt[i];
            }
        }
        vector<int>ans;
        ans.reserve(queries.size());
        for(auto &q:queries){
            int l=q[0];
            int r=q[1];
            int k=cnt[r+1]-cnt[l];
            long long x=(val[r+1]-val[l]*pow10[k]%mod+mod)%mod;
            long long sum=ps[r+1]-ps[l];
            ans.push_back(x*sum%mod);
        }
        return ans;
    }
};
