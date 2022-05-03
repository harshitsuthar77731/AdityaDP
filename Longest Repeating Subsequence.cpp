int LongestRepeatingSubsequence(string str){
		    int n = str.size();
		    
		    int dp[n+1][n+1];
		    
		    for(int i=0;i<=n;i++)
		        dp[i][0] = 0;
		    for(int j=0;j<=n;j++)
		        dp[0][j] = 0;
		        
		    for(int i=1;i<=n;i++){
		        for(int j= 1;j<=n;j++){
		            if(str[i-1]==str[j-1]&&i!=j)    // i!=j beacuse we don't want same index character
		                dp[i][j] = 1+dp[i-1][j-1];
		            else
		                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		        }
		    }
		    return dp[n][n];
		}
