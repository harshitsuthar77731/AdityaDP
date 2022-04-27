class Solution{
  public:
    int cutRod(int val[], int n) {
        int dp[1001][1001];
        int length[n];      // we are making an another array of length to simplify understanding
        for(int i=0;i<=n;i++)
        {
            dp[i][0] = 0;
            dp[0][i] = 0;
            length[i] = i+1;
        }
        int cap = n;
        for(int i=1; i<=n;i++){
            for(int j = 1;j<=cap;j++){
                if(length[i-1]<=j)    // technically it's also equal to i>=j
                {
                    int take = val[i-1] + dp[i][j-length[i-1]];       // j representing our weitght array
                    int not_take = dp[i-1][j];
                    dp[i][j] = max(take,not_take);
                 }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][n];
    }
};
