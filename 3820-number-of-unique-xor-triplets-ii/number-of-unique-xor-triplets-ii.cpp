class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st;
        unordered_set<int>pairwise;
        for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
            pairwise.insert(nums[i]^nums[j]);
           }
        }
        for(int pair:pairwise){
            for(int k=0;k<n;k++){
                int no=pair^nums[k];
                st.insert(no);
            }
        }
        
        return st.size();
    }
};
            