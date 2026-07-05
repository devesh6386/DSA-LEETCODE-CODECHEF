class Solution {
public:
   int n;
   int mod=1e9+7;
   int getchar(char ch){
    return ch!='S'?ch-'0':0; 
   }
   vector<vector<pair<int,int>>>dp;
   bool isvalid(int i,int j,vector<string>&board){
        if(i>=0 && i<n && j>=0 && j<n && board[i][j]!='X')return true;
        return false;
   }
   pair<int,int>solve(int i,int j,vector<string>&board){
        if(board[i][j]=='E')return {0,1};
        if(board[i][j]=='X')return {0,0};
        if(dp[i][j]!=make_pair(-1,-1))return dp[i][j];
        int upscore=0;
        int uppath=0,leftscore=0,diagscore=0,diagpath=0,leftpath=0;
        char ch=board[i][j];
        if(isvalid( i-1, j,board)){
            auto[score,path]=solve(i-1,j,board);//left
            upscore=score;
            uppath=path;
            if(uppath>0){
                upscore+=getchar(ch);
            }
        }
        if(isvalid(i,j-1,board)){
            auto[score,path]=solve(i,j-1,board);//left
            leftscore=score;
            leftpath=path;
            if(leftpath>0){
                leftscore+=getchar(ch);
            }
        }
        if(isvalid(i-1,j-1,board)){
            auto[score,path]=solve(i-1,j-1,board);//left
            diagscore=score;
            diagpath=path;
            if(diagpath>0){
                diagscore+=getchar(ch);
            }
        }
        //now best among all
        int bestscore,bestpath;
        if(upscore==leftscore && leftscore==diagscore){// all are equal
            bestscore=upscore;
            bestpath=uppath+leftpath+diagpath;
        }
        else if(upscore==leftscore){// 2nd condn
            bestscore=leftscore;
            bestpath=leftpath+uppath;
            if(diagscore>bestscore || (diagscore==bestscore && diagpath>bestpath)){
                bestscore=diagscore;
                bestpath=diagpath;
            }
        }
        else{
            bestscore=upscore;
            bestpath=uppath;
            if(leftscore>bestscore ||(leftscore==bestscore && leftpath>bestpath)){
                bestscore=leftscore;
                bestpath=leftpath;
            }
            else if(diagscore>bestscore ||(diagscore==bestscore && diagpath>bestpath)){
                bestscore=diagscore;
                bestpath=diagpath;
            }
        }
        return dp[i][j]={bestscore,bestpath%mod};
   }
           
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n=board.size();
         dp.assign(n,vector<pair<int,int>>(n,{-1,-1}));
        pair<int,int>ans=solve(n-1,n-1,board);
       
        return {ans.first,ans.second};

    }
};