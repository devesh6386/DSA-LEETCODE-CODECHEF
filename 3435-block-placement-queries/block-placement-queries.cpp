class Solution {
public:
    int n=50005;
    vector<bool>res;
    vector<int>segtree;
    void build(){
        segtree.resize(4*n,0);
    }
    void update(int idx,int val,int i,int l,int r){
        if(l==r){
            segtree[i]=val;
            return;
        }
        int mid=l+(r-l)/2;
        if(idx<=mid){
            update(idx,val,2*i+1,l,mid);
        }
        else{
            update(idx,val,2*i+2,mid+1,r);
        }
        segtree[i]=max(segtree[2*i+1],segtree[2*i+2]);
    }
    int queryseg(int start,int end,int i,int l,int r){
        if(l>end|| r<start)return 0;
        if(l>=start && r<=end){
            return segtree[i];
        }
        int mid=l+(r-l)/2;
        return max(queryseg(start,end,2*i+1,l,mid),queryseg(start,end,2*i+2,mid+1,r));
    }
    
    vector<bool> getResults(vector<vector<int>>& queries) {
        build();
        set<int>st;
        st.insert(0);
        for(auto &query:queries){
            if(query[0]==1){
                int x=query[1];
                auto it=st.upper_bound(x);
                int nxt=(it!=st.end())?*it:-1;
                int pre=*prev(it);
                update(x,x-pre,0,0,n-1);
                update(nxt,nxt-x,0,0,n-1);
                st.insert(x);
            }else{
                int x=query[1];
                int sz=query[2];
                auto it=st.upper_bound(x);
                int pre=*prev(it);
                int maxgap=queryseg(0,pre,0,0,n-1);
                int temp=max(maxgap,x-pre);
                res.push_back(temp>=sz);
            }
        }
        return res;
    }
};
         