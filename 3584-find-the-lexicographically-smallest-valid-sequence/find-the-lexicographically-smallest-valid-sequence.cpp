class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        vector<int>dp(n+1,-1);
        vector<int>ans;
        int j=n-1;
        //from backward
        for(int i=m-1;i>=0 && j>=0;i--){
            if(word1[i]==word2[j]){
                dp[j]=i;
                j--;
            }
        }
        int pos=0;
        bool used=false;
        for(int i=0;i<n;i++){
            while(pos<m){
                if(word1[pos]==word2[i]){
                    ans.push_back(pos);
                    
                    break;
                }
                if(!(used)){
                    if(i==n-1 || (dp[i+1]!=-1 && dp[i+1]>pos)){//remaining words 
                        ans.push_back(pos);
                        used=true;
                        break;
                    }
                }
                pos++;
            }
            if(ans.size()!=i+1)return {};
            pos++;
        }
        return ans;
    }
};
            
            