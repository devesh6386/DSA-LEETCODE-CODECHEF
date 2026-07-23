class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return n;//we cant gemnerate all no
        //2^noof bits
        int upper=1;
        while(upper<=n){
            upper*=2;
        }
        return upper;
    }
};
    