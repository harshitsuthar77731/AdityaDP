int minDeletions(string str, int n) { 
    
    string a = str;
    reverse(str.begin(),str.end());
    string b = str;
    
    int dp[n+1][n+1];
    
    for(int i = 0;i<=n;i++)
        dp[i][0] = 0;
    for(int j = 0;j<=n;j++)
        dp[0][j] = 0;
    
    for(int i=1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(a[i-1]==b[j-1])
                dp[i][j] = 1+dp[i-1][j-1];  // previous max+1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]); // max of previous max
        }
    }
    
    int lps = dp[n][n];
    int ans = n-lps;
    return ans;
} 
