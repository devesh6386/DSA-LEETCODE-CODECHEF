class Solution {
public:
typedef long long ll;
int mod=1e9+7;
    ll count(ll x,int a,int b){
        ll l=std::lcm(a,b);
        ll ans=(x/a)+(x/b)-(x/l);
        return ans;

    }
    int nthMagicalNumber(int n, int a, int b) {
        
        ll l=1;
        long long r=1LL*n*min(a,b);
        while(l<r){
            ll mid=l+(r-l)/2;
            if(count(mid,a,b)>=n){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l%mod;
    }
};