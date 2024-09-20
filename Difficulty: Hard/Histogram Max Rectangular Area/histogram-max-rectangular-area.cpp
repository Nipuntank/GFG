//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(vector<long long> &hist) {
        // Your code here
        stack<int>st;
        int n=hist.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && hist[st.top()]>=hist[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                left[i]=0;
            }
            else{
                left[i]=st.top()+1;
            }
            st.push(i);
        }
        while(!st.empty())
        {
            st.pop();
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && hist[st.top()]>=hist[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                right[i]=n-1;
            }
            else{
                right[i]=st.top()-1;
            }
            st.push(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,hist[i]*(right[i]-left[i]+1));
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends