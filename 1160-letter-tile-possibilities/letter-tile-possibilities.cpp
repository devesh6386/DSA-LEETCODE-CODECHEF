class Solution {
public:
    int dfs(vector<int>&freq){
        int count=0;
        for(int i=0;i<26;i++){
            if(freq[i]==0)continue;
            freq[i]--;
            count+=(1+dfs(freq));
            freq[i]++;
        }
        return count;
    }
    int numTilePossibilities(string tiles) {
        int n=tiles.length();
        vector<int>freq(26,0);
        for(char c:tiles){
            freq[c-'A']++;
        }
        //freq store 
        return dfs(freq);
    }
};
       
       