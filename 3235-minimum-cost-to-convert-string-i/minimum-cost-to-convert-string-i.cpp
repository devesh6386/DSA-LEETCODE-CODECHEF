class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const long long INF=1e18;
        vector<vector<long long>>distance(26,vector<long long>(26,INF));
        for(int i=0;i<26;i++){
            distance[i][i]=0;
        }
        for(int i=0;i<original.size();i++){
            int u=original[i]-'a';
            int v=changed[i]-'a';
            distance[u][v]=min(distance[u][v],(long long)cost[i]);
        }
        for(int i=0;i<26;i++){//Flody warshall
            for(int k=0;k<26;k++){
                for(int j=0;j<26;j++){
                    if(distance[k][i]==INF || distance[i][j]==INF) continue;//distance 
                    distance[k][j]=min(distance[k][j],distance[k][i]+distance[i][j]);
                }
            }
        }
        long long ans=0;
            for(int i=0;i<source.length();i++){
                int s=source[i]-'a';
                int t=target[i]-'a';
                if(s==t)continue;
                if(distance[s][t]==INF)return -1;;
                ans+=distance[s][t];
            }
        
        return ans;
    }
};