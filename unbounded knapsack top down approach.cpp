
class Solution{
public:
    int dp[1001][1001];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        // BASE CASE
        // if capacity(w) =0 or quantity(N)==0 then profit will be zero too
        for(int i=0;i<=N;i++)
            dp[i][0] = 0;
        for(int j=0;j<=W;j++)
            dp[0][j] = 0;
        
        
        //TOP DOWN APPROACH
        for(int i=1;i<=N;i++){
            for(int j=0;j<=W;j++){
                if(wt[i-1]<=j)
                {
                    int take = val[i-1]+dp[i][j-wt[i-1]] ;
                    int not_take = dp[i-1][j];
                    dp[i][j] =  max(take,not_take);
                }
                else
                    dp[i][j] = dp[i-1][j];  // capacity less than wt
            }
        }
        return dp[N][W];
    }
};
