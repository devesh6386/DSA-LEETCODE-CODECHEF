class Solution {
public:
    string smallestPalindrome(string s) {
        unordered_map<char,int>freq;
        int n=s.length();
        for(char c:s){
            freq[c]++;
        }
        string l="";
        string mid="";
        for(char c='a';c<='z';c++){
            if(freq.find(c)!=freq.end()){
                if(freq[c]%2!=0){
                    mid=c;
                }
                l.append(freq[c]/2,c);
            }
        }
        string r=l;
        reverse(r.begin(),r.end());
        return l+mid+r;
    }
};
    