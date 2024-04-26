//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        int dir=0;
        int x=0,y=0;
        vector<int>ans;
        vector<pair<int,int>>d={{0,1},{1,0},{0,-1},{-1,0}};
        while(x>=0 && x<n && y>=0 && y<m)
        {
            if(matrix[x][y]==1)
            {
                matrix[x][y]=0;
                dir=(dir+1)%4;
            }
            x+=d[dir].first;
            y+=d[dir].second;
        }
        x-=d[dir].first;
        y-=d[dir].second;
        ans.push_back(x);
        ans.push_back(y);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends