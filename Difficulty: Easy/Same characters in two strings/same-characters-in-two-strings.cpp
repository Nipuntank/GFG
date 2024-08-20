//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int sameChar(string A, string B)
    {
        // code here 
        int cnt=0;
        int n=min(A.size(),B.size());
        for(int i=0;i<n;i++)
        {
            if(A[i]==B[i] || A[i]+32==B[i] || A[i]==B[i]+32)
            {
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
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.sameChar(A,B)<<endl;
    }
    return 0;
}
// } Driver Code Ends