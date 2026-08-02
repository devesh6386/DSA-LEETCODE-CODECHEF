class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return false;
        int first=INT_MAX;
        int second=INT_MAX;
        for(int num:nums){
            if(num<=first){
                first=num;//the greatest
            }
            else if(num<=second){
                second=num;
            }
            else{
                return true;
            }
        }
        return false;
    }
};