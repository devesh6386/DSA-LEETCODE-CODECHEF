class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.length();
        int totalone=0;
        int cnt1=0;
        int cnt2=0;
        int ans=0;
        int i=0;
        while(i<n){
            if(s[i]=='0'){
                cnt1++;
                i++;
            }
            else{
                while(i<n && s[i]=='1'){
                    totalone++;
                    i++;
                }
                while(i<n && s[i]=='0'){
                    cnt2++;
                    i++;
                }
                if(cnt1 && cnt2){
                    ans=max(ans,cnt1+cnt2);
                }
                cnt1=cnt2;
                cnt2=0;
            }
        }
        return ans+totalone;
    }
};
          