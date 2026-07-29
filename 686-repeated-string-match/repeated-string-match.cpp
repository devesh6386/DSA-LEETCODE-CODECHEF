class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n=a.length();
        int m=b.length();
        //build lps array
        vector<int>lps(m,0);
        for(int i=1,len=0;i<m;i++){
            while(len>0 && b[i]!=b[len]){
                len=lps[len-1];
            }
            if(b[i]==b[len]){
                len++;
                lps[i]=len;
            }
        }
        //kmp search for subsytring
        //circular indexing i%n
        for(int i=0,j=0;i<n+m;i++){
            while(j>0 && a[i%n]!=b[j]){
                j=lps[j-1];
            }
            if(a[i%n]==b[j]){
                j++;
            }
            if(j==m){
                //touched is i+1
                return (i/n)+1;
            }
        }
        return -1;
    }
};
    