class Solution {
public:
    typedef long long ll;
    string func(ll num,int length){
        string str="";
        for(int dig=9;dig>=2;dig--){
            while(num%dig==0){
                str.push_back(dig+'0');
                num=num/dig;
            }
        }
        if(num!=1)return "";
        while((int)str.length()<length){
            str.push_back('1');
        }
        reverse(str.begin(),str.end());
        return str;
    }
    string smallestNumber(string num, long long t) {
        int n=num.length();
        ll temp=t;
        for(int prime:{2,3,5,7}){
            while(temp%prime==0){
                temp=temp/prime;
            }
        }
        if(temp!=1){
            return "-1";
        }
        //precompute remainfactor[i];
        vector<ll>remain(n+1,t);
        for(int i=0;i<n;i++){
            int dig=num[i]-'0';
            if(dig==0)break;
            remain[i+1]=remain[i]/gcd(remain[i],(ll)dig);
        }
        if(remain[n]==1)return num;
        int zeroidx=n-1;
        int zeropos=num.find('0');
        if(zeropos!=-1){
            zeroidx=zeropos;
        }
        for(int i=zeroidx;i>=0;i--){
            ll required=remain[i];
            int freeslot=n-1-i;
            for(int dig=(num[i]-'0')+1;dig<=9;dig++){
                ll furtreq=required/gcd(required,(ll)dig);
                string reqno=func(furtreq,freeslot);
                if((int)reqno.length()==freeslot){
                    return num.substr(0,i)+char(dig+'0')+reqno;
                }
            }
        }
        return func(t,n+1);
    }
};

