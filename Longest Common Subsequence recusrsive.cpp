class Solution {
public:
    int helper(string x, string y,int n,int m)
    {
        // base case ->if either string length became 0 there will be no common element b/w them
        if(n==0||m==0)
            return 0;
        
        // recursive case
        if(x[n-1]==y[m-1])
            return 1+helper(x,y,n-1,m-1); // we got one subsequence so adding 1 as result
        else if(x[n-1]!=y[m-1])
            return max(helper(x,y,n-1,m),helper(x,y,n,m-1)); // if we didn't got equal element one time we will check in reducing index of x and one by y where ever maximum result avilable return that
        return 0;
    }
    int longestCommonSubsequence(string x, string y) {
        return helper(x,y,x.size(),y.size());
    }
};
