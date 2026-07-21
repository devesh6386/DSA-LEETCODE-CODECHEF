class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.length();
        int ones=0;
        for(char c:s){
            if(c=='1'){
                ones++;//original
            }
        }
        string t="1"+s+"1";//augmented
        vector<pair<char,int>>runs;//split
        for(char c:t){
            if(runs.empty()|| runs.back().first!=c){
                runs.push_back({c,1});
            }
            else{
                runs.back().second++;//cnt
            }
        }
        int ans=0;
        for(int i=1;i+1<runs.size();i++){
            if(runs[i].first=='1' && runs[i-1].first=='0' && runs[i+1].first=='0'){
                ans=max(ans,runs[i-1].second+runs[i+1].second);
            }
        }
        return ans+ones;
    }
};