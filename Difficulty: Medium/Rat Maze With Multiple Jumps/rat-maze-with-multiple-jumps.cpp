//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool isSafe(vector<vector<int>>&matrix,int x,int y,int m,int n)
    {
        if(x>=0 && x<m && y>=0 && y<n && matrix[x][y]!=0)
        {
            return true;
        }
        return false;
    }
    int dfs(vector<vector<int>>&matrix,vector<vector<int>>&vis,int x,int y,int m,int n)
    {
        if(x==m-1 && y==n-1)
        {
            vis[x][y]=1;
            return true;
        }
        if(isSafe(matrix,x,y,m,n) && !vis[x][y])
        {
            vis[x][y]=1;
            for(int i=1;i<=matrix[x][y] &&i<n;i++)
            {
                if(dfs(matrix,vis,x,y+i,m,n))
                {
                    return true;
                }
                if(dfs(matrix,vis,x+i,y,m,n))
                {
                    return true;
                }
            }
            vis[x][y]=0;
            return false;
        }
        return false;
    }
	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	   // Code here
	   int m=matrix.size();
	   int n=matrix[0].size();
	   vector<vector<int>>vis(m,vector<int>(n,0));
	   if(!dfs(matrix,vis,0,0,m,n))
	   {
	       return{{-1}};
	   }
	   return vis;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends