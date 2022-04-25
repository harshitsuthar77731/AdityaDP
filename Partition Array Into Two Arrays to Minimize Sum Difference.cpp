  int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for(int i=0;i<n;i++)
            k+=nums[i];
        
        bool dp[n+1][k+1];
        
        for(int i =0 ;i<=n;i++)
            dp[i][0] = true;
        for(int j =1 ;j<=k;j++)  
            dp[0][j] = false;
    
        for(int i =1 ;i<=n;i++)
        {
          for(int j =1 ;j<=k;j++)  
          {
              if(nums[i-1]<=j)
                  dp[i][j] = dp[i-1][j]||dp[i-1][j-nums[i-1]];
              else
                  dp[i][j] = dp[i-1][j];
          }
        }
        
        int ans = INT_MAX;
        
        for(int i=0;i<=k;i++)
        {
            if(dp[n][i]==true)
                if(ans>abs(k-2*i))
                    ans = abs(k-2*i);
        }
        return ans;
    }
