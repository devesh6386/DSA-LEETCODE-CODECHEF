class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.length();
        vector<int>freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        string ans(n,' ');
        int l=0;
        int r=n-1;
        for(int i=0;i<26;i++){//process all characters
            while(freq[i]>=2){
                ans[l++]=char('a'+i);
                ans[r--]=char('a'+i);
                freq[i]-=2;
            }
            if(freq[i]==1){
                ans[(n/2)]=char('a'+i);
            }
        }
        return ans;
    }
};
    