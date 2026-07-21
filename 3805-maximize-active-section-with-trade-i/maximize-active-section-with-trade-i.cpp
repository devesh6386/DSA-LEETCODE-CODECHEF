class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int totalones=0;
        int cnt1=0;//previous zeroblock
        int cnt2=0;//curr zeroblock
        int ans=0;//00--11
        int i=0;
        int n=s.length();
        while(i<n){
            if(s[i]=='0'){
                cnt1++;
                i++;
            }
            else{
                while(i<n && s[i]=='1'){
                    totalones++;
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
        return ans+totalones;
    }
};
