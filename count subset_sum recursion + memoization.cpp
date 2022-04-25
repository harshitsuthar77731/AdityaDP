long long int dp[1001][1001];
	Solution()
	{
	    memset(dp,-1,sizeof(dp));
	}
	long long m = 1e9 + 7;
	long long int helper(int nums[],int n, int target)
	{
	     if (n==0) {
        if (target == 0)
            return 1;
        else
            return 0;
        }

	        
	   if(dp[n][target]!=-1)
	        return dp[n][target];
	        
	   // recursive case
	   
	   if(target>=nums[n-1])
	       dp[n][target] = (helper(nums,n-1,target)%m+helper(nums,n-1,target-nums[n-1])%m)%m;
	   else
	        dp[n][target] = helper(nums,n-1,target)%m;
	   return dp[n][target];
	}
	int perfectSum(int nums[], int n, int target)
	{
        return helper(nums,n,target);
	}
