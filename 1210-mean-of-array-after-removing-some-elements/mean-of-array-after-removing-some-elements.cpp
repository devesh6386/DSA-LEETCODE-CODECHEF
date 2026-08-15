class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int maxi=arr[n-1];
        double sum=0;

        int mini=arr[0];
        double k=n*0.05;
        for(double i=k;i<n-k;i++){
            sum+=arr[i];
        }
        double mean=0;
        mean=sum/(n-2*k);
        return mean;
    }
};

        