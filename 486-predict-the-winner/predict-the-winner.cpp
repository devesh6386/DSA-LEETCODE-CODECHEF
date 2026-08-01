class Solution {
public:
    int solve(int i,int j,vector<int>&nums){
        int n=nums.size();
        if(i==j)return nums[j];
        int left=nums[i]-solve(i+1,j,nums);
        int right=nums[j]-solve(i,j-1,nums);
        int maxi=max(left,right);
        return maxi;
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        return solve(0,n-1,nums)>=0;
    }
};
        
