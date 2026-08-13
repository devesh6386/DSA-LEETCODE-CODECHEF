class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
          //int k=flights.size();
          //int m=flights[0].size();
          vector<vector<pair<int,int>>>adj(n);//adjacent nodes 
          for(auto it:flights){//create graph
            adj[it[0]].push_back({it[1],it[2]});

          }
          queue<pair<int,pair<int,int>>>q;
          //{stops,{node,dist}}
          q.push({0,{src,0}});//source 0
          vector<int>dist(n,1e9);//all infinite other than 0
          dist[src]=0;
          while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stop=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stop>k)continue;
            for(auto iter:adj[node]){
                int adjnode=iter.first;
                int edgwt=iter.second;
                if(cost+edgwt<dist[adjnode] && stop<=k){//compare for rest queue apart of steps
                         dist[adjnode]=edgwt+cost;
                         q.push({stop+1,{adjnode,dist[adjnode]}});
                }
            }
          }//dist array initialise
          if(dist[dst]==1e9)return -1;
          return dist[dst];
    }
};



            
