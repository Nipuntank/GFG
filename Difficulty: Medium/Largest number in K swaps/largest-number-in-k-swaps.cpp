//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void helper(string &ans,string &str,int k,int n,int i)
    {
        if(k==0)
        {
            return ;
        }
        char maxChar=str[i];
        for(int j=i;j<n;j++)
        {
            if(maxChar<str[j])
            {
                maxChar=str[j];
            }
        }
        if(str[i]!=maxChar)
        {
           k--;
        }
        for(int j=n-1;j>=i;j--)
        {
            if(str[j]==maxChar)
            {
                swap(str[i],str[j]);
                if(ans<str)
                {
                    ans=str;
                    
                }
                helper(ans,str,k,n,i+1);
                swap(str[i],str[j]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans=str;
       int n=str.size();
       helper(ans,str,k,n,0);
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends