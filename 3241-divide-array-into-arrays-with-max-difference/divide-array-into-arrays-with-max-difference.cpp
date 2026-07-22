class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>ans(n/3,vector<int>(3));
        //n=multple of 3
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i+=3){
            if(nums[i+2]-nums[i]>k){
                return {};
            }
            else ans[i/3]={nums[i],nums[i+1],nums[i+2]}
            ;
        }
        return ans;
    }
};