class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n);
        vector<int>seq=arr;
        sort(seq.begin(),seq.end());//sorted it
        unordered_map<int,int>rank;
        int strank=1;
        for(int i=0;i<n;i++){
            if(!rank.count(seq[i])){//not seen befor
                rank[seq[i]]=strank++;//
            }
        }
        for(int i=0;i<n;i++){
            arr[i]=rank[arr[i]];
        }
        return arr;
    }
};
