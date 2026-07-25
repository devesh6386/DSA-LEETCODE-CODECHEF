class Solution {
public:
    int maxProduct(int n) {
        vector<int>num;
        while(n>0){
            long long dig=n%10;
            num.push_back(dig);
            n=n/10;
        }
        sort(num.begin(),num.end());
        int k=num.size();
        int ans=num[k-1]*num[k-2];
        return ans;
    }
};
    