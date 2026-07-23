class Solution {
public:
    void build(int i,int l,int r,int segmentree[],int arr[]){
        if(l==r){
            segmentree[i]=arr[l];
            return;
        }
        int mid=l+(r-l)/2;
        build(2*i+1,l,mid,segmentree,arr);
        build(2*i+2,mid+1,r,segmentree,arr);
        segmentree[i]=max(segmentree[2*i+1],segmentree[2*i+2]);
    }
    int *construct(int arr[],int n){
        int* segmentree=new int[4*n];
        build(0,0,n-1,segmentree,arr);
        return segmentree;
    }
    int query(int st,int end,int i,int l,int r,int segmentree[]){
        if(l>end || r<st){
            return INT_MIN;
        }
        if(l>=st && r<=end){
            return segmentree[i];
        }
        int mid=l+(r-l)/2;
        return max(query(st,end,2*i+1,l,mid,segmentree),query(st,end,2*i+2,mid+1,r,segmentree));
    }
    int RMQ(int st[],int n,int a,int b){
        return query(a,b,0,0,n-1,st);
    }

    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
         int n=s.length();
         int active=count(s.begin(),s.end(),'1');
         vector<int>blockst;
         vector<int>blockend;
         int i=0;
         while(i<n){
            if(s[i]=='0'){
                int st=i;
                while(i<n && s[i]=='0'){
                    i++;
                }
                blockst.push_back(st);
                blockend.push_back(i-1);
            }
            else{
                i++;
            }
         }
         int m=blockst.size();
         //if only one block of zeroes
         if(blockst.size()<2){
            return vector<int>(queries.size(),active);
         }//corner case
         vector<int>blocksize(m);
         for(int i=0;i<m;i++){
            blocksize[i]=blockend[i]-blockst[i]+1;
         }
         //pair sum formula
         int k=blocksize.size()-1;
         vector<int>pairsum(k);
         for(int i=0;i<k-1;i++){
            pairsum[i]=blocksize[i]+blocksize[i+1];
         }
         int *st=construct(pairsum.data(),k);
         vector<int>ans;
         for(auto &q:queries){
            int l=q[0];
            int r=q[1];
            //first block in this range 
            int low=lower_bound(blockend.begin(),blockend.end(),l)-blockend.begin();//for indexz
            int high=upper_bound(blockst.begin(),blockst.end(),r)-blockst.begin()-1;
            int maxpairsum=0;
            if(low<high){
                int firstlen=blockend[low]-max(blockst[low],l)+1;
                int lastlen=min(blockend[high],r)-blockst[high]+1;
                if(high-low==1){
                    maxpairsum= firstlen+lastlen;
                }
                else{
                    int pair1=firstlen+blocksize[low+1];
                    int pair2=blocksize[high-1]+lastlen;
                    int RMQmax=RMQ(st,k,low+1,high-2);
                    maxpairsum=max({pair1,pair2,RMQmax});
                }
            }
            ans.push_back({maxpairsum+active});
         }
         return ans;
    }
};
    