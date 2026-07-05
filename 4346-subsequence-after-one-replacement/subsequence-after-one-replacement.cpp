class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(n>m)return false;
        int matched=0;//refer to s
        int lastmatchpos=0;///refer to t
        for(int i=0;i<n;i++){
            for(int j=i+lastmatchpos;j<=m-n+i;j++){
                if(s[i]==t[j]){
                    if(i!=j){
                        lastmatchpos=j;
                    }
                    
                    matched++;
                    break;
                    
                }
            }
        }
        return matched>=n-1;
    }
};
                