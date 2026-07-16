class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<long long>prefixGcd(n);
        int mx=nums[0];
        for(int i=0;i<n;i++){
            mx=max(nums[i],mx);
            prefixGcd[i]=std::gcd(nums[i],mx);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int l=0;
        int r=n-1;
        long long ans=0;
        while(l<r){
            
            ans+=gcd(prefixGcd[l],prefixGcd[r]);
            //if(l==r)continue;
            l++;
            r--;
        }
        return ans;
    }
};
      