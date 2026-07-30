class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        unordered_map<int,int>mpp;
        int start=2;
        int cnt=0;
        for(char ch:word){
            if(start>9){
                start=2;//restart
            }
            mpp[start]++;//mpving map updat
            cnt+=mpp[start];
            start+=1;
        }
        return cnt;
    }
};



    