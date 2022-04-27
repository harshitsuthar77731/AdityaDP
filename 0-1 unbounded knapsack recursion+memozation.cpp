class Solution{
public:
    int dp[1001][1001];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    
    int fun(int n, int w, int val[], int wt[])
    {
        if(n<=0||w<=0)
            return 0;
        
        // if already got result at that point then return ans;
        if(dp[n][w]!=-1)
            return dp[n][w];
        
        //recursive case
        
        if(wt[n-1]<=w)
        {
            int take = val[n-1]+fun(n,w-wt[n-1],val,wt); // not passing n-1 means we are taking it again and again until our requirement 
            int not_take = fun(n-1,w,val,wt);
            return dp[n][w] =  max(take,not_take);
        }
        else
            return dp[n][w] = fun(n-1,w,val,wt);         // wt greater than capcity w
    }
    
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        return fun(N,W,val,wt);
    }
};
