class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        //increasing->decreasing
        vector<int>inc(n,1);//lis
        vector<int> dec(n,1);//reverse lis
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    inc[i]=max(inc[i],inc[j]+1);
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[i]>nums[j]){
                    dec[i]=max(dec[i],dec[j]+1);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            if(inc[i]>1 && dec[i]>1){
                ans=max(ans,inc[i]+dec[i]-1);
            }
        }
        return n-ans;
    }
};
           