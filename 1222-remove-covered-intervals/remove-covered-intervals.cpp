class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
            if(a[0]==b[0])return a[1]>b[1];
            return a[0]<b[0];
        });
        //c<=a && b<=d
        //n is ans
        int ans=n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(intervals[i][0]>=intervals[j][0] && intervals[i][1]<=intervals[j][1]){
                        ans--;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
               