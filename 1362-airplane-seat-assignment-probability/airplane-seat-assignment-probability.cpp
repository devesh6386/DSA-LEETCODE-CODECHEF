class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        //p(1)=1//base case
        //p(2)=1/2
        if(n==1)return 1.0;
        if(n==2)return 0.5;
        return 0.5;

    }
};