public:
    int dp[1001][1001];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int helper(string x, string y, int n, int m){
        
        //base case
        if(n==0||m==0) // if length of string is zero so no common substring possible
            return 0;
        
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        helper(x,y,n-1,m); // we are checking by reducing one string 
        helper(x,y,n,m-1); // we are checking by reducing another string 
             
        
        //recursive case
        
        if(x[n-1]==y[m-1]){
           return dp[n][m] = 1+helper(x,y,n-1,m-1); // if both ar equal then we are checking for another substring      
            }
        else{
           return dp[n][m] = 0; // at this point both string are not matched so substring will be zero
        }
           
    }
    int longestCommonSubstr (string x, string y, int n, int m)
    {
        helper(x,y,n,m);
        int k = 0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                k = max(k,dp[i][j]);
            }
        }
        return k;
    }
