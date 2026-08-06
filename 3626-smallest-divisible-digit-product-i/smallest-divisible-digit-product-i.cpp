class Solution {
public:
    int pro(int n){
        int ans=1;
        while(n>0){
            int dig=n%10;
            ans*=dig;
            n/=10;
        }
        return ans;
    }
    
    int smallestNumber(int n, int t) {
        int res=0;
        int i=n;
        while(true){
            if(pro(i)%t==0){
                return i;
            }
            i++;
        }
        return res;
    }
};
            