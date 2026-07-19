class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.length();//store last occurance of each character
        string st;
        vector<int>last(26);
        vector<bool>vis(26,false);
        for(char c:s){
            last[c-'a']++;
        }
        //string act as stack
        for(char c:s){
            last[c-'a']--;
            if(vis[c-'a']){
                continue;//if it is already in stack
            }
            while(!st.empty() && st.back()>c && last[st.back()-'a']>0){
                vis[st.back()-'a']=false;
                st.pop_back();//top wala remove
            }
            st.push_back(c);
            vis[c-'a']=true;
        }
        return st;
    }
};


