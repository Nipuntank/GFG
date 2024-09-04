//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node,vector<int>adj[],vector<int>&vis,stack<int>&st)
	{
	    vis[node]=1;
	    for(auto it:adj[node])
	    {
	        if(!vis[it])
	        {
	            dfs(it,adj,vis,st);
	        }
	    }
	    st.push(node);
	}
	void dfs2(int node,vector<int>adj[],vector<int>&vis)
	{
	    vis[node]=1;
	    for(auto it:adj[node])
	    {
	        if(!vis[it])
	        {
	            dfs2(it,adj,vis);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int>graph[V];
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                graph[i].push_back(it);
            }
        }
        stack<int>st;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,graph,vis,st);
            }
        }
        vector<int>revGraph[V];
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                revGraph[it].push_back(i);
            }
        }
        fill(vis.begin(),vis.end(),0);
        int ans=0;
        while(!st.empty())
        {
            int top=st.top();
            st.pop();
            if(!vis[top])
            {
                dfs2(top,revGraph,vis);
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends