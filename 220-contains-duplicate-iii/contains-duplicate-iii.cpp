class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff){   set<int>s(nums.begin(),nums.end());
        int n=nums.size();
        if(valueDiff==0 && n==s.size())return false;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=i+indexDiff && j<n;j++){
                if(i!=j && (long long)abs(nums[i]-nums[j])<=valueDiff)return true;
            }
        }
        return false;
    }
};
            