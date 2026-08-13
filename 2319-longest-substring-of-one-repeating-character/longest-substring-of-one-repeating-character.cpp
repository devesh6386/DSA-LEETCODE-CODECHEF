class Solution {
public:
    struct Node{
        int pre=0;
        int suf=0;
        int maxlen=0;
        char leftChar=0;
        char rightChar=0;
    };
    int n;
    vector<Node>segtree;
    Node merge(Node l,Node r,int leftlen,int rightlen){
        Node res;
        res.leftChar=l.leftChar;
        res.rightChar=r.rightChar;
        res.pre=l.pre;
        if(l.pre==leftlen && l.rightChar==r.leftChar){
            res.pre=l.pre+r.pre;
        }
        res.suf=r.suf;
        if(r.suf==rightlen && l.rightChar==r.leftChar){
            res.suf=r.suf+l.suf;
        }
        res.maxlen=max(l.maxlen,r.maxlen);
        if(l.rightChar==r.leftChar){
            res.maxlen=max(res.maxlen,l.suf+r.pre);
        }
        return res;
    }
    void build(int i,int l,int r,string &s){
        if(l==r){
            segtree[i]={1,1,1,s[l],s[l]};
            return;
        }
        int mid=l+(r-l)/2;
        build(2*i+1,l,mid,s);
        build(2*i+2,mid+1,r,s);
        segtree[i]=merge(segtree[2*i+1],segtree[2*i+2],mid-l+1,r-mid);
    }
     
    void update(int i,int l,int r,int pos,char ch){
        if(l==r){
            segtree[i]={1,1,1,ch,ch};
            return;
        }
        int mid=l+(r-l)/2;
        if(pos<=mid){
            update(2*i+1,l,mid,pos,ch);
        }
        else{
            update(2*i+2,mid+1,r,pos,ch);
        }
        segtree[i]=merge(segtree[2*i+1],segtree[2*i+2],mid-l+1,r-mid);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int k=queryCharacters.length();
        n=s.size();
        segtree.assign(4*n,Node());
        build(0,0,n-1,s);
        vector<int>res(k);
        for(int i=0;i<k;i++){
            int pos=queryIndices[i];
            char ch=queryCharacters[i];
            update(0,0,n-1,pos,ch);
            res[i]=segtree[0].maxlen;
        }
        return res;
    }
};
    