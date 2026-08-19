class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m=reservedSeats.size();
        unordered_map<int,int>mpp;
        //store bitmask

        for(auto &seats:reservedSeats){
            int rowno=seats[0];
            int colno=seats[1];
            mpp[rowno]|=(1<<colno);
        }
        int res=2*(n-mpp.size());
        int maskA=(1<<2)|(1<<3)|(1<<4)|(1<<5);
        int maskb=(1<<4)|(1<<5)|(1<<6)|(1<<7);
        int maskc=(1<<6)|(1<<7)|(1<<8)|(1<<9);
        for(auto &[row,ismask]:mpp){
            bool grpa=(maskA & ismask)==0;
            bool grpb=(maskb & ismask)==0;
            bool grpc=(maskc & ismask)==0;
            if(grpa && grpc){
                res+=2;
            }
            else if(grpa || grpb || grpc){
                res+=1;
            }
        }
        return res;
    }
};
           