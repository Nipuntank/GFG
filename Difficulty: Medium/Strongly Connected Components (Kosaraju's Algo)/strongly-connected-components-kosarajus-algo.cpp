//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	void dfs(int node,vector<int>graph[],vector<int>&vis,stack<int>&st)
	{
	    vis[node]=1;
	    for(auto it:graph[node])
	    {
	        if(!vis[it])
	        {
	            dfs(it,graph,vis,st);
	        }
	    }
	    st.push(node);
	}
	void dfs2(int node,vector<int>graph[],vector<int>&vis)
	{
	    vis[node]=1;
	    for(auto it:graph[node])
	    {
	        if(!vis[it])
	        {
	            dfs2(it,graph,vis);
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
        int cnt=0;
        fill(vis.begin(), vis.end(), 0);
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            if(!vis[node])
            {
                dfs2(node,revGraph,vis);
                cnt++;
            }
        }
        return cnt;
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