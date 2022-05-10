  
//kadane's algorithm

int maxProduct(vector<int>& nums) {
        int ans = nums[0];
	    int maxm = INT_MIN;
        int prod =1;
	    // int  =nums[0];
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            prod*=nums[i];
            maxm = max(maxm,prod);
            if(nums[i]==0)
                prod=1;
        }
        prod =1;
	   for(int i=n-1;i>=0;i--)
        {
            prod*=nums[i];
            maxm = max(maxm,prod);
            if(nums[i]==0)
                prod=1;
        }
	    return maxm;
    }
