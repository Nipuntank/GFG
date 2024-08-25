//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    int dx[8]={1,2,2,1,-1,-2,-2,-1};
    int dy[8]={2,1,-1,-2,-2,-1,1,2};
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    vector<vector<int>>vis(N,vector<int>(N,0));
	    queue<pair<int,pair<int,int>>>q;
	    int xi=KnightPos[0]-1;
	    int yi=KnightPos[1]-1;
	    
	    q.push({0,{xi,yi}});
	    vis[xi][yi]=1;
	    while(!q.empty())
	    {
	        int cnt=q.front().first;
	        int x=q.front().second.first;
	        int y=q.front().second.second;
	        q.pop();
	        if(x==TargetPos[0]-1 && y==TargetPos[1]-1)
	        {
	            return cnt;
	        }
	        for(int i=0;i<8;i++)
	        {
	            int nx=x+dx[i];
	            int ny=y+dy[i];
	            if(nx>=0 && nx<N && ny>=0 && ny<N && !vis[nx][ny])
	            {
	                q.push({cnt+1,{nx,ny}});
	                vis[nx][ny]=1;
	            }
	        }
	    }
	    return -1;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends