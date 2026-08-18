class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
         int n=nums.size();
         int mx=*max_element(nums.begin(),nums.end());
         unordered_map<int,int>mpp;
         for(int num:nums){
            mpp[num]++;
         }
         int ans=-1;
         if(k==n){
            return mx;
         }
         
         else if(k==1){
            //int ans=-1;
            for(auto &[x,cnt]:mpp){
                if(cnt==1){
                    ans=max(ans,x);
                }
            }
            return ans;
         }
         else{
            if(mpp[nums[0]]==1){
                ans=max(ans,nums[0]);
            }
            if(mpp[nums[n-1]]==1){
                ans=max(ans,nums[n-1]);
            }
         }
         return ans;
    }
};
           