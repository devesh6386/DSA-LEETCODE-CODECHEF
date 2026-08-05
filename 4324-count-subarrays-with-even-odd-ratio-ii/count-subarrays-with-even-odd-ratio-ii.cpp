class Solution {
public:
    long long ans=0;
    void merge(vector<long long>&nums,int left,int mid,int right){
        int i=left;
        int j=mid+1;
        while(i<=mid && j<=right){
            if(nums[i]>=nums[j]){
                ans+=(mid-i+1);
                j++;
            }
            else{
                i++;
            }
        }
        vector<long long>tmp(right-left+1);
        int p=left;
        int q=mid+1;
        int k=0;
        
        while(p<=mid && q<=right){
            if(nums[p]>=nums[q]){
                tmp[k++]=nums[q++];
            }
            else{
                tmp[k++]=nums[p++];
            }
        }
        while(p<=mid){
            tmp[k++]=nums[p++];
        }
        while(q<=right){
            tmp[k++]=nums[q++];
        }
        for(int x=0;x<tmp.size();x++){
            nums[left+x]=tmp[x];
        }
    }
    void mergesort(vector<long long>&psum,int start,int end){
        if(start>=end){
            return;
        }
        int mid=start+(end-start)/2;
        mergesort(psum,start,mid);
        mergesort(psum,mid+1,end);
        merge(psum,start,mid,end);
    }
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        
        int even=0;
        int odd=0;
        int n=nums.size();
        vector<long long>psum(n+1,0);
        for(int i=0;i<n;i++){
            if(nums[i]%2==0)even++;
            else{
                odd++;
            }
            psum[i+1]=(1ll*b*even)-(1ll*a*odd);
        }
        mergesort(psum,0,psum.size()-1);
        return ans;
    }
};
