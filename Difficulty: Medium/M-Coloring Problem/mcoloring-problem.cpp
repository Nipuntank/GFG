//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(int i,int j,bool graph[101][101],vector<int>&color,int m,int n)
    {
        for(int k=0;k<n;k++)
        {
            if(graph[i][k] && color[k]==j)
            {
                return false;
            }
        }
        return true;
    }
    bool isGraphColoring(int i,bool graph[101][101],vector<int>&color,int m,int n)
    {
        if(i==n)
        {
            return true;
        }
        for(int j=1;j<=m;j++)
        {
            if(isSafe(i,j,graph,color,m,n))
            {
                color[i]=j;
                if(isGraphColoring(i+1,graph,color,m,n))
                {
                    return true;
                }
                color[i]=-1;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int>color(n,-1);
        if(isGraphColoring(0,graph,color,m,n))
        {
            return true;
        }
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends