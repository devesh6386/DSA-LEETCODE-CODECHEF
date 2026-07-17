class TreeAncestor {
public:
    vector<vector<int>>ancestortable;
    int row;
    int col;

    TreeAncestor(int n, vector<int>& parent) {
        row=n;
        col=log2(n)+1;
        ancestortable.resize(row,vector<int>(col,-1));
        //find parent
        for(int node=0;node<n;node++){
            ancestortable[node][0]=parent[node];
        }
        for(int j=1;j<col;j++){
            for(int node=0;node<n;node++){
                if(ancestortable[node][j-1]!=-1)ancestortable[node][j]=ancestortable[ancestortable[node][j-1]][j-1];
            }
        }
    }
    int getKthAncestor(int node, int k) {
        for(int j=0;j<col;j++){
            if(k&(1<<j)){
                if(node==-1)return -1;
                node=ancestortable[node][j];
            }
        }
        return node;
    }
};
           

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */