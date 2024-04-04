//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    int todigit(char c)
    {
        return (c-'0');
    }
    long long sumSubstrings(string s){
        
        // your code here
        int mod=1e9+7;
        int n=s.length();
        long long sumofdigit[n];
        sumofdigit[0] = todigit(s[0]);
        long long sum=sumofdigit[0];
        for(int i=1;i<n;i++)
        {
            long long num=todigit(s[i]);
            sumofdigit[i]=((i+1)*num + 10*sumofdigit[i-1])%mod;
            sum+=sumofdigit[i]%mod;;
        }
        return sum%mod;
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends