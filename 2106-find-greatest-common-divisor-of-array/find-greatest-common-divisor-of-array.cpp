class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        int mn=*min_element(nums.begin(),nums.end());
        int gc=std::gcd(mx,mn);
        return gc;
    }
};
     
     