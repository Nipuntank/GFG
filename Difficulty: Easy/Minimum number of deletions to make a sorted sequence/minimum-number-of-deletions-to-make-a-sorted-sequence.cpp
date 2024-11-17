//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minDeletions(int arr[], int n) 
	{ 
	    // Your code goes here
	    if(n<=1)
	    {
	        return 0;
	    }
	    vector<int>v;
	    v.push_back(arr[0]);
	    for(int i=1;i<n;i++)
	    {
	        if(arr[i]>v.back())
	        {
	            v.push_back(arr[i]);
	        }
	        int idx=lower_bound(v.begin(),v.end(),arr[i])-v.begin();
	        v[idx]=arr[i];
	    }
	    return n-v.size();
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

	    

	    Solution ob;
	    cout << ob.minDeletions(arr, n) << "\n";
	     
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends