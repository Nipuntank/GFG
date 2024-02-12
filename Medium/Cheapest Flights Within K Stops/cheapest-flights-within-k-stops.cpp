//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        vector<pair<int,int>>adj[n];
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n,1e9);
        dist[src]=0;
        queue<pair<pair<int,int>,int>>q;
        q.push({{src,0},0});
        while(!q.empty())
        {
            int node=q.front().first.first;
            int cost=q.front().first.second;
            int stop=q.front().second;
            q.pop();
            for(auto it:adj[node])
            {
                int adjNode=it.first;
                int d=it.second;
                if(d+cost<dist[adjNode] && stop<=K)
                {
                    q.push({{adjNode,d+cost},stop+1});
                    dist[adjNode]=d+cost;
                }
            }
        }
        if(dist[dst]==1e9)
        {
            return -1;
        }
        return dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends