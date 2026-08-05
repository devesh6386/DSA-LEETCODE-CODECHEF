class Solution {
public:
    struct TrieNode{
        TrieNode *children[2];
        TrieNode(){
            children[0]=NULL;
            children[1]=NULL;
        }
    };
    void insert(TrieNode*root,int num){
        TrieNode*curr=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            int opp=1-bit;
            if(curr->children[bit]==NULL){
                curr->children[bit]=new TrieNode();
            }
            curr=curr->children[bit];
        }
    }
    int search(TrieNode*root,int num){
        TrieNode*curr=root;
        int ans=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            int opp=1-bit;
            if(curr->children[opp]!=NULL){
                ans=(ans|(1<<i));
                curr=curr->children[opp];
            }
            else{
                curr=curr->children[bit];
            }
        }
        return ans;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        int maxx=0;
        TrieNode*root=new TrieNode();
        for(int num:nums){
            insert(root,num);
        }
        for(int num:nums){
            maxx=max(maxx,search(root,num));
        }
        return maxx;
    }
};
        