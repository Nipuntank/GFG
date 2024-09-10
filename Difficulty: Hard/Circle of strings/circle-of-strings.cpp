//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<int>adj[],vector<int>&vis,int node)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(adj,vis,it);
            }
        }
    }
    int isCircle(vector<string> &arr) {
        // code here
        vector<int>adj[26];
        vector<int>indegree(26,0);
        vector<int>outdegree(26,0);
        for(auto it:arr)
        {
            string temp=it;
            adj[temp[0]-'a'].push_back(temp[temp.size()-1]-'a');
            indegree[temp[temp.size()-1]-'a']++;
            outdegree[temp[0]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(indegree[i]!=outdegree[i])
            {
                return 0;
            }
        }
        vector<int>vis(26,0);
        dfs(adj,vis,arr[0][0]-'a');
        for(int i=0;i<26;i++)
        {
            if(!vis[i] && indegree[i])
            {
                return 0;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends