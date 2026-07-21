class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n=votes.size();
        int m=votes[0].size();
        vector<vector<int>>rank(26,vector<int>(m,0));
        for(string &vote:votes){
            for(int i=0;i<m;i++){
                rank[vote[i]-'A'][i]++;
            }//no pf votes 
        }
        string ans=votes[0];
        sort(ans.begin(),ans.end(),[&](char a,char b){
            for(int i=0;i<m;i++){
                if(rank[a-'A'][i]!=rank[b-'A'][i]){//if not equal
                    return rank[a-'A']>rank[b-'A'];
                }
            }
            return a<b;
        });
        
        return ans;
    }
};
    

         