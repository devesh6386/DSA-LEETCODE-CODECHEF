class Solution {
public:
typedef long long ll;
    long long count(ll x,vector<int>&coins){
        ll ans=0;
        int n=coins.size();
        for(int mask=1;mask<(1<<n);mask++){
            ll l=1;
            int cnt=0;
            for(int i=0;i<n;i++){
                if(mask &(1<<i)){
                    cnt++;
                    l=std::lcm(l,(ll)coins[i]);
                }
                if(l>x)break;
            }
            if(l>x)continue;
            if(cnt % 2==1){
                ans+=floor(x/l);
            }
            else{
                ans-=floor(x/l);
            }
        }
        return ans;

    }
    long long findKthSmallest(vector<int>& coins, int k) {
        int n=coins.size();
        ll l=0;
        ll r=1LL*(*min_element(coins.begin(),coins.end()))*k;
        while(l<r){
            ll mid=l+(r-l)/2;
            if(count(mid,coins)>=k){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};
           