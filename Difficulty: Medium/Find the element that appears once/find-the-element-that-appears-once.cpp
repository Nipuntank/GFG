//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int search(int n, int arr[]) {
        // code
        int l=0,r=n-1;
        if(r==0)
        {
            return arr[0];
        }
        else if(arr[0]!=arr[1])
        {
            return arr[0];
        }
        else if(arr[r]!=arr[r-1])
        {
            return arr[r];
        }
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1])
            {
                return arr[mid];
            }
            if((mid%2==0 && arr[mid]==arr[mid+1]) || (mid%2==1 && arr[mid]==arr[mid-1]))
            {
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

// Driver program
int main() {
    int t, len;
    cin >> t;
    while (t--) {
        cin >> len;
        int arr[len];
        for (int i = 0; i < len; i++) {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.search(len, arr) << '\n';
    }
    return 0;
}

// } Driver Code Ends