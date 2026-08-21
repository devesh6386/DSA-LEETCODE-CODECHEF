class Solution {
public:
typedef long long ll;
long long count(ll x,vector<int>&coins){
    int n=coins.size();
    ll ans=0;
    for(int mask=1;mask<(1<<n);mask++){
        ll l=1;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(mask & (1<<i)){
                cnt++;
                l=std::lcm(l,coins[i]);
            }
            
            if(l>x)break;
        }
        if(l>x)continue;
        if(cnt%2==1){//odd
            ans+=floor(x/l);
        }
        else{
            ans=ans-floor(x/l);
        }
    }
    return ans;
}
    long long findKthSmallest(vector<int>& coins, int k) {
        int n=coins.size();
        //lcm
        //binary seach on ans
        ll low=0;
        ll res=0;
        ll r=1LL*(*min_element(coins.begin(),coins.end()))*k;
        while(low<r){
            ll mid=low+(r-low)/2;
            if(count(mid,coins)>=k){
                
                r=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
           