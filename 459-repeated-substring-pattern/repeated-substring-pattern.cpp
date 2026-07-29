class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.length();
        vector<int>lps(n,0);
        for(int i=1,len=0;i<n;i++){
            while(len>0 && s[i]!=s[len]){
                len=lps[len-1];
            }
            if(s[i]==s[len]){
                len++;
            }
            lps[i]=len;
        }
        int final=lps[n-1];
        return final>0 &&(n%(n-final)==0);
    }
};