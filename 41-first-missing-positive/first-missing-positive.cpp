class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        sort(nums.begin(),nums.end());
        for(int num:nums){
            if(num==ans){
                ans++;
            }
        }
        return ans;
    }
};
    