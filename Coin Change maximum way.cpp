 long long int count(int coins[], int n, int amount) {

        long long int dp[n+1][amount+1]; 
        
        // base case initialization
        for(int j=0;j<=amount;j++) // when amount =0 then for all n = there will be one sol'n
            dp[0][j] = 0;
        for(int i=0;i<=n;i++)
            dp[i][0] = 1;
       
        
        // recursive case updation to top down
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j){
                    long long int take = dp[i][j-coins[i-1]];
                    long long int not_take = dp[i-1][j];
                    dp[i][j] = take+not_take;
                }
                else 
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][amount];
    }
