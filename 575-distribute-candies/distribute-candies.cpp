class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        int ans=0;
        set<int>st;
        for(int i=0;i<n;i++){
            st.insert(candyType[i]);
        }
        ans=min((int)st.size(),n/2);
        return ans;
    }
};
        