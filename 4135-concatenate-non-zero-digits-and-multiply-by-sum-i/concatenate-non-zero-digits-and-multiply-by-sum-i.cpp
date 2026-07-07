class Solution {
public:
    long long zeroel(int num){
        std::string str=to_string(num);
        str.erase(std::remove(str.begin(),str.end(),'0'),str.end());
        if(str.empty())return 0;
        return std::stoi(str);
    }
    long long sumf(int x){
        long long sum=0;
        while(x>0){
            int dig=x%10;
            sum+=dig;
            x=x/10;
        }
        return sum;
    }
    
    long long sumAndMultiply(int n) {
        if(n==0)return 0;
        long long x=zeroel(n);
        long long sum=sumf(x);
        return x*sum;
    }
};

        
    