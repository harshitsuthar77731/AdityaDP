int dp[101][101];
    int fun(string s, string t,int n, int m)
    {
        if(n==0)
            return m;
        if(m==0)
            return n;
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        //recursive case;
        if(s[n-1]==t[m-1])
            return dp[n][m] = fun(s, t,n-1, m-1);
        else{
            int deletion = fun(s, t,n-1,m);
            int addition = fun(s,t,n,m-1);
            int replacement = fun(s,t,n-1,m-1);
            return dp[n][m] = 1+min(min(deletion,addition),replacement);
        }
        
    }
    int editDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        memset(dp,-1,sizeof(dp));
        fun(s,t,n,m);
        return dp[n][m];
    }
