class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long a=nums[0];
        long long b=nums[1];
        long long c=nums[n-2];
        long long d=nums[n-1];
        long long x=100000;
        long long p1=a*b*x;
        long long p2=c*d*x;
        long long p3=a*d*(-x);
        return max({p1,p2,p3});
    }
};