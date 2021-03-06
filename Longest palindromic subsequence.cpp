 int longestPalinSubseq(string s) {
         string a = s;
        reverse(s.begin(),s.end());
        string b = s;
        int n = s.size();
        int m = n;
        
        int dp[n+1][n+1];
        
        for(int i=0;i<=n;i++)
            dp[i][0] = 0;
        for(int j=0;j<=m;j++)
            dp[0][j] = 0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i-1]==b[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];  //dp[n][n];
    }
