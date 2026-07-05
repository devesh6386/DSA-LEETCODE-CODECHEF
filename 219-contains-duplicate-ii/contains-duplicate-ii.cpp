class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();//pointer in mpp
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            if(mpp.contains(nums[i])){
                if((i-mpp[nums[i]])<=k){
                    return true;
                }
            }
            mpp[nums[i]]=i;
        }
        return false;
    }
};