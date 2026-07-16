class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<long long>prefixGcd(n);
        
        int mx=nums[0];
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            prefixGcd[i]=std::gcd(nums[i],mx);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        long long ans=0;
        long long l=0;
        long long r=n-1;
        while(l<r){
            ans+=std::gcd(prefixGcd[l],prefixGcd[r]);
            l++;
            r--;
        }
        return ans;
    }
};
    