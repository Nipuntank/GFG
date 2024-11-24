//{ Driver Code Starts
// C++ program to find union of
// two sorted arrays
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*You are required to complete this method*/
class Solution {
  public:
    int circularTour(vector<int>& a1, vector<int>& a2) {
        // Your code here
        int n = a1.size();
    int start = 0, curr = 0, total = 0;

    for (int i = 0; i < n; i++) {
        curr += a1[i] - a2[i];
        total += a1[i] - a2[i];

        // If current fuel is less than 0, reset the start point to the next pump
        if (curr < 0) {
            start = i + 1;
            curr = 0;  // reset the current fuel
        }
    }

    // If total fuel is non-negative, a solution exists
    return total >= 0 ? start : -1;
    }
    
};


//{ Driver Code Starts.
/* Driver program to test above function */
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {

        vector<int> arr1, arr2;
        string input1;
        getline(cin, input1);
        stringstream ss(input1);
        int number1;
        while (ss >> number1) {
            arr1.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream sss(input2);
        int number2;
        while (sss >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        // Function calling
        // vector<int> v;
        int ans = ob.circularTour(arr1, arr2);

        cout << ans << endl;

        cout << "~" << endl;
        // string tilde;
        // getline(cin, tilde);
    }

    return 0;
}

// } Driver Code Ends