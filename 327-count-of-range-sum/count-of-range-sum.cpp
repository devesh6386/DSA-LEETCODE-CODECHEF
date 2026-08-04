#include <ext/pb_ds/assoc_container.hpp>   
#include <ext/pb_ds/tree_policy.hpp>  
using namespace __gnu_pbds;
class Solution {
public:
    typedef tree<pair<long long, int>,null_type,less<pair<long long, int>>,               rb_tree_tag,                           
tree_order_statistics_node_update      
> ordered_set;
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        ordered_set st;
        long long pref=0;
        long long ans=0;
        st.insert({0,0});
        for(int i=0;i<n;i++){
            pref+=nums[i];
            long long up=st.order_of_key({pref-lower+1,-1});
            long long low=st.order_of_key({pref-upper,-1});
            ans+=up-low;
            st.insert({pref,i+1});
        }
        return ans;
    }
};


        