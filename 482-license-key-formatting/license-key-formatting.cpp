class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n=s.length();//
        int cnt=0;
        string ans="";
        for(int i=n-1;i>=0;i--){
            if(s[i]=='-')continue;
            if(islower(s[i])){
                ans+=toupper(s[i]);
            }
            else{
                ans+=s[i];
            }
            cnt++;
            if(cnt==k){
                ans+='-';
                cnt=0;
            }
        }
        
        
        if(!ans.empty() && ans.back()=='-'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

