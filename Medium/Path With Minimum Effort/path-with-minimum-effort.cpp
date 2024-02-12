//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>cost(m,vector<int>(n,1e9));
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>>pq;
        pq.push({{0,0},0});
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        cost[0][0]=0;
        while(!pq.empty())
        {
            int x=pq.top().first.first;
            int y=pq.top().first.second;
            int diff=pq.top().second;
            pq.pop();
            if(x==m-1 && y==n-1)
            {
                return diff;
            }
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n)
                {
                    int ndiff=max(diff,abs(heights[nx][ny]-heights[x][y]));
                    if(ndiff<cost[nx][ny])
                    {
                        cost[nx][ny]=ndiff;
                        pq.push({{nx,ny},ndiff});
                    }
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends