class Solution {
public:
    int sumn(int n){
        int ans1=0;
        while(n>0){
            int dig=n%10;
            ans1+=dig;
            n=n/10;
        }
        return ans1;
    }
    int multn(int n){
        int ans2=1;
        while(n>0){
            int dig=n%10;
            ans2*=dig;
            n=n/10;
        }
        return ans2;
    }
    bool checkDivisibility(int n) {
        int s=sumn(n);
        int p=multn(n);
        int com=s+p;
        if(n%com==0)return true;
        return false;
    }
};
        
    