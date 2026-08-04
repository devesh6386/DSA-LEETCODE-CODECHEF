#include <ext/pb_ds/assoc_container.hpp>   
#include <ext/pb_ds/tree_policy.hpp>  
using namespace __gnu_pbds;
class Solution {
public:
   typedef tree<long long, null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n=nums.size();
        long long ans=0;
        long long pref=0;
        ordered_set st;
        st.insert(0);//empty
        for(int i=0;i<n;i++){
            pref+=nums[i]%2==0?b:-a;
            long long less = st.order_of_key(pref);
            ans+=st.size()-less;
            st.insert(pref);
        }
        return ans;
    }
};


        