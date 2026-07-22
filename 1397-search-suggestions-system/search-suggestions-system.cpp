class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
       int n=products.size();
        sort(products.begin(),products.end());
        vector<vector<string>>ans;
        string pref="";//matching part
        for(char c:searchWord){
            pref+=c;
            vector<string>tmp;//insert into ans
            for(string& p:products){
                if(p.size()>=pref.size()){
                    if(p.substr(0,pref.size())==pref)tmp.push_back(p);
                }
                if(tmp.size()>3)tmp.resize(3);
            }
            
            sort(tmp.begin(),tmp.end());
            ans.push_back(tmp);
        }
        return ans;
    }
};
    