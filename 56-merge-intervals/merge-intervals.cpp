class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int m=intervals.size();
        int n=intervals[0].size();
        //start,end
        if(intervals.empty()){
            return{};
        }
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<m;i++){
            int st=intervals[i][0];
            int end=intervals[i][1];
            int last=ans.back()[1];
            if(st<=last){
                ans.back()[1]=max(last,end);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
          