//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int m=s.size();
        int n=p.size();
        if(n>m || n==0 || m==0)
        {
            return "-1";
        }
        unordered_map<char,int>mp;
        for(auto it:p)
        {
            mp[it]++;
        }
        int si=-1;
        int mini=1e9;
        int l=0,r=0;
        int count=n;
        while(r<m)
        {
            if(mp[s[r++]]-->0)
            {
                count--;
            }
            while(count==0)
            {
                if(r-l<mini)
                {
                    mini=r-l;
                    si=l;
                }
                if(mp[s[l++]]++==0)
                {
                    count++;
                }
            }
        }
        return (si==-1)?"-1":s.substr(si,mini);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends