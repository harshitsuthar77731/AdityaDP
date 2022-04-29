int longestCommonSubstr (string x, string y, int n, int m)
    {
        int dp[n+1][m+1];

        // initialization
        for(int i=0;i<=n;i++)
            dp[i][0] =0;

        for(int j=0;j<=m;j++)
            dp[0][j] =0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(x[i-1]==y[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
        else if(x[i-1]!=y[j-1])
                    dp[i][j] = 0; 
            }
        }
        int k = 0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                k = max(k,dp[i][j]);
            }
        }
        return k;
    }
