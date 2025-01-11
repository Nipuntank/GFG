//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int m=a.size();
        int n=b.size();
        if(m>n)
            return kthElement(b,a,k);
        int left=k;
        int l=max(0,k-n),h=min(k,m);
        while(l<=h)
        {
            int mid1=l+(h-l)/2;
            int mid2=left-mid1;
            int l1=(mid1>0)?a[mid1-1]:INT_MIN;
            int l2=(mid2>0)?b[mid2-1]:INT_MIN;
            int r1=(mid1<m)?a[mid1]:INT_MAX;
            int r2=(mid2<n)?b[mid2]:INT_MAX;
            
            if(l1<=r2 && l2<=r1)
            {
                return max(l1,l2);
            }
            else if(l1>r2)
                h=mid1-1;
            else
                l=mid1+1;
        }
        return 0;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends