class Solution {
public:
    bool isSubstringPresent(string s) {
        string rev="";
        int n=s.length();
        for(int i=n-1;i>=0;i--){
            rev+=s[i];
        }
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1;j++){
                if((s[i]==rev[j])&& (s[i+1]==rev[j+1])){
                    return true;
                }
            }
        }
        return false;
    }
};

                    