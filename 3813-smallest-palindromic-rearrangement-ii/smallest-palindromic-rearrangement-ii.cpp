class Solution {
public:
    long long comb(int n,int r,int lim){
        r=min(r,n-r);
        long long ans=1;
        for(int i=1;i<=r;i++){
            ans=ans*(n-r+i)/i;
            if(ans>lim){
                return lim+1;
            }
        }
        return ans;
    }
    long long calc(vector<int>&cnt,int rem,int lim){
        long long ans=1;
        for(int x:cnt){
            if(!x)continue;
            ans*=comb(rem,x,lim);
            if(ans>lim){
                return lim+1;
            }
            rem-=x;
        }
        return ans;
    }
    string smallestPalindrome(string s, int k) {
        int n=s.length();
        vector<int>mpp(26,0);
        string ans(n,' ');
        int m=n/2;
        for(char c:s){
            mpp[c-'a']++;
        }
        for(int i=0;i<26;i++){
            if(mpp[i]&1){
                ans[m]='a'+i;
            }
            mpp[i]/=2;
        }
        if(calc(mpp,m,k)<k)return "";
        for(int i=0;i<m;i++){
            for(int c=0;c<26;c++){
                if(!mpp[c])continue;
                mpp[c]--;
                long long cur=calc(mpp,m-i-1,k);
                if(cur>=k){
                    ans[i]='a'+c;
                    break;
                }
                k=k-cur;
                mpp[c]++;
            }
        }
        for(int i=0;i<m;i++){
            ans[n-i-1]=ans[i];
        }
        return ans;
    }
};
    