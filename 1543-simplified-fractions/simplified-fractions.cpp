class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string>ans;
        for(int d=2;d<=n;d++){//
            //now evey no
            for(int no=1;no<=d-1;no++){
                if(std::gcd(no,d)==1){//for this condition

                    ans.push_back(to_string(no)+'/'+to_string(d));
                }
            }
        }
        return ans;
    }
};
        