class Solution {
public:
    long long modpow(long long a,long long b,long long mod){
        long long res=1;//solution
        a=a%mod;
        while(b>0){
            if(b%2==1){
                res=(res*a)%mod;
            }
            a=(a*a)%mod;
            b=b>>1;
            
        }
        return res;
    }
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int>ans;
        int n=variables.size();
        for(int i=0;i<n;i++){
            int a=variables[i][0];
            int b=variables[i][1];
            int c=variables[i][2];
            int m=variables[i][3];
            int x=modpow(a,b,10);
            int y=modpow(x,c,m);
            if(y==target){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
           