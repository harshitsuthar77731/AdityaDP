class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
         if(amount == 0)
            return 0;
        
        int n = coins.size();
        int dp[n+1][amount+1]; 
       
        // base case initialization  int this problem in 2d array we are assigning no. of coins required to get the amount in arlier we were just storing +1 if sum exist or not
        for(int i=0;i<=n;i++)
            dp[i][0] = 0;
        for(int j=1;j<=amount;j++)      // when amount =0 then for all n = there will be one sol'n
            dp[0][j] = INT_MAX-1;
        for(int j=1;j<=amount;j++)   // we have  to initialize 1'st row to predict future answer in this problem
        {
            if(j%coins[0]==0)
                dp[1][j] = j/coins[0];          
            else
                dp[1][j] = INT_MAX-1;
        }
        // recursive case updation to top down
        for(int i=2;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j){
                       // for ex j = 7 and i =2 and coins[2-1]=3 then dp[i][j-coins[i-1]] will be dp[2][7-3] => dp[2][4] => 2 means to get sum 4 we are using 2 coins at that point and to get sum 7(j=7,coins[i-1] = 3) we are using 2+1 means used one more coin '3' right now 
                    int take = 1+dp[i][j-coins[i-1]] ;
                    int not_take = dp[i-1][j];
                    
// we are getting j = 7 min'm by which taking coin or just not taking it(means we are checking it by earlier data for ex by taking coin we need 3 coin for sum 7 and may be at earlier data we are getting same 7 by only 2 coin then we will prefer 2);

                    dp[i][j] = min(take,not_take);     
                }
                else 
                    dp[i][j] = dp[i-1][j];
            }
        }
        if(dp[n][amount]+1==INT_MAX)
            return -1;
        else return dp[n][amount];
    }
};
