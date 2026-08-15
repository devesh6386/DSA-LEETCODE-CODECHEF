class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int val=0;
        for(int num:nums){
            val=val^num;
        }
        if(val!=0)return n;
        for(int num:nums){
            if(num!=0){
                return n-1;
            }
        }
        return 0;
    }
};
           