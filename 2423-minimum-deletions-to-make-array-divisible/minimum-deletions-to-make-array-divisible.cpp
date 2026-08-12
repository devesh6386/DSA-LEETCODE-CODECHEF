class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());//min no on top;
        int target=numsDivide[0];
        for(int x:numsDivide){
            target=std::gcd(target,x);
        }
        int ans=0;
        while(!pq.empty()){
            int small=pq.top();
            if(target%small==0){
                return ans;
            }
            pq.pop();
            ans++;
        }
        return -1;
        
    }
};
    