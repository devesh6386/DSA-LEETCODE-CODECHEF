class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>freq(mx+1);
        for(int x:nums){
            freq[x]++;
        }
        vector<long long>cnt(mx+1);
        for(int g=1;g<=mx;g++){
            for(int j=g;j<=mx;j+=g){
                cnt[g]+=freq[j];
            }
        }
        //cnt of pairs
        //nowhow ,any are equal to gcd
        vector<long long>gcdPairs(mx+1);
        for(int g=mx;g>=1;g--){
            gcdPairs[g]+=cnt[g]*(cnt[g]-1)/2;
            for(int j=2*g;j<=mx;j+=g){//remove all greater
                gcdPairs[g]-=gcdPairs[j];
            }
        }
        vector<long long>pref(mx+1);
        for(int g=1;g<=mx;g++){
            pref[g]=pref[g-1]+gcdPairs[g];
        }
        vector<int>ans;
        for(long long q:queries){
            auto it=upper_bound(pref.begin(),pref.end(),q);
            int g=distance(pref.begin(),it);
            ans.push_back(g);
        }
        return ans;
    }
};
      