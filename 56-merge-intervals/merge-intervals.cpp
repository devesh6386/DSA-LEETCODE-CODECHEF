class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int m=intervals[0].size();
        if(intervals.empty()){
            return {};
        }
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            int st=intervals[i][0];
            int end=intervals[i][1];
            int last=ans.back()[1];
            if(st<=last){
                ans.back()[1]=max(end,last);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
           