class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int n=nums.size();
        int target=numsDivide[0];
        for(int x:numsDivide){
            target=std::gcd(target,x);
        }
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;++i){
            if(target%nums[i]==0){
                return i;
            }
        }
        return -1;
    }
};
        