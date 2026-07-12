class Solution {
public://here we have to find 2 occurance
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int first=-1;
        int last=-1;
        int r=n-1;
        vector<int>ans;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                first=mid;
                r=mid-1;//1str
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        l=0;
        r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                last=mid;
                l=mid+1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        ans.push_back(first);

        return {first,last};
    }
};
                  