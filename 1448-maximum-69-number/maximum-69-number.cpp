class Solution {
public:

    int maximum69Number (int num) {
        vector<int>digits;
        while(num>0){
            int dig=num%10;
            digits.push_back(dig);
            num=num/10;
        }
        //[9,6,6,9];
       for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]==6){
                digits[i]=9;
                break;
            }
       }
       int ans=0;
       for(int i=digits.size()-1;i>=0;i--){
            ans=ans*10+digits[i];
       }
       return ans;
    }
};
    