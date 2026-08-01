class Trie {
public:
    struct TrieNode{
        bool isendofword;
        TrieNode*children[26];
    };
    TrieNode*root;
    Trie() {
        root=getNode();
    }
    TrieNode*getNode(){
        TrieNode*newNode=new TrieNode();
        newNode->isendofword=false;
        for(int i=0;i<26;i++){
            newNode->children[i]=NULL;
        }
        return newNode;
    }
    void insert(string word) {
        TrieNode*crawl=root;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            int idx=ch-'a';
            if(crawl->children[idx]==NULL){
                crawl->children[idx]=getNode();
            }
            crawl=crawl->children[idx];//aage traversal
        }
        crawl->isendofword=true;
    }
    bool search(string word) {
        TrieNode*crawl=root;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            int idx=ch-'a';
            if(crawl->children[idx]==NULL){
                return false;
            }
            crawl=crawl->children[idx];
        }
        return (crawl!=NULL && crawl->isendofword==true);
    }
    bool startsWith(string prefix) {
        TrieNode*crawl=root;
        int i=0;
        for(;i<prefix.length();i++){
            char ch=prefix[i];
            int idx=ch-'a';
            if(crawl->children[idx]==NULL){
                return false;
            }
            crawl=crawl->children[idx];
            
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */