class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m=reservedSeats.size();
        int ans=INT_MIN;
        unordered_map<int,vector<bool>>isres;
        for(auto &seat:reservedSeats){
            int rowno=seat[0];
            int colno=seat[1];
            if (isres.find(rowno)==isres.end()){
                isres[rowno]=vector<bool>(11,false);
            }
            isres[rowno][colno]=true;
            
        }
        int total=2*n;
        for(auto &pair:isres){
            auto &row=pair.second;
            //checl for free
            bool isleftfree=!row[2] && !row[3] && !row[4] && !row[5];
            bool ismidfree=!row[4] && !row[5] && !row[6] && !row[7];
            bool isrigfree=!row[6] && !row[7] && !row[8] && !row[9];
            if(isleftfree && isrigfree){
                total;
            }
            else if(isleftfree || isrigfree || ismidfree){
                total-=1;
            }
            else{
                total-=2;
            }
        }
        return total;
    }
};
            