class Solution {
public://firstly merge a,b =x then x,c;
    string merge(string a,string b){
        string x="";
        if(a.find(b)!=string::npos)return a;
        if(b.find(a)!=string::npos)return b;
        for(int i=min(a.length(),b.length());i>=0;i--){
            if(a.substr(a.length()-i)==b.substr(0,i)){//if match
                return a+b.substr(i);
            }
        }
        return a+b;
    }
    string minimumString(string a, string b, string c) {
        //greedy based maximal ordering
        //took out largest prefix of b/c that matches withprefix of a/b
        //string ans="";
        //string t;
        string s1=merge(merge(a,b),c);
        string s2=merge(merge(a,c),b);
        string s3=merge(merge(b,a),c);
        string s4=merge(merge(b,c),a);
        string s5=merge(merge(c,a),b);
        string s6=merge(merge(c,b),a);
        vector<string>v={s1,s2,s3,s4,s5,s6};
        string ans=v[0];
        for(int i=0;i<6;i++){
            if(v[i].length()<ans.length()){
                ans=v[i];
            }
            else if(v[i].length()==ans.length() && v[i]<ans){
                ans=v[i];
            }
        }
        return ans;
    }
};
    