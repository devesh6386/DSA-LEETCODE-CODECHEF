class Solution {
public:
vector<int>bit;
int n;
    void update(int i){
        while(i<=n){
            bit[i]++;
            i=i+(i&(-i));
        }
    }
    int query(int i){
        int sum=0;
        while(i>0){
            sum+=bit[i];
            i=i-(i&(-i));
        }
        return sum;
    }
    vector<int> countSmaller(vector<int>& nums) {
        n=nums.size();
        vector<int>v=nums;
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        n=nums.size();
        vector<int>ans(n);
        bit.assign(n+1,0);
        for(int i=n-1;i>=0;i--){
            int rank=lower_bound(v.begin(),v.end(),nums[i])-v.begin()+1;
            ans[i]=query(rank-1);
            update(rank);
        }
        return ans;
    }
};