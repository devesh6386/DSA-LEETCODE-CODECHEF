class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>freq;
        for(auto num:nums){
            freq[num]++;
        }
        vector<int>ans;
        int limit=n/3;
        for(auto it:freq){
            if(it.second>limit){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
    