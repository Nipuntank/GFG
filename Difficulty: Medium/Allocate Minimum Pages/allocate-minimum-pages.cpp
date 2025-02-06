//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int helper(int mid,vector<int>&arr,int k)
    {
        int d=1;
        int sum=0;
        for(auto it:arr)
        {
            if(sum+it<=mid)
            {
                sum+=it;
            }
            else{
                d++;
                sum=it;
            }
        }
        return d<=k;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(k>n)
            return -1;
        int l=0;
        int r=0;
        for(auto it:arr)
        {
            r+=it;
            l=max(it,l);
        }
        int ans=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(helper(mid,arr,k))
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends